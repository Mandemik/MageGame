// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EasyMultiSave/Public/EMSObject.h"
#include "Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEMSObject() {}
// Cross Module References
	EASYMULTISAVE_API UClass* Z_Construct_UClass_UEMSObject_NoRegister();
	EASYMULTISAVE_API UClass* Z_Construct_UClass_UEMSObject();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	UPackage* Z_Construct_UPackage__Script_EasyMultiSave();
	EASYMULTISAVE_API UClass* Z_Construct_UClass_UEMSInfoSaveGame_NoRegister();
	EASYMULTISAVE_API UClass* Z_Construct_UClass_UEMSCustomSaveGame_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	EASYMULTISAVE_API UScriptStruct* Z_Construct_UScriptStruct_FLevelArchive();
	EASYMULTISAVE_API UScriptStruct* Z_Construct_UScriptStruct_FMultiLevelStreamingData();
	EASYMULTISAVE_API UScriptStruct* Z_Construct_UScriptStruct_FPlayerStackArchive();
	EASYMULTISAVE_API UScriptStruct* Z_Construct_UScriptStruct_FActorSaveData();
	EASYMULTISAVE_API UScriptStruct* Z_Construct_UScriptStruct_FLevelScriptSaveData();
	EASYMULTISAVE_API UScriptStruct* Z_Construct_UScriptStruct_FGameObjectSaveData();
	EASYMULTISAVE_API UScriptStruct* Z_Construct_UScriptStruct_FControllerSaveData();
	EASYMULTISAVE_API UScriptStruct* Z_Construct_UScriptStruct_FPawnSaveData();
// End Cross Module References
	void UEMSObject::StaticRegisterNativesUEMSObject()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEMSObject);
	UClass* Z_Construct_UClass_UEMSObject_NoRegister()
	{
		return UEMSObject::StaticClass();
	}
	struct Z_Construct_UClass_UEMSObject_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentSaveGameName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_CurrentSaveGameName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentSaveUserName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_CurrentSaveUserName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CachedSlotInfoSave_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CachedSlotInfoSave;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CachedCustomSaves_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_CachedCustomSaves_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CachedCustomSaves_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_CachedCustomSaves;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ActorList_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActorList_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ActorList;
		static const UECodeGen_Private::FStructPropertyParams NewProp_LevelArchiveList_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LevelArchiveList_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_LevelArchiveList;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MultiLevelStreamData_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_MultiLevelStreamData;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlayerStackData_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_PlayerStackData;
		static const UECodeGen_Private::FStructPropertyParams NewProp_SavedActors_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SavedActors_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_SavedActors;
		static const UECodeGen_Private::FStructPropertyParams NewProp_SavedScripts_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SavedScripts_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_SavedScripts;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SavedGameMode_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SavedGameMode;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SavedGameState_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SavedGameState;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SavedController_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SavedController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SavedPawn_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SavedPawn;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SavedPlayerState_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SavedPlayerState;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEMSObject_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_EasyMultiSave,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSObject_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EMSObject.h" },
		{ "ModuleRelativePath", "Public/EMSObject.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSObject_Statics::NewProp_CurrentSaveGameName_MetaData[] = {
		{ "ModuleRelativePath", "Public/EMSObject.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEMSObject_Statics::NewProp_CurrentSaveGameName = { "CurrentSaveGameName", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEMSObject, CurrentSaveGameName), METADATA_PARAMS(Z_Construct_UClass_UEMSObject_Statics::NewProp_CurrentSaveGameName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSObject_Statics::NewProp_CurrentSaveGameName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSObject_Statics::NewProp_CurrentSaveUserName_MetaData[] = {
		{ "ModuleRelativePath", "Public/EMSObject.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEMSObject_Statics::NewProp_CurrentSaveUserName = { "CurrentSaveUserName", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEMSObject, CurrentSaveUserName), METADATA_PARAMS(Z_Construct_UClass_UEMSObject_Statics::NewProp_CurrentSaveUserName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSObject_Statics::NewProp_CurrentSaveUserName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSObject_Statics::NewProp_CachedSlotInfoSave_MetaData[] = {
		{ "ModuleRelativePath", "Public/EMSObject.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEMSObject_Statics::NewProp_CachedSlotInfoSave = { "CachedSlotInfoSave", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEMSObject, CachedSlotInfoSave), Z_Construct_UClass_UEMSInfoSaveGame_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UEMSObject_Statics::NewProp_CachedSlotInfoSave_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSObject_Statics::NewProp_CachedSlotInfoSave_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEMSObject_Statics::NewProp_CachedCustomSaves_ValueProp = { "CachedCustomSaves", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UClass_UEMSCustomSaveGame_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEMSObject_Statics::NewProp_CachedCustomSaves_Key_KeyProp = { "CachedCustomSaves_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSObject_Statics::NewProp_CachedCustomSaves_MetaData[] = {
		{ "ModuleRelativePath", "Public/EMSObject.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UEMSObject_Statics::NewProp_CachedCustomSaves = { "CachedCustomSaves", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEMSObject, CachedCustomSaves), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UEMSObject_Statics::NewProp_CachedCustomSaves_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSObject_Statics::NewProp_CachedCustomSaves_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEMSObject_Statics::NewProp_ActorList_Inner = { "ActorList", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSObject_Statics::NewProp_ActorList_MetaData[] = {
		{ "ModuleRelativePath", "Public/EMSObject.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UEMSObject_Statics::NewProp_ActorList = { "ActorList", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEMSObject, ActorList), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UEMSObject_Statics::NewProp_ActorList_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSObject_Statics::NewProp_ActorList_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEMSObject_Statics::NewProp_LevelArchiveList_Inner = { "LevelArchiveList", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FLevelArchive, METADATA_PARAMS(nullptr, 0) }; // 1469099123
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSObject_Statics::NewProp_LevelArchiveList_MetaData[] = {
		{ "ModuleRelativePath", "Public/EMSObject.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UEMSObject_Statics::NewProp_LevelArchiveList = { "LevelArchiveList", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEMSObject, LevelArchiveList), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UEMSObject_Statics::NewProp_LevelArchiveList_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSObject_Statics::NewProp_LevelArchiveList_MetaData)) }; // 1469099123
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSObject_Statics::NewProp_MultiLevelStreamData_MetaData[] = {
		{ "ModuleRelativePath", "Public/EMSObject.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEMSObject_Statics::NewProp_MultiLevelStreamData = { "MultiLevelStreamData", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEMSObject, MultiLevelStreamData), Z_Construct_UScriptStruct_FMultiLevelStreamingData, METADATA_PARAMS(Z_Construct_UClass_UEMSObject_Statics::NewProp_MultiLevelStreamData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSObject_Statics::NewProp_MultiLevelStreamData_MetaData)) }; // 3024221988
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSObject_Statics::NewProp_PlayerStackData_MetaData[] = {
		{ "ModuleRelativePath", "Public/EMSObject.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEMSObject_Statics::NewProp_PlayerStackData = { "PlayerStackData", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEMSObject, PlayerStackData), Z_Construct_UScriptStruct_FPlayerStackArchive, METADATA_PARAMS(Z_Construct_UClass_UEMSObject_Statics::NewProp_PlayerStackData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSObject_Statics::NewProp_PlayerStackData_MetaData)) }; // 4026008531
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedActors_Inner = { "SavedActors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FActorSaveData, METADATA_PARAMS(nullptr, 0) }; // 1761664848
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedActors_MetaData[] = {
		{ "ModuleRelativePath", "Public/EMSObject.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedActors = { "SavedActors", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEMSObject, SavedActors), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedActors_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedActors_MetaData)) }; // 1761664848
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedScripts_Inner = { "SavedScripts", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FLevelScriptSaveData, METADATA_PARAMS(nullptr, 0) }; // 3566394910
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedScripts_MetaData[] = {
		{ "ModuleRelativePath", "Public/EMSObject.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedScripts = { "SavedScripts", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEMSObject, SavedScripts), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedScripts_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedScripts_MetaData)) }; // 3566394910
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedGameMode_MetaData[] = {
		{ "ModuleRelativePath", "Public/EMSObject.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedGameMode = { "SavedGameMode", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEMSObject, SavedGameMode), Z_Construct_UScriptStruct_FGameObjectSaveData, METADATA_PARAMS(Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedGameMode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedGameMode_MetaData)) }; // 1033339996
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedGameState_MetaData[] = {
		{ "ModuleRelativePath", "Public/EMSObject.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedGameState = { "SavedGameState", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEMSObject, SavedGameState), Z_Construct_UScriptStruct_FGameObjectSaveData, METADATA_PARAMS(Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedGameState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedGameState_MetaData)) }; // 1033339996
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedController_MetaData[] = {
		{ "ModuleRelativePath", "Public/EMSObject.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedController = { "SavedController", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEMSObject, SavedController), Z_Construct_UScriptStruct_FControllerSaveData, METADATA_PARAMS(Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedController_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedController_MetaData)) }; // 2390210929
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedPawn_MetaData[] = {
		{ "ModuleRelativePath", "Public/EMSObject.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedPawn = { "SavedPawn", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEMSObject, SavedPawn), Z_Construct_UScriptStruct_FPawnSaveData, METADATA_PARAMS(Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedPawn_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedPawn_MetaData)) }; // 1177466952
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedPlayerState_MetaData[] = {
		{ "ModuleRelativePath", "Public/EMSObject.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedPlayerState = { "SavedPlayerState", nullptr, (EPropertyFlags)0x0010000000002000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEMSObject, SavedPlayerState), Z_Construct_UScriptStruct_FGameObjectSaveData, METADATA_PARAMS(Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedPlayerState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedPlayerState_MetaData)) }; // 1033339996
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEMSObject_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSObject_Statics::NewProp_CurrentSaveGameName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSObject_Statics::NewProp_CurrentSaveUserName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSObject_Statics::NewProp_CachedSlotInfoSave,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSObject_Statics::NewProp_CachedCustomSaves_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSObject_Statics::NewProp_CachedCustomSaves_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSObject_Statics::NewProp_CachedCustomSaves,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSObject_Statics::NewProp_ActorList_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSObject_Statics::NewProp_ActorList,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSObject_Statics::NewProp_LevelArchiveList_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSObject_Statics::NewProp_LevelArchiveList,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSObject_Statics::NewProp_MultiLevelStreamData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSObject_Statics::NewProp_PlayerStackData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedActors_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedActors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedScripts_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedScripts,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedGameMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedGameState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedPawn,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSObject_Statics::NewProp_SavedPlayerState,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEMSObject_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEMSObject>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UEMSObject_Statics::ClassParams = {
		&UEMSObject::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UEMSObject_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UEMSObject_Statics::PropPointers),
		0,
		0x401000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UEMSObject_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSObject_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UEMSObject()
	{
		if (!Z_Registration_Info_UClass_UEMSObject.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEMSObject.OuterSingleton, Z_Construct_UClass_UEMSObject_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UEMSObject.OuterSingleton;
	}
	template<> EASYMULTISAVE_API UClass* StaticClass<UEMSObject>()
	{
		return UEMSObject::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEMSObject);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSObject_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSObject_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UEMSObject, UEMSObject::StaticClass, TEXT("UEMSObject"), &Z_Registration_Info_UClass_UEMSObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEMSObject), 2192311747U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSObject_h_2421294839(TEXT("/Script/EasyMultiSave"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSObject_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSObject_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
