//Easy Multi Save - Copyright (C) 2023 by Michael Hegemann.  

#include "EMSFunctionLibrary.h"


/**
Save Game Users
**/

void UEMSFunctionLibrary::SetCurrentSaveUserName(UObject* WorldContextObject, const FString& UserName)
{
	if (UEMSObject* EMS = UEMSObject::Get(WorldContextObject))
	{
		EMS->SetCurrentSaveUserName(UserName);
	}
}

void UEMSFunctionLibrary::DeleteSaveUser(UObject* WorldContextObject, const FString& UserName)
{
	if (UEMSObject* EMS = UEMSObject::Get(WorldContextObject))
	{
		EMS->DeleteAllSaveDataForUser(UserName);
	}
}

TArray<FString> UEMSFunctionLibrary::GetAllSaveUsers(UObject* WorldContextObject)
{
	if (UEMSObject* EMS = UEMSObject::Get(WorldContextObject))
	{
		return EMS->GetAllSaveUsers();
	}

	return TArray<FString>();
}

/**
Save Slots
**/

void UEMSFunctionLibrary::SetCurrentSaveGameName(UObject* WorldContextObject, const FString & SaveGameName)
{
	if (UEMSObject* EMS = UEMSObject::Get(WorldContextObject))
	{
		EMS->SetCurrentSaveGameName(SaveGameName);
	}
}

TArray<FString> UEMSFunctionLibrary::GetSortedSaveSlots(UObject* WorldContextObject)
{
	if (UEMSObject* EMS = UEMSObject::Get(WorldContextObject))
	{
		return EMS->GetSortedSaveSlots();
	}

	return TArray<FString>();
}

UEMSInfoSaveGame* UEMSFunctionLibrary::GetSlotInfoSaveGame(UObject* WorldContextObject, FString& SaveGameName)
{
	if (UEMSObject* EMS = UEMSObject::Get(WorldContextObject))
	{
		SaveGameName = EMS->GetCurrentSaveGameName();
		return EMS->GetSlotInfoObject();
	}

	return nullptr;
}

UEMSInfoSaveGame* UEMSFunctionLibrary::GetNamedSlotInfo(UObject* WorldContextObject, const FString& SaveGameName)
{
	if (UEMSObject* EMS = UEMSObject::Get(WorldContextObject))
	{
		return EMS->GetSlotInfoObject(SaveGameName);
	}

	return nullptr;
}

bool UEMSFunctionLibrary::DoesSaveSlotExist(UObject* WorldContextObject, const FString& SaveGameName)
{
	if (SaveGameName.IsEmpty())
	{
		return false;
	}

	if (UEMSObject* EMS = UEMSObject::Get(WorldContextObject))
	{
		return EMS->DoesSaveGameExist(SaveGameName);
	}

	return false;
}

/**
File System
**/

void UEMSFunctionLibrary::DeleteAllSaveDataForSlot(UObject* WorldContextObject, const FString& SaveGameName)
{
	if (UEMSObject* EMS = UEMSObject::Get(WorldContextObject))
	{
		EMS->DeleteAllSaveDataForSlot(SaveGameName);
	}
}

void UEMSFunctionLibrary::ClearMultiLevelSave(UObject* WorldContextObject)
{
	if (UEMSObject* EMS = UEMSObject::Get(WorldContextObject))
	{
		EMS->ClearMultiLevelSave();
	}
}

/**
Thumbnail Saving
Simple saving as .png from a 2d scene capture render target source.
**/

UTexture2D* UEMSFunctionLibrary::ImportSaveThumbnail(UObject* WorldContextObject, const FString& SaveGameName)
{
	if (UEMSObject* EMS = UEMSObject::Get(WorldContextObject))
	{
		return EMS->ImportSaveThumbnail(SaveGameName);
	}	

	return nullptr;
}

void UEMSFunctionLibrary::ExportSaveThumbnail(UObject* WorldContextObject, UTextureRenderTarget2D* TextureRenderTarget, const FString& SaveGameName)
{
	if (UEMSObject* EMS = UEMSObject::Get(WorldContextObject))
	{
		return EMS->ExportSaveThumbnail(TextureRenderTarget, SaveGameName);
	}
}

/**
Other Functions
**/

void UEMSFunctionLibrary::SetActorSaveProperties(UObject* WorldContextObject, bool bSkipSave,  bool bPersistent, bool bSkipTransform)
{
	AActor* SaveActor = Cast<AActor>(WorldContextObject);
	if (SaveActor)
	{
		if (bSkipSave)
		{
			SaveActor->Tags.AddUnique(EMS::SkipSaveTag);
		}
		else
		{
			SaveActor->Tags.Remove(EMS::SkipSaveTag);
		}

		if (bPersistent)
		{
			SaveActor->Tags.AddUnique(EMS::PersistentTag);
		}
		else
		{
			SaveActor->Tags.Remove(EMS::PersistentTag);
		}

		if (bSkipTransform)
		{
			SaveActor->Tags.AddUnique(EMS::SkipTransformTag);
		}
		else
		{
			SaveActor->Tags.Remove(EMS::SkipTransformTag);
		}
	}
}

bool UEMSFunctionLibrary::IsSavingOrLoading(UObject* WorldContextObject)
{
	if (UEMSObject* EMS = UEMSObject::Get(WorldContextObject))
	{
		return EMS->IsAsyncSaveOrLoadTaskActive(ESaveGameMode::MODE_All, EAsyncCheckType::CT_Both, false);
	}

	return false;
}

/**
Custom Objects
**/

bool UEMSFunctionLibrary::SaveCustom(UObject* WorldContextObject, UEMSCustomSaveGame* SaveGame)
{
	if (SaveGame)
	{
		if (UEMSObject* EMS = UEMSObject::Get(WorldContextObject))
		{
			return EMS->SaveCustom(SaveGame);
		}
	}

	return false;
}

UEMSCustomSaveGame* UEMSFunctionLibrary::GetCustomSave(UObject* WorldContextObject, TSubclassOf<UEMSCustomSaveGame> SaveGameClass)
{
	if (SaveGameClass->GetDefaultObject())
	{
		if (UEMSObject* EMS = UEMSObject::Get(WorldContextObject))
		{
			return EMS->GetCustomSave(SaveGameClass);
		}
	}

	return nullptr;
}

void UEMSFunctionLibrary::DeleteCustomSave(UObject* WorldContextObject, UEMSCustomSaveGame* SaveGame)
{
	if (UEMSObject* EMS = UEMSObject::Get(WorldContextObject))
	{
		EMS->DeleteCustomSave(SaveGame);
	}
}

