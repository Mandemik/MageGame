//Easy Multi Save - Copyright (C) 2023 by Michael Hegemann.  

#include "EMSObject.h"
#include "EMSFunctionLibrary.h"
#include "HAL/PlatformFileManager.h"
#include "EMSActorSaveInterface.h"
#include "EMSCompSaveInterface.h"
#include "Misc/FileHelper.h"
#include "Engine/Engine.h"
#include "EngineUtils.h"
#include "UObject/UObjectIterator.h"
#include "Engine/LevelScriptActor.h"
#include "Engine/GameInstance.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"
#include "Serialization/ArchiveSaveCompressedProxy.h"
#include "Serialization/ArchiveLoadCompressedProxy.h"
#include "TimerManager.h"
#include "EMSPluginSettings.h"
#include "Kismet/GameplayStatics.h"
#include "Async/Async.h"
#include "Runtime/Launch/Resources/Version.h"
#include "SaveGameSystem.h"
#include "PlatformFeatures.h"
#include "ImageUtils.h"

#define EMS_ENGINE_MIN_UE51 (ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 1)
#define EMS_ENGINE_BELOW_UE427 (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)

/**
Initalization
**/

UWorld* UEMSObject::GetWorld() const
{
	return GetGameInstance()->GetWorld();
}

void UEMSObject::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UE_LOG(LogEasyMultiSave, Log, TEXT("Easy Multi Save Initialized"));
	UE_LOG(LogEasyMultiSave, Log, TEXT("Current Save Game Slot is: %s"), *GetCurrentSaveGameName());
}

UEMSObject* UEMSObject::Get(UObject* WorldContextObject)
{
	const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (World)
	{
		const UGameInstance* GameInst = World->GetGameInstance();
		if (GameInst)
		{
			UEMSObject* EMSSubSystem = GameInst->GetSubsystem<UEMSObject>();
			if (EMSSubSystem)
			{
				return EMSSubSystem;
			}
		}
	}

	return nullptr;
}

/**
Custom Save Game
Fully separate of the other save functions.
**/

UEMSCustomSaveGame* UEMSObject::GetCustomSave(const TSubclassOf<UEMSCustomSaveGame>& SaveGameClass)
{
	if (!SaveGameClass->GetDefaultObject())
	{
		return nullptr;
	}

	const UEMSCustomSaveGame* CustomClass = Cast<UEMSCustomSaveGame>(SaveGameClass->GetDefaultObject());
	if (!CustomClass)
	{
		return nullptr;
	}

	FString CustomSaveName = CustomClass->SaveGameName;
	if (CustomSaveName.IsEmpty())
	{
		CustomSaveName = CustomClass->GetName();
	}

	const bool bUseSlot = CustomClass->bUseSaveSlot;

	const FString SaveFile = CustomSaveFile(CustomSaveName, bUseSlot);
	const FSoftClassPath SaveClass = CustomClass->GetClass();

	const FString CurrentSave = GetCurrentSaveGameName();
	const FString CachedRefName = bUseSlot ? CustomSaveName + CurrentSave : CustomSaveName;

	UEMSCustomSaveGame* CachedObject = CachedCustomSaves.FindRef(CachedRefName);
	if (CachedObject)
	{
		return GetDesiredSaveObject<UEMSCustomSaveGame>(SaveFile, SaveClass, CachedObject);
	}
	else
	{
		UEMSCustomSaveGame* NewObject = GetDesiredSaveObject<UEMSCustomSaveGame>(SaveFile, SaveClass, CachedObject);
		NewObject->SaveGameName = CustomSaveName;

		CachedCustomSaves.Add(CachedRefName, NewObject);
		
		return NewObject;
	}

	return nullptr;
}

bool UEMSObject::SaveCustom(UEMSCustomSaveGame* SaveGame)
{
	if (!SaveGame)
	{
		return false;
	}

	const bool bUseSlot = SaveGame->bUseSaveSlot;
	const FString CustomSaveName = SaveGame->SaveGameName;

	//Always save the slot
	if (bUseSlot)
	{
		SaveSlotInfoObject();
	}

	if (SaveObject(*CustomSaveFile(CustomSaveName, bUseSlot), SaveGame))
	{
		UE_LOG(LogEasyMultiSave, Log, TEXT("Custom Save Game Saved: %s"), *CustomSaveName);
		return true;
	}

	return false;
}

void UEMSObject::DeleteCustomSave(UEMSCustomSaveGame* SaveGame)
{
	if (!SaveGame)
	{
		return;
	}

	const bool bUseSlot = SaveGame->bUseSaveSlot;
	const FString CustomSaveName = SaveGame->SaveGameName;
	const FString SaveFile = CustomSaveFile(CustomSaveName, bUseSlot);
	
	bool bSuccess = false;

	ISaveGameSystem* SaveSystem = IPlatformFeaturesModule::Get().GetSaveGameSystem();
	if(SaveSystem->DoesSaveGameExist(*SaveFile, PlayerIndex))
	{
		bSuccess = SaveSystem->DeleteGame(false, *SaveFile, PlayerIndex);
	}

	if (bSuccess)
	{
		const FString CurrentSave = GetCurrentSaveGameName();
		const FString CachedRefName = bUseSlot ? CustomSaveName + CurrentSave : CustomSaveName;

		const UEMSCustomSaveGame* CachedObject = CachedCustomSaves.FindRef(CachedRefName);
		if (CachedObject)
		{
			CachedCustomSaves.Remove(CachedRefName);
		}

		UE_LOG(LogEasyMultiSave, Log, TEXT("Custom Save Game Deleted: %s"), *CustomSaveName);
	}
}

/**
Save Slots
**/

FString UEMSObject::GetCurrentSaveGameName() const
{
	const FString DefaultName = UEMSPluginSettings::Get()->DefaultSaveGameName;

	if (CurrentSaveGameName.IsEmpty())
	{
		return DefaultName;
	}

	return CurrentSaveGameName;
}

UEMSInfoSaveGame* UEMSObject::GetSlotInfoObject(FString SaveGameName)
{
	//We need to clear the cached one for Get Named Slot Info
	if (!SaveGameName.IsEmpty())
	{
		CachedSlotInfoSave = nullptr;
	}

	return GetDesiredSaveObject<UEMSInfoSaveGame>(
		SlotInfoSaveFile(SaveGameName),
		UEMSPluginSettings::Get()->SlotInfoSaveGameClass,
		CachedSlotInfoSave);
}

void UEMSObject::SaveSlotInfoObject()
{
	const FString SaveGameName = GetCurrentSaveGameName();

	if (VerifyOrCreateDirectory(SaveGameName))
	{
		UEMSInfoSaveGame* SaveGame = GetSlotInfoObject();
		if (SaveGame)
		{
			//GetSortedSaveSlots() only uses the file data, this uses actual saved data.
			SaveGame->SlotInfo.Name = SaveGameName;
			SaveGame->SlotInfo.TimeStamp = FDateTime::Now();
			SaveGame->SlotInfo.Level = GetLevelName();

			TArray<FString> PlayerNames;
			if (AGameStateBase* GameState = GetWorld()->GetGameState())
			{
				TArray<APlayerState*> Players = GameState->PlayerArray;
				if (!EMS::ArrayEmpty(Players))
				{
					for (APlayerState* PlayerState : Players)
					{
						PlayerNames.Add(PlayerState->GetPlayerName());
					}

					SaveGame->SlotInfo.Players = PlayerNames;
				}
			}

			SaveObject(*SlotInfoSaveFile(), SaveGame);
		}
	}
}

void UEMSObject::SetCurrentSaveGameName(const FString & SaveGameName)
{
	if (CurrentSaveGameName != SaveGameName)
	{
		ClearCachedSlot();

		CurrentSaveGameName = ValidateSaveName(SaveGameName);
		SaveConfig();

		UE_LOG(LogEasyMultiSave, Log, TEXT("New Current Save Game Slot is: %s"), *CurrentSaveGameName);
	}
}

TArray<FString> UEMSObject::GetSortedSaveSlots() const
{
	if (IsConsoleFileSystem())
	{
		return GetSaveSlotsConsole();
	}

	return GetSaveSlotsDesktop();
}

TArray<FString> UEMSObject::GetSaveSlotsDesktop() const
{
	TArray<FString> SaveGameNames;
	IFileManager::Get().FindFiles(SaveGameNames, *FPaths::Combine(BaseSaveDir(), TEXT("*")), false, true);

	TArray<FString> SaveSlotNames;
	TArray<FSaveSlotInfo> SaveSlots;

	for (const FString& SlotName : SaveGameNames)
	{
		FSaveSlotInfo SlotInfo;
		SlotInfo.Name = SlotName;

		//Use Timestamp of actual file only for sorting.
		const FString SlotPath = SlotFilePath(SlotName);
		SlotInfo.TimeStamp = IFileManager::Get().GetTimeStamp(*SlotPath);

		SaveSlots.Add(SlotInfo);
	}

	SaveSlots.Sort([](const FSaveSlotInfo& A, const FSaveSlotInfo& B)
	{
		return A.TimeStamp > B.TimeStamp;
	});

	for (const FSaveSlotInfo& SlotInfo : SaveSlots)
	{
		SaveSlotNames.Add(SlotInfo.Name);
	}
	
	return SaveSlotNames;
}

TArray<FString> UEMSObject::GetAllSaveGames() const
{
	TArray<FString> SaveGameNames;

#if EMS_ENGINE_MIN_UE51
	ISaveGameSystem* SaveSystem = IPlatformFeaturesModule::Get().GetSaveGameSystem();
	SaveSystem->GetSaveGameNames(SaveGameNames, PlayerIndex);
#else
	IFileManager::Get().FindFiles(SaveGameNames, *UEMSObject::ConsoleSaveDir(), TEXT("*.sav"));
#endif

	return SaveGameNames;
}

TArray<FString> UEMSObject::GetSaveSlotsConsole() const
{
	const FString SlotId = EMS::Underscore + EMS::SlotSuffix;

#if EMS_ENGINE_MIN_UE51
	const FString FullSlotSuffix = SlotId;
#else
	const FString FullSlotSuffix = SlotId + EMS::SaveType;
#endif

	//Gather all save files
	const TArray<FString> SaveGameNames = GetAllSaveGames();

	//Filter out slots
	TArray<FString> SlotNames;
	for (const FString& ActualFileName : SaveGameNames)
	{
		const bool bIsActualSlot = ActualFileName.Contains(FullSlotSuffix);
		if (bIsActualSlot)
		{
			//Get actual name without suffix
			const int Index = ActualFileName.Find(FullSlotSuffix, ESearchCase::IgnoreCase, ESearchDir::FromEnd, INDEX_NONE);
			const int Count = FullSlotSuffix.Len();

			FString ReducedFileName = ActualFileName;
			ReducedFileName.RemoveAt(Index, Count);
			SlotNames.Add(ReducedFileName);
		}
	}

	//Fill with proper info
	TArray<FSaveSlotInfo> SaveSlots;
	for (const FString& SlotName : SlotNames)
	{
		FSaveSlotInfo SlotInfo;
		SlotInfo.Name = SlotName;

		const FString SlotPath = SlotFilePath(SlotName);
		SlotInfo.TimeStamp = IFileManager::Get().GetTimeStamp(*SlotPath);

		SaveSlots.Add(SlotInfo);
	}

	SaveSlots.Sort([](const FSaveSlotInfo& A, const FSaveSlotInfo& B)
	{
		return A.TimeStamp > B.TimeStamp;
	});

	//Need another copy to return the sorted list
	TArray<FString> SaveSlotNames;
	for (const FSaveSlotInfo& SlotInfo : SaveSlots)
	{
		SaveSlotNames.Add(SlotInfo.Name);
	}

	return SaveSlotNames;
}

bool UEMSObject::DoesSaveGameExist(const FString& SaveGameName) const
{
	ISaveGameSystem* SaveSystem = IPlatformFeaturesModule::Get().GetSaveGameSystem();
	return SaveSystem->DoesSaveGameExist(*SlotInfoSaveFile(SaveGameName), PlayerIndex);
}

void UEMSObject::DeleteAllSaveDataForSlot(const FString& SaveGameName)
{
	ClearCachedSlot();

	bool bSuccess = false;

	//Console uses files and not folders
	if (IsConsoleFileSystem())
	{
		TArray<FString> AllFiles;

		//Gather all save files
		const TArray<FString> SaveGameNames = GetAllSaveGames();

		for (const FString& FileName : SaveGameNames)
		{
			if (FileName.Contains(SaveGameName))
			{
				AllFiles.Add(FileName);
			}
		}

		//Gather all thumbnail files
		TArray<FString> SaveThumbFiles;
		IFileManager::Get().FindFiles(SaveThumbFiles, *AllThumbnailFiles(), true, false);
		for (const FString& FileName : SaveThumbFiles)
		{
			if (FileName.Contains(SaveGameName))
			{
				AllFiles.Add(FileName);
			}
		}

		for (const FString& FileName : AllFiles)
		{
			const FString SaveFile = BaseSaveDir() + FileName + EMS::SaveType;
			IFileManager::Get().Delete(*SaveFile, true, false, true);
		}

		bSuccess = !EMS::ArrayEmpty(AllFiles);
		if (bSuccess)
		{
			UE_LOG(LogEasyMultiSave, Log, TEXT("Save Game Data removed for: %s"), *SaveGameName);
		}
	}
	else
	{
		const FString SaveFile = FPaths::Combine(UEMSObject::BaseSaveDir(), SaveGameName);

		bSuccess = IFileManager::Get().DeleteDirectory(*SaveFile, true, true);
		if (bSuccess)
		{
			UE_LOG(LogEasyMultiSave, Log, TEXT("Save Game Data removed for: %s"), *SaveGameName);
		}
	}

	//Delete the cached custom save objects
	TMap<FString, UEMSCustomSaveGame*> TempCustomSaves = CachedCustomSaves;
	for (auto It = TempCustomSaves.CreateIterator(); It; ++It)
	{
		if (It)
		{
			if (It->Key.Contains(SaveGameName))
			{
				CachedCustomSaves.Remove(It->Key);
			}
		}
	}

}

/***
Save Users
**/

void UEMSObject::SetCurrentSaveUserName(const FString& UserName)
{
	if (IsConsoleFileSystem())
	{
		UE_LOG(LogEasyMultiSave, Warning, TEXT("Save Users are not supported when using the console file system."));
		return;
	}

	if (CurrentSaveUserName != UserName)
	{
		ClearCachedSlot();
		ClearCachedCustomSaves();

		CurrentSaveUserName = UserName;
		SaveConfig();

		UE_LOG(LogEasyMultiSave, Log, TEXT("New Current Save User Name is: %s"), *UserName);
	}
}

void UEMSObject::DeleteAllSaveDataForUser(const FString& UserName)
{
	ClearCachedSlot();
	ClearCachedCustomSaves();

	const FString UserSaveFile = SaveUserDir() + UserName;
	bool bSuccess = false;

	//Try removing folder	
	bSuccess = IFileManager::Get().DeleteDirectory(*UserSaveFile, true, true);
	if (bSuccess)
	{
		UE_LOG(LogEasyMultiSave, Log, TEXT("Save Game User Data removed for: %s"), *UserName);
	}
}

TArray<FString> UEMSObject::GetAllSaveUsers() const
{
	TArray<FString> SaveUserNames;
	IFileManager::Get().FindFiles(SaveUserNames, *FPaths::Combine(SaveUserDir(), TEXT("*")), false, true);

	return SaveUserNames;
}

/**
File System
**/

bool UEMSObject::VerifyOrCreateDirectory(const FString& NewDir)
{
	//Not required for console
	if (IsConsoleFileSystem())
	{
		return true;
	}

	const FString SaveFile = FPaths::Combine(BaseSaveDir(), NewDir);
	if (IFileManager::Get().DirectoryExists(*SaveFile) )
	{
		return true;
	}

	return IFileManager::Get().MakeDirectory(*SaveFile, true);
}

USaveGame* UEMSObject::CreateSaveObject(const TSubclassOf<USaveGame>& SaveGameClass)
{
	if (*SaveGameClass && (*SaveGameClass != USaveGame::StaticClass()))
	{
		USaveGame* SaveGame = NewObject<USaveGame>(GetTransientPackage(), SaveGameClass);
		return SaveGame;
	}

	return nullptr;
}

bool UEMSObject::SaveObject(const FString& FullSavePath, USaveGame* SaveGameObject)
{
	bool bSuccess = false;

	if (SaveGameObject)
	{
		TArray<uint8> Data;

		FMemoryWriter MemoryWriter(Data, true);
		FObjectAndNameAsStringProxyArchive Ar(MemoryWriter, false);
		SaveGameObject->Serialize(Ar);

		FBufferArchive Archive;
		Archive << Data;

		bSuccess = SaveBinaryArchive(Archive, *FullSavePath);

		Archive.FlushCache();
		Archive.Close();

		MemoryWriter.FlushCache();
		MemoryWriter.Close();
	}

	return bSuccess;
}

USaveGame* UEMSObject::LoadObject(const FString& FullSavePath, TSubclassOf<USaveGame> SaveGameClass)
{
	USaveGame* SaveGameObject = CreateSaveObject(SaveGameClass);
	if (SaveGameObject)
	{
		LoadBinaryArchive(EDataLoadType::DATA_Object, FullSavePath, SaveGameObject);
	}

	return SaveGameObject;
}

/**
Archive Functions
**/

bool UEMSObject::SaveBinaryData(const TArray<uint8>& SavedData, const FString& FullSavePath) const
{
	ISaveGameSystem* SaveSystem = IPlatformFeaturesModule::Get().GetSaveGameSystem();
	return SaveSystem->SaveGame(false, *FullSavePath, PlayerIndex, SavedData);
}

bool UEMSObject::SaveBinaryArchive(FBufferArchive& BinaryData, const FString& FullSavePath)
{
	bool bSuccess = false;
	const bool bNoCompression = IsConsoleFileSystem();

	if (bNoCompression)
	{
		bSuccess = SaveBinaryData(BinaryData, FullSavePath);
	}
	else
	{
		//Compress and save
		TArray<uint8> CompressedData;
		FArchiveSaveCompressedProxy Compressor = FArchiveSaveCompressedProxy(CompressedData, NAME_Zlib);

		if (Compressor.GetError())
		{
			UE_LOG(LogEasyMultiSave, Error, TEXT("Cannot save, compressor error: %s"), *FullSavePath);
			return false;
		}

		Compressor << BinaryData;
		Compressor.Flush();

		bSuccess = SaveBinaryData(CompressedData, FullSavePath);

		Compressor.FlushCache();
		Compressor.Close();
	}

	BinaryData.FlushCache();
	BinaryData.Empty();
	BinaryData.Close();

	return bSuccess;
}

bool UEMSObject::LoadBinaryArchive(const EDataLoadType& LoadType, const FString& FullSavePath, UObject* Object)
{
	ISaveGameSystem* SaveSystem = IPlatformFeaturesModule::Get().GetSaveGameSystem();
	if (!SaveSystem->DoesSaveGameExist(*FullSavePath, PlayerIndex))
	{
		return false;
	}

	TArray<uint8> BinaryData;
	if (!SaveSystem->LoadGame(false, *FullSavePath, PlayerIndex, BinaryData))
	{
		UE_LOG(LogEasyMultiSave, Warning, TEXT("%s could not be loaded"), *FullSavePath);
		return false;
	}

	if (EMS::ArrayEmpty(BinaryData))
	{
		UE_LOG(LogEasyMultiSave, Warning, TEXT("No binary data found for %s"), *FullSavePath);
		return false;
	}

	bool bSuccess = false;
	const bool bNoCompression = IsConsoleFileSystem();

	if (bNoCompression)
	{
		FMemoryReader FromBinary = FMemoryReader(BinaryData, true);
		FromBinary.Seek(0);

		bSuccess = UnpackBinaryArchive(LoadType, FromBinary, Object);

		FromBinary.FlushCache();
		FromBinary.Close();
	}
	else
	{
		FArchiveLoadCompressedProxy Decompressor = FArchiveLoadCompressedProxy(BinaryData, NAME_Zlib);

		if (Decompressor.GetError())
		{
			UE_LOG(LogEasyMultiSave, Error, TEXT("Cannot load, file might not be compressed: %s"), *FullSavePath);
			return false;
		}

		FBufferArchive DecompressedBinary;
		Decompressor << DecompressedBinary;

		FMemoryReader FromBinary = FMemoryReader(DecompressedBinary, true);
		FromBinary.Seek(0);

		//Unpack archive 
		bSuccess = UnpackBinaryArchive(LoadType, FromBinary, Object);

		Decompressor.FlushCache();
		Decompressor.Close();

		DecompressedBinary.Empty();
		DecompressedBinary.Close();

		FromBinary.FlushCache();
		FromBinary.Close();
	}

	return bSuccess;
}

bool UEMSObject::UnpackBinaryArchive(const EDataLoadType& LoadType, FMemoryReader FromBinary, UObject* Object)
{
	if (LoadType == EDataLoadType::DATA_Level)
	{
		bool bLevelLoadSuccess = false;

		//Check for multi level saving.
		if (IsNormalMultiLevelSave())
		{
			FLevelStackArchive LevelStack;
			FromBinary << LevelStack;

			//Copy from disk to memory.
			if (EMS::ArrayEmpty(LevelArchiveList))
			{
				LevelArchiveList = LevelStack.Archives;
			}

			//It will only unpack the archive for the current level, unless using persistent/slow mode. 
			for (const FLevelArchive& StackedArchive : LevelStack.Archives)
			{
				if (StackedArchive.Level == GetLevelName() || IsSlowMultiLevelSave())
				{
					UnpackLevel(StackedArchive);
				}
			}

			SavedGameMode = LevelStack.SavedGameMode;
			SavedGameState = LevelStack.SavedGameState;

			bLevelLoadSuccess = true;
		}
		else
		{
			FLevelArchive LevelArchive;
			FromBinary << LevelArchive;

			//Streaming Multi Level save specific.  
			if (IsStreamMultiLevelSave())
			{
				//Copy from disk to memory.
				MultiLevelStreamData.CopyFrom(LevelArchive);
			}

			if (UnpackLevel(LevelArchive))
			{
				bLevelLoadSuccess = true;
			}
		}

		return bLevelLoadSuccess;
	}
	else if (LoadType == EDataLoadType::DATA_Player)
	{
		//Check for multi level saving.
		if (IsNormalMultiLevelSave())
		{
			FPlayerStackArchive PlayerStack;
			FromBinary << PlayerStack;

			//Copy from disk to memory.
			if (PlayerStackData.IsEmpty())
			{
				PlayerStackData = PlayerStack;
			}
			
			UnpackPlayer(PlayerStack.PlayerArchive);

			//Set transform per level
			for (auto It = PlayerStack.LevelPositions.CreateConstIterator(); It; ++It)
			{
				if (It.Key() == GetLevelName())
				{
					DirectSetPlayerPosition(It.Value());
					return true;		
				}
			}

			//This prevents loading previous position for an unsaved level
			ClearPlayerPosition();

			return true;
		}
		else
		{
			FPlayerArchive PlayerArchive;
			FromBinary << PlayerArchive;

			if (PlayerArchive.Level == GetLevelName() || IsPersistentPlayer())
			{
				UnpackPlayer(PlayerArchive);
				return true;
			}
		}
	}
	else if (LoadType == EDataLoadType::DATA_Object)
	{
		if (Object)
		{
			FBufferArchive ObjectArchive;
			FromBinary << ObjectArchive;

			FMemoryReader MemoryReader(ObjectArchive, true);
			FObjectAndNameAsStringProxyArchive Ar(MemoryReader, true);
			Object->Serialize(Ar);

			ObjectArchive.FlushCache();
			ObjectArchive.Close();

			MemoryReader.FlushCache();
			MemoryReader.Close();

			return true;
		}
	}

	return false;
}

void UEMSObject::DirectSetPlayerPosition(const FPlayerPositionArchive& PosArchive)
{
	//Set location/rotation directly, no need to have the same player data per level.
	SavedPawn.Position = PosArchive.Position;
	SavedPawn.Rotation = PosArchive.Rotation;
	SavedController.Rotation = PosArchive.ControlRotation;
}

void UEMSObject::ClearPlayerPosition()
{
	SavedPawn.Position = FVector::ZeroVector;
	SavedPawn.Rotation = FRotator::ZeroRotator;
	SavedController.Rotation = FRotator::ZeroRotator;
}

bool UEMSObject::UnpackPlayer(const FPlayerArchive& PlayerArchive)
{
	SavedController = PlayerArchive.SavedController;
	SavedPawn = PlayerArchive.SavedPawn;
	SavedPlayerState = PlayerArchive.SavedPlayerState;

	return true;
}

bool UEMSObject::UnpackLevel(const FLevelArchive& LevelArchive)
{
	bool bLevelLoadSuccess = false;

	ClearSavedLevelActors();

	for (const FActorSaveData& TempSavedActor : LevelArchive.SavedActors)
	{
		if (EActorType(TempSavedActor.Type) == EActorType::AT_Persistent)
		{
			SavedActors.Add(TempSavedActor);
			bLevelLoadSuccess = true;
		}
		else
		{
			if (LevelArchive.Level == GetLevelName())
			{
				SavedActors.Add(TempSavedActor);
				bLevelLoadSuccess = true;
			}
		}
	}

	if (LevelArchive.Level == GetLevelName())
	{
		SavedScripts.Append(LevelArchive.SavedScripts);
		bLevelLoadSuccess = true;
	}

	//Basic Multi-Level saving saves mode in the level stack. It is always persistent.
	if (!IsNormalMultiLevelSave())
	{
		if (LevelArchive.Level == GetLevelName() || UEMSPluginSettings::Get()->bPersistentGameMode)
		{
			SavedGameMode = LevelArchive.SavedGameMode;
			SavedGameState = LevelArchive.SavedGameState;
			bLevelLoadSuccess = true;
		}
	}

	return bLevelLoadSuccess;
}

bool UEMSObject::TryLoadPlayerFile()
{
	return LoadBinaryArchive(EDataLoadType::DATA_Player, PlayerSaveFile());
}

bool UEMSObject::TryLoadLevelFile()
{
	return LoadBinaryArchive(EDataLoadType::DATA_Level, ActorSaveFile());
}

/**
Saving Game Actors General Functions
**/

void UEMSObject::PrepareLoadAndSaveActors(const uint32& Flags, const EAsyncCheckType& FunctionType, const bool& bFullReload)
{
	TArray<AActor*> Actors;
	for (FActorIterator It(GetWorld()); It; ++It)
	{
		AActor* Actor = *It;
		if (Actor && IsValidActor(Actor))
		{	
			const EActorType Type = GetActorType(Actor);

			//Load exclusive checks
			if (FunctionType == EAsyncCheckType::CT_Load)
			{
				if (bFullReload)
				{
					bool bIsPlayer = false;
					if (GetPlayerController())
					{
						bIsPlayer = (Actor == GetPlayerController()) || (Actor == GetPlayerPawn()) || (Actor == GetPlayerController()->PlayerState);
					}

					if (Flags & ENUM_TO_FLAG(ELoadTypeFlags::LF_Player))
					{
						if (bIsPlayer)
						{
							Actor->Tags.Remove(EMS::HasLoadedTag);
						}
					}

					if (Flags & ENUM_TO_FLAG(ELoadTypeFlags::LF_Level))
					{
						if (!bIsPlayer)
						{
							Actor->Tags.Remove(EMS::HasLoadedTag);
						}
					}
				}
				else
				{
					//Don't consider loaded placed Actors at all. Runtime Actors require another check, otherwise they would duplicate.
					if (Type == EActorType::AT_Placed && Actor->ActorHasTag(EMS::HasLoadedTag))
					{
						continue;
					}
				}
			}

			//For all, including player, must be done a tick before actual save/load
			if (UEMSPluginSettings::Get()->bAutoSaveStructs)
			{
				SerializeActorStructProperties(Actor);
			}

			if (Type == EActorType::AT_Runtime || Type == EActorType::AT_Placed || Type == EActorType::AT_LevelScript || Type == EActorType::AT_Persistent)
			{
				Actors.Add(Actor);
			}
		}
	}

	ActorList.Empty();
	ActorList = Actors;
}

/**
Saving and Loading Level Actors
**/

void UEMSObject::SaveLevelActors()
{
	TArray<FActorSaveData> InActors;
	TArray<FLevelScriptSaveData> InScripts;
	FGameObjectSaveData InGameMode;
	FGameObjectSaveData InGameState;

	FScopeLock Lock(&ActorCriticalSection);

	for (AActor* Actor : ActorList)
	{
		if (Actor && IsValidForSaving(Actor))
		{
			EActorType Type = GetActorType(Actor);

			//Add Level Actor and Component Data
			if (Type == EActorType::AT_Runtime || Type == EActorType::AT_Placed || Type == EActorType::AT_Persistent)
			{
				FActorSaveData ActorArray;

				if (Type == EActorType::AT_Runtime || Type == EActorType::AT_Persistent)
				{
					ActorArray.Class = BytesFromString(Actor->GetClass()->GetPathName());
				}
			
				ActorArray.Type = uint8(Type);
				
				//No transform for persistent Actors or if skipped
				if (Type != EActorType::AT_Persistent && CanProcessActorTransform(Actor))
				{		
					ActorArray.Transform = Actor->GetActorTransform();
				}
				else
				{
					ActorArray.Transform = FTransform::Identity;	
				}

				ActorArray.Name = BytesFromString(GetFullActorName(Actor));

				SaveActorToBinary(Actor, ActorArray.SaveData);
				InActors.Add(ActorArray);
			}
			//Add Level Script Data
			else if (Type == EActorType::AT_LevelScript)
			{
				FLevelScriptSaveData ScriptArray;
				ScriptArray.Name = LevelScriptSaveName(Actor);

				SaveActorToBinary(Actor, ScriptArray.SaveData);
				InScripts.Add(ScriptArray);
			}
		}
	}
	
	//Game Mode Actor
	AGameModeBase* GameMode = GetWorld()->GetAuthGameMode();
	if (GameMode && IsValidForSaving(GameMode))
	{
		SaveActorToBinary(GameMode, InGameMode);
	}

	//Game State Actor
	AGameStateBase* GameState = GetWorld()->GetGameState();
	if (GameState && IsValidForSaving(GameState))
	{
		SaveActorToBinary(GameState, InGameState);
	}

	FBufferArchive LevelData;

	FLevelArchive LevelArchive;
	{
		LevelArchive.SavedActors = InActors;
		LevelArchive.SavedScripts = InScripts;

		if (!IsNormalMultiLevelSave())
		{
			LevelArchive.SavedGameMode = InGameMode;
			LevelArchive.SavedGameState = InGameState;
		}

		LevelArchive.Level = GetLevelName();
	}

	//Check for multi level saving.
	if (IsNormalMultiLevelSave())
	{
		FLevelStackArchive LevelStack;
		{
			LevelStack.AddTo(LevelArchive);
			LevelStack.SavedGameMode = InGameMode;
			LevelStack.SavedGameState = InGameState;
		}

		//Add data from memory to the Stack Archive.
		for (const FLevelArchive& MemoryArchive : LevelArchiveList)
		{
			if (MemoryArchive != LevelArchive)
			{
				LevelStack.AddTo(MemoryArchive);
			}
		}

		//Update the list in memory with data from current level.
		if (LevelArchiveList.Contains(LevelArchive))
		{
			//If already in the array, we just replace the data.
			for (FLevelArchive& ExistingArchive : LevelArchiveList)
			{
				if (ExistingArchive == LevelArchive)
				{
					ExistingArchive.ReplaceWith(LevelArchive);
				}
			}
		}
		else
		{
			LevelArchiveList.Add(LevelArchive);
		}

		LevelData << LevelStack;
	}
	else if (IsStreamMultiLevelSave())
	{
		//Get the data from memory and either replace or add current Level Actors.
		FMultiLevelStreamingData NewStreamingData = MultiLevelStreamData;
		{
			NewStreamingData.PruneActors();
			NewStreamingData.ReplaceOrAdd(LevelArchive);
		}

		//Get Level and Game Mode etc. from LevelArchive.
		FLevelArchive NewLevelArchive = LevelArchive; 
		{
			NewLevelArchive.SavedActors = NewStreamingData.Actors;
			NewLevelArchive.SavedScripts = NewStreamingData.Scripts;
		}

		//Update data in memory
		MultiLevelStreamData.CopyFrom(NewLevelArchive);

		LevelData << NewLevelArchive;
	}
	else
	{
		LevelData << LevelArchive;
	}

	//Save and log
	if (SaveBinaryArchive(LevelData, ActorSaveFile()))
	{
		UE_LOG(LogEasyMultiSave, Log, TEXT("Level and Game Actors have been saved"));
	}
	else
	{
		UE_LOG(LogEasyMultiSave, Error, TEXT("Failed to save Level Actors"));
	}
}

void UEMSObject::LoadLevelActors(UEMSAsyncLoadGame* LoadTask)
{
	//Level Scripts
	if (!EMS::ArrayEmpty(SavedScripts))
	{
		for (AActor* Actor : ActorList)
		{
			if (Actor && IsValidForLoading(Actor) && GetActorType(Actor) == EActorType::AT_LevelScript)
			{
				for (const FLevelScriptSaveData& ScriptArray : SavedScripts)
				{
					//Compare by level name, since the engine creates multiple script actors.
					const FName ScriptName = LevelScriptSaveName(Actor);

					if (ScriptArray.Name == ScriptName)
					{
						UE_LOG(LogEasyMultiSave, Log, TEXT("%s Blueprint Loaded"), *ScriptName.ToString());

						LoadActorFromBinary(Actor, ScriptArray.SaveData);
					}
				}
			}
		}
	}

	//Game Mode Actor
	if (!EMS::ArrayEmpty(SavedGameMode.Data))
	{
		AGameModeBase* GameMode = GetWorld()->GetAuthGameMode();
		if (GameMode && IsValidForLoading(GameMode))
		{
			LoadActorFromBinary(GameMode, SavedGameMode);

			UE_LOG(LogEasyMultiSave, Log, TEXT("Game Mode loaded"));
		}
	}

	//Game State Actor
	if (!EMS::ArrayEmpty(SavedGameState.Data))
	{
		AGameStateBase* GameState = GetWorld()->GetGameState();
		if (GameState && IsValidForLoading(GameState))
		{
			LoadActorFromBinary(GameState, SavedGameState);

			UE_LOG(LogEasyMultiSave, Log, TEXT("Game State loaded"));
		}
	}

	//Level Actors
	StartLoadLevelActors(LoadTask);
}

void UEMSObject::StartLoadLevelActors(UEMSAsyncLoadGame* LoadTask)
{
	if (!LoadTask)
	{
		return;
	}

	if (EMS::ArrayEmpty(SavedActors))
	{
		LoadTask->FinishLoading();
		return;
	}

	//If authority, we use distance based loading
	if (GetWorld()->GetNetMode() != ENetMode::NM_Client)
	{
		const APlayerController* PC = GetPlayerController();
		if (PC && PC->PlayerCameraManager)
		{
			const FVector CameraLoc = PC->PlayerCameraManager->GetCameraLocation();
			SavedActors.Sort([CameraLoc](const FActorSaveData& A, const FActorSaveData& B)
			{
				const float DistA = FVector::Dist(A.Transform.GetLocation(), CameraLoc);
				const float DistB = FVector::Dist(B.Transform.GetLocation(), CameraLoc);

				return DistA < DistB;
			});
		}
	}

	if (UEMSPluginSettings::Get()->LoadMethod == ELoadMethod::LM_Thread)
	{
		if (FPlatformProcess::SupportsMultithreading())
		{
			AsyncTask(ENamedThreads::AnyNormalThreadNormalTask, [this, LoadTask]()
			{
				LoadAllLevelActors(LoadTask);
			});
		}
		else
		{
			LoadTask->StartDeferredLoad();
		}
	}
	else if (UEMSPluginSettings::Get()->LoadMethod == ELoadMethod::LM_Deferred)
	{
		LoadTask->StartDeferredLoad();
	}
	else
	{
		LoadAllLevelActors(LoadTask);
	}
	
}

void UEMSObject::LoadAllLevelActors(UEMSAsyncLoadGame* LoadTask)
{
	bool bSuccess = false;

	for (const FActorSaveData& ActorArray : SavedActors)
	{
		bSuccess = SpawnOrUpdateLevelActor(ActorArray);
	}

	if (bSuccess)
	{
		LogFinishLoadingLevel();
	}

	if (!IsInGameThread())
	{
		//This fixes a potential crash
		const TWeakObjectPtr<UEMSAsyncLoadGame> LoadTaskRef = MakeWeakObjectPtr(LoadTask);
		if (LoadTaskRef.IsValid())
		{
			AsyncTask(ENamedThreads::GameThread, [LoadTaskRef]()
			{
				UEMSAsyncLoadGame* NewLoadTask = LoadTaskRef.Get();
				if (IsValid(NewLoadTask))
				{
					NewLoadTask->FinishLoading();
				}
			});
		}
	}
	else
	{
		LoadTask->FinishLoading();
	}
	
}

bool UEMSObject::SpawnOrUpdateLevelActor(const FActorSaveData& ActorArray)
{
	const EActorType Type = EActorType(ActorArray.Type);
	const bool bRightType = Type == EActorType::AT_Placed || Type == EActorType::AT_Runtime || Type == EActorType::AT_Persistent;

	if (!bRightType)
	{
		return false;
	}

	const EUpdateActorResult UpdateResult = UpdateLevelActor(ActorArray);
	if (UpdateResult == EUpdateActorResult::RES_ShouldSpawnNewActor)
	{
		SpawnLevelActor(ActorArray);
	}

	return UpdateResult != EUpdateActorResult::RES_Skip;
}

EUpdateActorResult UEMSObject::UpdateLevelActor(const FActorSaveData& ActorArray)
{
	FScopeLock Lock(&ActorCriticalSection);

	for (AActor* Actor : ActorList)
	{
		if (Actor && IsValidActor(Actor))
		{
			//Update existing actors
			if (ActorArray.Name == BytesFromString(GetFullActorName(Actor)))
			{
				//Skips respawn
				if (Actor->ActorHasTag(EMS::HasLoadedTag))
				{
					return EUpdateActorResult::RES_Skip;
				}

				if (!IsInGameThread())
				{
					AsyncTask(ENamedThreads::GameThread, [this, Actor, ActorArray]()
					{
						ProcessLevelActor(Actor, ActorArray);
						return EUpdateActorResult::RES_Success;
					});
				}
				else
				{
					ProcessLevelActor(Actor, ActorArray);
				}

				return EUpdateActorResult::RES_Success;
			}
		}
	}

	return EUpdateActorResult::RES_ShouldSpawnNewActor;
}

bool UEMSObject::CheckForExistingActor(const FActorSaveData& ActorArray)
{
	if (!UEMSPluginSettings::Get()->bAdvancedSpawnCheck)
	{
		return false;
	}

	const UWorld* ThisWorld = GetWorld();
	if (ThisWorld && ThisWorld->PersistentLevel)
	{
		const FName LoadedActorName(*StringFromBytes(ActorArray.Name));
		AActor* NewLevelActor = Cast<AActor>(StaticFindObjectFast(nullptr, GetWorld()->PersistentLevel, LoadedActorName));
		if (NewLevelActor)
		{
			if (!NewLevelActor->ActorHasTag(EMS::HasLoadedTag))
			{
				ProcessLevelActor(NewLevelActor, ActorArray);
				return true;
			}
		}
		else
		{
			LogFailSpawnLevelActor(ActorArray);
		}
	}

	return false;
}

void UEMSObject::SpawnLevelActor(const FActorSaveData & ActorArray)
{
	const FString Class = StringFromBytes(ActorArray.Class);
	if (Class.IsEmpty())
	{
		return;
	}

#if EMS_ENGINE_MIN_UE51
	UClass* SpawnClass = FindObject<UClass>(nullptr, *Class);
#else
	UClass* SpawnClass = FindObject<UClass>(ANY_PACKAGE, *Class);
#endif

	if (!SpawnClass)
	{
		SpawnClass = Cast<UClass>(StaticLoadObject(UClass::StaticClass(), nullptr, *Class, nullptr, LOAD_None, nullptr));
	}

	if (!SpawnClass)
	{
		const FString ActorName = StringFromBytes(ActorArray.Name);
		UE_LOG(LogEasyMultiSave, Warning, TEXT("Spawn Class '%s' could not be loaded for Actor: %s"), *Class, *ActorName);
		return;
	}

	if (SpawnClass && SpawnClass->ImplementsInterface(UEMSActorSaveInterface::StaticClass()))
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		SpawnParams.Name = FName(*StringFromBytes(ActorArray.Name));
		SpawnParams.NameMode = FActorSpawnParameters::ESpawnActorNameMode::Requested; 

		if (!IsInGameThread())
		{
			AsyncTask(ENamedThreads::GameThread, [this, ActorArray, SpawnClass, SpawnParams]()
			{
				if (!CheckForExistingActor(ActorArray))
				{
					AActor* NewActor = GetWorld()->SpawnActor(SpawnClass, &ActorArray.Transform, SpawnParams);
					if (NewActor)
					{
						ProcessLevelActor(NewActor, ActorArray);
					}
					else
					{
						LogFailSpawnLevelActor(ActorArray);
					}
				}
			});
		}
		else
		{
			if (!CheckForExistingActor(ActorArray))
			{
				AActor* NewActor = GetWorld()->SpawnActor(SpawnClass, &ActorArray.Transform, SpawnParams);
				if (NewActor)
				{
					ProcessLevelActor(NewActor, ActorArray);
				}
				else
				{
					LogFailSpawnLevelActor(ActorArray);
				}
			}
		}
	}
}

bool UEMSObject::HasValidTransform(const FTransform& CheckTransform) const
{
	return CheckTransform.IsValid() && CheckTransform.GetLocation() != FVector::ZeroVector;
}

void UEMSObject::ProcessLevelActor(AActor* Actor, const FActorSaveData& ActorArray)
{
	//Only process matching type
	if (EActorType(ActorArray.Type) == GetActorType(Actor))
	{
		if (CanProcessActorTransform(Actor) && HasValidTransform(ActorArray.Transform))
		{
			Actor->SetActorTransform(ActorArray.Transform, false, nullptr, ETeleportType::TeleportPhysics);
		}

		LoadActorFromBinary(Actor, ActorArray.SaveData);
	}
}

void UEMSObject::LogFailSpawnLevelActor(const FActorSaveData& ActorArray)
{
	const FString ActorName = StringFromBytes(ActorArray.Name);
	UE_LOG(LogEasyMultiSave, Warning, TEXT("Failed to spawn Level Actor: %s"), *ActorName);
}

void UEMSObject::LogFinishLoadingLevel()
{
	UE_LOG(LogEasyMultiSave, Log, TEXT("Level Actors loaded"));

	ClearSavedLevelActors();
}

/**
Saving and Loading Player
**/

void UEMSObject::SavePlayerActors()
{
	bool bPlayerSaveSuccess = false;

	//Controller
	FControllerSaveData InController;
	APlayerController* Controller = GetPlayerController();
	if (Controller && IsValidForSaving(Controller))
	{
		if (!Controller->ActorHasTag(EMS::SkipTransformTag))
		{
			InController.Rotation = Controller->GetControlRotation();
		}

		SaveActorToBinary(Controller, InController.SaveData);

		bPlayerSaveSuccess = true;
	}

	//Pawn
	FPawnSaveData InPawn;
	APawn* Pawn = GetPlayerPawn();
	if (Pawn && IsValidForSaving(Pawn) && !SaveAsLevelActor(Pawn))
	{
		if (!Pawn->ActorHasTag(EMS::SkipTransformTag))
		{
			InPawn.Position = Pawn->GetActorLocation();
			InPawn.Rotation = Pawn->GetActorRotation();
		}

		SaveActorToBinary(Pawn, InPawn.SaveData);

		bPlayerSaveSuccess = true;
	}

	//Player State
	FGameObjectSaveData InPlayerState;
	APlayerState* PlayerState = GetPlayerController()->PlayerState;
	if (PlayerState && IsValidForSaving(PlayerState))
	{
		SaveActorToBinary(PlayerState, InPlayerState);

		bPlayerSaveSuccess = true;
	}

	FBufferArchive PlayerData;

	FPlayerArchive PlayerArchive;
	{
		PlayerArchive.SavedController = InController;
		PlayerArchive.SavedPawn = InPawn;
		PlayerArchive.SavedPlayerState = InPlayerState;
		PlayerArchive.Level = GetLevelName();
	}

	//Check for multi level saving.
	if (IsNormalMultiLevelSave())
	{
		PlayerStackData.ReplaceOrAdd(PlayerArchive);
		FPlayerStackArchive PlayerStack = PlayerStackData;

		PlayerData << PlayerStack;
	}
	else
	{
		PlayerData << PlayerArchive;
	}

	if (SaveBinaryArchive(PlayerData, PlayerSaveFile()))
	{
		if (bPlayerSaveSuccess)
		{
			UE_LOG(LogEasyMultiSave, Log, TEXT("Player Actors have been saved"));
		}
	}
	else
	{
		UE_LOG(LogEasyMultiSave, Error, TEXT("Failed to save Player"));
	}
}

void UEMSObject::LoadPlayerActors(UEMSAsyncLoadGame* LoadTask)
{
	//Controller
	APlayerController* Controller = GetPlayerController();
	if (Controller && IsValidForLoading(Controller))
	{
		const FControllerSaveData ControllerData = SavedController;

		if (!IsPersistentPlayer() && !ControllerData.Rotation.IsNearlyZero())
		{
			Controller->SetControlRotation(ControllerData.Rotation);
		}

		LoadActorFromBinary(Controller, ControllerData.SaveData);

		UE_LOG(LogEasyMultiSave, Log, TEXT("Player Controller loaded"));
	}

	//Pawn
	APawn* Pawn = GetPlayerPawn();
	if (Pawn && IsValidForLoading(Pawn) && !SaveAsLevelActor(Pawn))
	{
		const FPawnSaveData PawnData = SavedPawn;

		if (!IsPersistentPlayer() && !PawnData.Position.IsNearlyZero())
		{
			Pawn->SetActorLocation(PawnData.Position, false, nullptr, ETeleportType::TeleportPhysics);
			Pawn->SetActorRotation(PawnData.Rotation, ETeleportType::TeleportPhysics);
		}

		LoadActorFromBinary(Pawn, PawnData.SaveData);

		UE_LOG(LogEasyMultiSave, Log, TEXT("Player Pawn loaded"));
	}

	//Player State
	if (!EMS::ArrayEmpty(SavedPlayerState.Data))
	{
		APlayerState* PlayerState = GetPlayerController()->PlayerState;
		if (PlayerState && IsValidForLoading(PlayerState))
		{
			LoadActorFromBinary(PlayerState, SavedPlayerState);

			UE_LOG(LogEasyMultiSave, Log, TEXT("Player State loaded"))
		}
	}
}

/**
Loading and Saving Components
**/

bool UEMSObject::HasComponentSaveInterface(const UActorComponent* Comp) const
{
	return Comp && Comp->IsRegistered() && Comp->GetClass()->ImplementsInterface(UEMSCompSaveInterface::StaticClass());
}

TArray<UActorComponent*> UEMSObject::GetSaveComponents(AActor* Actor) const
{
	TArray<UActorComponent*> SourceComps;

	//Get components from array
	IEMSActorSaveInterface::Execute_ComponentsToSave(Actor, SourceComps);

	//Get Components with interface
	for (UActorComponent* Component : Actor->GetComponents())
	{
		if (HasComponentSaveInterface(Component))
		{
			if (SourceComps.Find(Component) == INDEX_NONE)
			{
				SourceComps.Add(Component);
			}
		}
	}

	return SourceComps;
}

void UEMSObject::SaveActorComponents(AActor* Actor, TArray<FComponentSaveData>& OutComponents)
{
	const TArray<UActorComponent*> SourceComps = GetSaveComponents(Actor);
	if (EMS::ArrayEmpty(SourceComps))
	{
		return;
	}

	for (UActorComponent* Component : SourceComps)
	{
		if (Component && Component->IsRegistered())
		{
			FComponentSaveData ComponentArray;
			ComponentArray.Name = BytesFromString(Component->GetName());

			const USceneComponent* SceneComp = Cast<USceneComponent>(Component);
			if (SceneComp)
			{
				ComponentArray.RelativeTransform = SceneComp->GetRelativeTransform();
			}

			const UChildActorComponent* ChildActorComp = Cast<UChildActorComponent>(Component);
			if (ChildActorComp)
			{
				AActor* ChildActor = ChildActorComp->GetChildActor();
				if (ChildActor)
				{
					if (!HasSaveInterface(ChildActor))
					{
						SerializeToBinary(ChildActor, ComponentArray.Data);
					}
					else
					{
						UE_LOG(LogEasyMultiSave, Warning, TEXT("Child Actor Component has Save Interface, skipping: %s"), *Component->GetName());
					}
				}
			}
			else
			{
				if (HasComponentSaveInterface(Component))
				{
					IEMSCompSaveInterface::Execute_ComponentPreSave(Component);
				}

				SerializeToBinary(Component, ComponentArray.Data);
			}

			OutComponents.Add(ComponentArray);
		}
	}
}

void UEMSObject::LoadActorComponents(AActor* Actor, const TArray<FComponentSaveData>& InComponents)
{
	const TArray<UActorComponent*> SourceComps = GetSaveComponents(Actor);
	if (EMS::ArrayEmpty(SourceComps))
	{
		return;
	}

	for (UActorComponent* Component : SourceComps)
	{
		if (Component && Component->IsRegistered())
		{
			for (const FComponentSaveData& ComponentArray : InComponents)
			{
				if (ComponentArray.Name == BytesFromString(Component->GetName()))
				{
					USceneComponent* SceneComp = Cast<USceneComponent>(Component);
					if (SceneComp)
					{
						if (IsMovable(SceneComp))
						{
							SceneComp->SetRelativeTransform(ComponentArray.RelativeTransform, false, nullptr, ETeleportType::TeleportPhysics);
						}
					}

					UChildActorComponent* ChildActorComp = Cast<UChildActorComponent>(Component);
					if (ChildActorComp)
					{
						AActor* ChildActor = ChildActorComp->GetChildActor();
						if (ChildActor)
						{
							if (!HasSaveInterface(ChildActor))
							{
								SerializeFromBinary(ChildActor, ComponentArray.Data);
							}
						}
					}
					else
					{
						SerializeFromBinary(Component, ComponentArray.Data);

						if (HasComponentSaveInterface(Component))
						{
							IEMSCompSaveInterface::Execute_ComponentLoaded(Component);
						}
					}
				}
			}
		}
	}
}

/**
Serialize Functions
**/

void UEMSObject::SaveActorToBinary(AActor* Actor, FGameObjectSaveData& OutData)
{
	IEMSActorSaveInterface::Execute_ActorPreSave(Actor);

	Actor->Tags.Remove(EMS::HasLoadedTag);

	SerializeToBinary(Actor, OutData.Data);

	if (GetActorType(Actor) != EActorType::AT_LevelScript)
	{
		SaveActorComponents(Actor, OutData.Components); 
	}

	IEMSActorSaveInterface::Execute_ActorSaved(Actor);
}

void UEMSObject::LoadActorFromBinary(AActor* Actor, const FGameObjectSaveData& InData)
{
	Actor->Tags.Add(EMS::HasLoadedTag);

	SerializeFromBinary(Actor, InData.Data);

	if (GetActorType(Actor) != EActorType::AT_LevelScript)
	{
		LoadActorComponents(Actor, InData.Components);
	}

	IEMSActorSaveInterface::Execute_ActorLoaded(Actor); //Post Component Load
}

void UEMSObject::SerializeToBinary(UObject* Object, TArray<uint8>& OutData)
{
	FMemoryWriter MemoryWriter(OutData, true);
	FSaveGameArchive Ar(MemoryWriter);
	Object->Serialize(Ar);

	MemoryWriter.FlushCache();
	MemoryWriter.Close();
}

void UEMSObject::SerializeFromBinary(UObject* Object, const TArray<uint8>& InData)
{
	FMemoryReader MemoryReader(InData, true);
	FSaveGameArchive Ar(MemoryReader);
	Object->Serialize(Ar);

	MemoryReader.FlushCache();
	MemoryReader.Close();
}

/**
Blueprint Struct Property Serialization
**/

void UEMSObject::SerializeActorStructProperties(AActor* Actor)
{
	SerializeStructProperties(Actor);

	//Also for Components
	TArray<UActorComponent*> SourceComps;
	IEMSActorSaveInterface::Execute_ComponentsToSave(Actor, SourceComps);

	if (!EMS::ArrayEmpty(SourceComps))
	{
		for (UActorComponent* Component : SourceComps)
		{
			if (Component)
			{
				SerializeStructProperties(Component);
			}
		}
	}
}

void UEMSObject::SerializeStructProperties(UObject* Object)
{
	//Non-array struct vars.
	for (TFieldIterator<FStructProperty> ObjectStruct(Object->GetClass()); ObjectStruct; ++ObjectStruct)
	{
		if (ObjectStruct && ObjectStruct->GetPropertyFlags() & CPF_SaveGame)
		{
			SerializeScriptStruct(ObjectStruct->Struct);
		}
	}

	//Struct-Arrays are cast as Arrays, not structs, so we work around it.
	for (TFieldIterator<FArrayProperty> ArrayProp(Object->GetClass()); ArrayProp; ++ArrayProp)
	{
		if (ArrayProp && ArrayProp->GetPropertyFlags() & CPF_SaveGame)
		{
			SerializeArrayStruct(*ArrayProp);
		}
	}

	//Map Properties
	for (TFieldIterator<FMapProperty> MapProp(Object->GetClass()); MapProp; ++MapProp)
	{
		if (MapProp && MapProp->GetPropertyFlags() & CPF_SaveGame)
		{
			SerializeMap(*MapProp);
		}
	}
}

void UEMSObject::SerializeMap(FMapProperty* MapProp)
{
	FProperty* ValueProp = MapProp->ValueProp;

	if (ValueProp)
	{
		ValueProp->SetPropertyFlags(CPF_SaveGame);

		FStructProperty* ValueStructProp = CastField<FStructProperty>(ValueProp);
		if (ValueStructProp)
		{
			SerializeScriptStruct(ValueStructProp->Struct);
		}
	}
}

void UEMSObject::SerializeArrayStruct(FArrayProperty* ArrayProp)
{
	FProperty* InnerProperty = ArrayProp->Inner;
	if (InnerProperty)
	{
		//Here we finally get to the structproperty, wich hides in the Array->Inner
		FStructProperty* ArrayStructProp = CastField<FStructProperty>(InnerProperty);
		if (ArrayStructProp)
		{
			SerializeScriptStruct(ArrayStructProp->Struct);
		}
	}
}

void UEMSObject::SerializeScriptStruct(UStruct* ScriptStruct)
{
	if (ScriptStruct)
	{
		for (TFieldIterator<FProperty> Prop(ScriptStruct); Prop; ++Prop)
		{
			if (Prop)
			{
				Prop->SetPropertyFlags(CPF_SaveGame);

				//Recursive Array
				FArrayProperty* ArrayProp = CastField<FArrayProperty>(*Prop);
				if (ArrayProp)
				{
					SerializeArrayStruct(ArrayProp);
				}

				//Recursive Struct
				FStructProperty* StructProp = CastField<FStructProperty>(*Prop);
				if (StructProp)
				{
					SerializeScriptStruct(StructProp->Struct);
				}

				//Recursive Map
				FMapProperty* MapProp = CastField<FMapProperty>(*Prop);
				if (MapProp)
				{
					SerializeMap(MapProp);
				}
			}
		}
	}
}

/**
Helper Functions
**/

bool UEMSObject::HasSaveInterface(const AActor* Actor) const
{
	return Actor->GetClass()->ImplementsInterface(UEMSActorSaveInterface::StaticClass());
}

bool UEMSObject::IsValidActor(const AActor* Actor) const
{
	return IsValid(Actor) && HasSaveInterface(Actor);
}

bool UEMSObject::IsValidForSaving(const AActor* Actor) const
{
	return IsValidActor(Actor) && !Actor->ActorHasTag(EMS::SkipSaveTag);
}

bool UEMSObject::IsValidForLoading(const AActor* Actor) const
{
	return IsValidActor(Actor) && !Actor->ActorHasTag(EMS::HasLoadedTag);
}

bool UEMSObject::SaveAsLevelActor(const APawn* Pawn) const
{
	return Pawn->ActorHasTag(EMS::PlayerPawnAsLevelActorTag);
}

EActorType UEMSObject::GetActorType(const AActor* Actor) const
{
	if (IsValid(Actor))
	{
		//A real player controlled pawn is saved in the player file
		const APawn* Pawn = Cast<APawn>(Actor);
		if (IsValid(Pawn) && Pawn->IsPlayerControlled() && !SaveAsLevelActor(Pawn))
		{
			return EActorType::AT_Player;
		}

		if (Cast<APlayerController>(Actor) || Cast<APlayerState>(Actor))
		{
			return EActorType::AT_Player;
		}

		if (Cast<ALevelScriptActor>(Actor))
		{
			return EActorType::AT_LevelScript;
		}

		if (Cast<AGameModeBase>(Actor) || Cast<AGameStateBase>(Actor))
		{
			return EActorType::AT_GameObject;
		}

		if (Actor->ActorHasTag(EMS::PersistentTag))
		{
			return EActorType::AT_Persistent;
		}

		//Set to placed if the actor was already there on level/sub-level load. Just skips saving ClassName and therefore prevents respawn
		if (IsPlacedActor(Actor))
		{
			return EActorType::AT_Placed;
		}
	}

	return EActorType::AT_Runtime;
}

FName UEMSObject::GetLevelName() const
{
	//Get full path without PIE prefixes

	FString LevelName = GetWorld()->GetOuter()->GetName();
	const FString Prefix = GetWorld()->StreamingLevelsPrefix;

	const int Index = LevelName.Find(Prefix);
	const int Count = Prefix.Len();

	LevelName.RemoveAt(Index, Count);

	return FName(*LevelName);
}

bool UEMSObject::IsMovable(const USceneComponent* SceneComp) const
{
	if (SceneComp != nullptr)
	{
		return SceneComp->Mobility == EComponentMobility::Movable;
	}

	return false;
}

bool UEMSObject::CanProcessActorTransform(const AActor* Actor) const
{
	return IsMovable(Actor->GetRootComponent()) && !Actor->ActorHasTag(EMS::SkipTransformTag) && Actor->GetAttachParentActor() == nullptr;
}

APlayerController* UEMSObject::GetPlayerController() const
{
	return UGameplayStatics::GetPlayerController(GetWorld(), PlayerIndex);
}

APawn* UEMSObject::GetPlayerPawn() const
{
	if (const APlayerController* PC = GetPlayerController())
	{
		return PC->GetPawnOrSpectator();
	}

	return nullptr;
}

FTimerManager& UEMSObject::GetTimerManager() const
{
	return GetWorld()->GetTimerManager();
}

template<class T>
bool UEMSObject::CheckLoadIterator(const T& It, const ESaveGameMode& Mode, const bool& bLog, const FString& DebugString) const
{
	if (It && It->bIsActive && (It->Mode == Mode || Mode == ESaveGameMode::MODE_All))
	{
		if (bLog)
		{
			UE_LOG(LogEasyMultiSave, Warning, TEXT("%s is active while trying to save or load."), *DebugString);
		}

		return true;
	}

	return false;
}

bool UEMSObject::IsAsyncSaveOrLoadTaskActive(const ESaveGameMode& Mode, const EAsyncCheckType& CheckType, const bool& bLog) const
{
	//This will prevent the functions from being executed at all during pause
	if (bLog)
	{
		if (GetWorld()->IsPaused())
		{
			UE_LOG(LogEasyMultiSave, Warning, TEXT(" Async save or load called during pause. Operation was canceled."));
			return true;
		}
	}

	if (CheckType == EAsyncCheckType::CT_Both || CheckType == EAsyncCheckType::CT_Load)
	{
		for (TObjectIterator<UEMSAsyncLoadGame> It; It; ++It)
		{
			return CheckLoadIterator(It, Mode, bLog, "Load Game Actors");
		}
	}

	if (CheckType == EAsyncCheckType::CT_Both || CheckType == EAsyncCheckType::CT_Save)
	{
		for (TObjectIterator<UEMSAsyncSaveGame> It; It; ++It)
		{
			return CheckLoadIterator(It, Mode, bLog, "Save Game Actors");
		}
	}

	return false;
}

bool UEMSObject::HasValidGameMode() const
{
	//On clients, we assume the game mode is valid
	if (GetWorld()->GetNetMode() == ENetMode::NM_Client)
	{
		return true;
	}

	const AGameModeBase* GameMode = GetWorld()->GetAuthGameMode();
	return IsValid(GameMode);
}

bool UEMSObject::HasValidPlayer() const
{
	return IsValid(GetPlayerPawn());
}

TArray<uint8> UEMSObject::BytesFromString(const FString& String) const
{
	const uint32 Size = String.Len();

	TArray<uint8> Bytes;
	Bytes.AddUninitialized(Size);
	StringToBytes(String, Bytes.GetData(), Size);

	return Bytes;
}

FString UEMSObject::StringFromBytes(const TArray<uint8>& Bytes) const
{
	return BytesToString(Bytes.GetData(), Bytes.Num());
}

/**
Template Functions
**/

template <class TSaveGame>
TSaveGame* UEMSObject::GetDesiredSaveObject(const FString& FullSavePath, const FSoftClassPath& InClassName, TSaveGame*& SaveGameObject)
{
	if (FullSavePath.IsEmpty())
	{
		return nullptr;
	}

	//If we don't have a cached one, we load it and set the cached one
	if (!SaveGameObject)
	{
		const FSoftClassPath LocalClassName = InClassName;
		TSubclassOf<TSaveGame> Class = LocalClassName.ResolveClass();

		if (!Class)
		{
			if (LocalClassName.TryLoad())
			{
				Class = LocalClassName.ResolveClass();
			}
		}

		if (!Class)
		{
			UE_LOG(LogEasyMultiSave, Error, TEXT("Invalid Save Game Object Class: %s"), *LocalClassName.ToString());
			return nullptr;
		}

		USaveGame* SaveGame = LoadObject(FullSavePath, Class);
		SaveGameObject = Cast<TSaveGame>(SaveGame);
	}

	if (!SaveGameObject)
	{
		UE_LOG(LogEasyMultiSave, Error, TEXT("Invalid Save Game Object: %s"), *FullSavePath);
		return nullptr;
	}

	return SaveGameObject;
}

/**
Thumbnail Saving
Simple saving as .png from a 2d scene capture render target source.
**/

UTexture2D* UEMSObject::ImportSaveThumbnail(const FString& SaveGameName)
{
	const FString SaveThumbnailName = ThumbnailSaveFile(SaveGameName);

	//Suppress warning messages when we dont have a thumb yet.
	if (FPaths::FileExists(SaveThumbnailName))
	{
		return FImageUtils::ImportFileAsTexture2D(SaveThumbnailName);
	}
	
	return nullptr;
}

bool UEMSObject::HasRenderTargetResource(UTextureRenderTarget2D* TextureRenderTarget) const
{

#if EMS_ENGINE_BELOW_UE427
	return TextureRenderTarget->Resource != nullptr;
#else
	return TextureRenderTarget->GetResource() != nullptr;
#endif

}

void UEMSObject::ExportSaveThumbnail(UTextureRenderTarget2D* TextureRenderTarget, const FString& SaveGameName)
{
	const FString SaveThumbnailName = ThumbnailSaveFile(SaveGameName);

	if (!TextureRenderTarget)
	{
		UE_LOG(LogEasyMultiSave, Warning, TEXT("ExportSaveThumbnailRT: TextureRenderTarget must be non-null"));
	}
	else if (!HasRenderTargetResource(TextureRenderTarget))
	{
		UE_LOG(LogEasyMultiSave, Warning, TEXT("ExportSaveThumbnailRT: Render target has been released"));
	}
	else if (SaveGameName.IsEmpty())
	{
		UE_LOG(LogEasyMultiSave, Warning, TEXT("ExportSaveThumbnailRT: FileName must be non-empty"));
	}
	else
	{
		FArchive* Ar = IFileManager::Get().CreateFileWriter(*SaveThumbnailName);

		if (Ar)
		{
			FBufferArchive Buffer;
			const bool bSuccess = FImageUtils::ExportRenderTarget2DAsPNG(TextureRenderTarget, Buffer);

			if (bSuccess)
			{
				Ar->Serialize(const_cast<uint8*>(Buffer.GetData()), Buffer.Num());
			}

			delete Ar;
		}
		else
		{
			UE_LOG(LogEasyMultiSave, Warning, TEXT("ExportSaveThumbnailRT: FileWrite failed to create"));
		}
	}
	
}

