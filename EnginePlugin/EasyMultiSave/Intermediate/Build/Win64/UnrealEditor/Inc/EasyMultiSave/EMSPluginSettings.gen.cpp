// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EasyMultiSave/Public/EMSPluginSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEMSPluginSettings() {}
// Cross Module References
	EASYMULTISAVE_API UClass* Z_Construct_UClass_UEMSPluginSettings_NoRegister();
	EASYMULTISAVE_API UClass* Z_Construct_UClass_UEMSPluginSettings();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_EasyMultiSave();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftClassPath();
	EASYMULTISAVE_API UEnum* Z_Construct_UEnum_EasyMultiSave_EFileSaveMethod();
	EASYMULTISAVE_API UEnum* Z_Construct_UEnum_EasyMultiSave_ELoadMethod();
	EASYMULTISAVE_API UEnum* Z_Construct_UEnum_EasyMultiSave_EMultiLevelSaveMethod();
// End Cross Module References
	void UEMSPluginSettings::StaticRegisterNativesUEMSPluginSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEMSPluginSettings);
	UClass* Z_Construct_UClass_UEMSPluginSettings_NoRegister()
	{
		return UEMSPluginSettings::StaticClass();
	}
	struct Z_Construct_UClass_UEMSPluginSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultSaveGameName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_DefaultSaveGameName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SlotInfoSaveGameClass_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SlotInfoSaveGameClass;
		static const UECodeGen_Private::FBytePropertyParams NewProp_FileSaveMethod_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FileSaveMethod_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_FileSaveMethod;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAdvancedSpawnCheck_MetaData[];
#endif
		static void NewProp_bAdvancedSpawnCheck_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAdvancedSpawnCheck;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSimpleActorNames_MetaData[];
#endif
		static void NewProp_bSimpleActorNames_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSimpleActorNames;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAutoSaveStructs_MetaData[];
#endif
		static void NewProp_bAutoSaveStructs_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoSaveStructs;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bMultiThreadSaving_MetaData[];
#endif
		static void NewProp_bMultiThreadSaving_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bMultiThreadSaving;
		static const UECodeGen_Private::FBytePropertyParams NewProp_LoadMethod_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LoadMethod_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_LoadMethod;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeferredLoadStackSize_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_DeferredLoadStackSize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AsyncWaitDelay_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AsyncWaitDelay;
		static const UECodeGen_Private::FBytePropertyParams NewProp_MultiLevelSaving_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MultiLevelSaving_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_MultiLevelSaving;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bPersistentPlayer_MetaData[];
#endif
		static void NewProp_bPersistentPlayer_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPersistentPlayer;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bPersistentGameMode_MetaData[];
#endif
		static void NewProp_bPersistentGameMode_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPersistentGameMode;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UEMSPluginSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_EasyMultiSave,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSPluginSettings_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EMSPluginSettings.h" },
		{ "ModuleRelativePath", "Public/EMSPluginSettings.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_DefaultSaveGameName_MetaData[] = {
		{ "Category", "General Settings" },
		{ "Comment", "/**The default save game slot name, that is used if no name is set with 'Set Current Save Slot Name'.*/" },
		{ "DisplayName", "Default Slot Name" },
		{ "ModuleRelativePath", "Public/EMSPluginSettings.h" },
		{ "ToolTip", "The default save game slot name, that is used if no name is set with 'Set Current Save Slot Name'." },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_DefaultSaveGameName = { "DefaultSaveGameName", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEMSPluginSettings, DefaultSaveGameName), METADATA_PARAMS(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_DefaultSaveGameName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_DefaultSaveGameName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_SlotInfoSaveGameClass_MetaData[] = {
		{ "Category", "General Settings" },
		{ "Comment", "/**The Blueprint class that you want to use for the slot info, usually does not need a custom class.*/" },
		{ "DisplayName", "Slot Info Class" },
		{ "MetaClass", "/Script/EasyMultiSave.EMSInfoSaveGame" },
		{ "ModuleRelativePath", "Public/EMSPluginSettings.h" },
		{ "ToolTip", "The Blueprint class that you want to use for the slot info, usually does not need a custom class." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_SlotInfoSaveGameClass = { "SlotInfoSaveGameClass", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEMSPluginSettings, SlotInfoSaveGameClass), Z_Construct_UScriptStruct_FSoftClassPath, METADATA_PARAMS(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_SlotInfoSaveGameClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_SlotInfoSaveGameClass_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_FileSaveMethod_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_FileSaveMethod_MetaData[] = {
		{ "Category", "General Settings" },
		{ "Comment", "/**The file system that is used depending on the platform.*/" },
		{ "DisplayName", "File System" },
		{ "ModuleRelativePath", "Public/EMSPluginSettings.h" },
		{ "ToolTip", "The file system that is used depending on the platform." },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_FileSaveMethod = { "FileSaveMethod", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEMSPluginSettings, FileSaveMethod), Z_Construct_UEnum_EasyMultiSave_EFileSaveMethod, METADATA_PARAMS(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_FileSaveMethod_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_FileSaveMethod_MetaData)) }; // 3517802261
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bAdvancedSpawnCheck_MetaData[] = {
		{ "Category", "Actors" },
		{ "Comment", "/**If enabled, the system runs a more expensive check for spawned Actors. This is useful if you spawn Actors at the beginning of a level and experience issues.*/" },
		{ "DisplayName", "Advanced Spawn Check" },
		{ "ModuleRelativePath", "Public/EMSPluginSettings.h" },
		{ "ToolTip", "If enabled, the system runs a more expensive check for spawned Actors. This is useful if you spawn Actors at the beginning of a level and experience issues." },
	};
#endif
	void Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bAdvancedSpawnCheck_SetBit(void* Obj)
	{
		((UEMSPluginSettings*)Obj)->bAdvancedSpawnCheck = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bAdvancedSpawnCheck = { "bAdvancedSpawnCheck", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UEMSPluginSettings), &Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bAdvancedSpawnCheck_SetBit, METADATA_PARAMS(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bAdvancedSpawnCheck_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bAdvancedSpawnCheck_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bSimpleActorNames_MetaData[] = {
		{ "Category", "Actors" },
		{ "Comment", "/**\n\x09""Actors are saved without their associated Level. This can speed up the loading process, but is not suitable for Level Streaming.\n\x09*/" },
		{ "DisplayName", "Optimized Actor Names" },
		{ "ModuleRelativePath", "Public/EMSPluginSettings.h" },
		{ "ToolTip", "Actors are saved without their associated Level. This can speed up the loading process, but is not suitable for Level Streaming." },
	};
#endif
	void Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bSimpleActorNames_SetBit(void* Obj)
	{
		((UEMSPluginSettings*)Obj)->bSimpleActorNames = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bSimpleActorNames = { "bSimpleActorNames", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UEMSPluginSettings), &Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bSimpleActorNames_SetBit, METADATA_PARAMS(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bSimpleActorNames_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bSimpleActorNames_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bAutoSaveStructs_MetaData[] = {
		{ "Category", "Actors" },
		{ "Comment", "/**\n\x09Struct and Map variables with 'Save Game' checked are saved automatically for all Actors. Otherwise only the desired variables inside a struct are saved.\n\x09*/" },
		{ "DisplayName", "Auto Save Structs" },
		{ "ModuleRelativePath", "Public/EMSPluginSettings.h" },
		{ "ToolTip", "Struct and Map variables with 'Save Game' checked are saved automatically for all Actors. Otherwise only the desired variables inside a struct are saved." },
	};
#endif
	void Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bAutoSaveStructs_SetBit(void* Obj)
	{
		((UEMSPluginSettings*)Obj)->bAutoSaveStructs = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bAutoSaveStructs = { "bAutoSaveStructs", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UEMSPluginSettings), &Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bAutoSaveStructs_SetBit, METADATA_PARAMS(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bAutoSaveStructs_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bAutoSaveStructs_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bMultiThreadSaving_MetaData[] = {
		{ "Category", "Save and Load" },
		{ "Comment", "/**If enabled, saving player and level actors is outsourced to a background thread.*/" },
		{ "DisplayName", "Multi-Thread Saving" },
		{ "ModuleRelativePath", "Public/EMSPluginSettings.h" },
		{ "ToolTip", "If enabled, saving player and level actors is outsourced to a background thread." },
	};
#endif
	void Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bMultiThreadSaving_SetBit(void* Obj)
	{
		((UEMSPluginSettings*)Obj)->bMultiThreadSaving = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bMultiThreadSaving = { "bMultiThreadSaving", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UEMSPluginSettings), &Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bMultiThreadSaving_SetBit, METADATA_PARAMS(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bMultiThreadSaving_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bMultiThreadSaving_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_LoadMethod_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_LoadMethod_MetaData[] = {
		{ "Category", "Save and Load" },
		{ "Comment", "/**The method that is used to load level-actors.*/" },
		{ "DisplayName", "Level Load Method" },
		{ "ModuleRelativePath", "Public/EMSPluginSettings.h" },
		{ "ToolTip", "The method that is used to load level-actors." },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_LoadMethod = { "LoadMethod", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEMSPluginSettings, LoadMethod), Z_Construct_UEnum_EasyMultiSave_ELoadMethod, METADATA_PARAMS(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_LoadMethod_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_LoadMethod_MetaData)) }; // 2802920606
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_DeferredLoadStackSize_MetaData[] = {
		{ "Category", "Save and Load" },
		{ "Comment", "/**Estimated Number of Actors to load in one batch.*/" },
		{ "DisplayName", "Deferred Load Size" },
		{ "EditCondition", "LoadMethod == ELoadMethod::LM_Deferred" },
		{ "ModuleRelativePath", "Public/EMSPluginSettings.h" },
		{ "ToolTip", "Estimated Number of Actors to load in one batch." },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_DeferredLoadStackSize = { "DeferredLoadStackSize", nullptr, (EPropertyFlags)0x0010040000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEMSPluginSettings, DeferredLoadStackSize), METADATA_PARAMS(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_DeferredLoadStackSize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_DeferredLoadStackSize_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_AsyncWaitDelay_MetaData[] = {
		{ "Category", "Save and Load" },
		{ "Comment", "/**How long the Async load/wait nodes are allowed to remain fixed in a state.*/" },
		{ "DisplayName", "Async Wait Delay" },
		{ "ModuleRelativePath", "Public/EMSPluginSettings.h" },
		{ "ToolTip", "How long the Async load/wait nodes are allowed to remain fixed in a state." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_AsyncWaitDelay = { "AsyncWaitDelay", nullptr, (EPropertyFlags)0x0010040000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEMSPluginSettings, AsyncWaitDelay), METADATA_PARAMS(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_AsyncWaitDelay_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_AsyncWaitDelay_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_MultiLevelSaving_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_MultiLevelSaving_MetaData[] = {
		{ "Category", "Save and Load" },
		{ "Comment", "/**\n\x09* How Level Actor Save Data is kept between levels.\n\x09* Prevents old save data from being overwritten. \n\x09* \n\x09* Game Mode is persistent and not saved per level. \n\x09* Player is also persistent and will automatically save it's position.\n\x09* \n\x09* The level name from the slot is always the last saved level.\n\x09*/" },
		{ "DisplayName", "Multi-Level Saving Mode" },
		{ "ModuleRelativePath", "Public/EMSPluginSettings.h" },
		{ "ToolTip", "How Level Actor Save Data is kept between levels.\nPrevents old save data from being overwritten.\n\nGame Mode is persistent and not saved per level.\nPlayer is also persistent and will automatically save it's position.\n\nThe level name from the slot is always the last saved level." },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_MultiLevelSaving = { "MultiLevelSaving", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UEMSPluginSettings, MultiLevelSaving), Z_Construct_UEnum_EasyMultiSave_EMultiLevelSaveMethod, METADATA_PARAMS(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_MultiLevelSaving_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_MultiLevelSaving_MetaData)) }; // 2642088245
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bPersistentPlayer_MetaData[] = {
		{ "Category", "Persistence" },
		{ "Comment", "/**The controller, pawn and player state can be loaded independent of the level without transforms.*/" },
		{ "DisplayName", "Persistent Player" },
		{ "EditCondition", "MultiLevelSaving != EMultiLevelSaveMethod::ML_Stream" },
		{ "ModuleRelativePath", "Public/EMSPluginSettings.h" },
		{ "ToolTip", "The controller, pawn and player state can be loaded independent of the level without transforms." },
	};
#endif
	void Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bPersistentPlayer_SetBit(void* Obj)
	{
		((UEMSPluginSettings*)Obj)->bPersistentPlayer = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bPersistentPlayer = { "bPersistentPlayer", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UEMSPluginSettings), &Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bPersistentPlayer_SetBit, METADATA_PARAMS(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bPersistentPlayer_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bPersistentPlayer_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bPersistentGameMode_MetaData[] = {
		{ "Category", "Persistence" },
		{ "Comment", "/**The game mode and game state can be loaded independent of the level.*/" },
		{ "DisplayName", "Persistent Game Mode" },
		{ "EditCondition", "MultiLevelSaving == EMultiLevelSaveMethod::ML_Disabled" },
		{ "ModuleRelativePath", "Public/EMSPluginSettings.h" },
		{ "ToolTip", "The game mode and game state can be loaded independent of the level." },
	};
#endif
	void Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bPersistentGameMode_SetBit(void* Obj)
	{
		((UEMSPluginSettings*)Obj)->bPersistentGameMode = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bPersistentGameMode = { "bPersistentGameMode", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UEMSPluginSettings), &Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bPersistentGameMode_SetBit, METADATA_PARAMS(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bPersistentGameMode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bPersistentGameMode_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEMSPluginSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_DefaultSaveGameName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_SlotInfoSaveGameClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_FileSaveMethod_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_FileSaveMethod,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bAdvancedSpawnCheck,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bSimpleActorNames,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bAutoSaveStructs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bMultiThreadSaving,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_LoadMethod_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_LoadMethod,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_DeferredLoadStackSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_AsyncWaitDelay,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_MultiLevelSaving_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_MultiLevelSaving,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bPersistentPlayer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEMSPluginSettings_Statics::NewProp_bPersistentGameMode,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UEMSPluginSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEMSPluginSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UEMSPluginSettings_Statics::ClassParams = {
		&UEMSPluginSettings::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UEMSPluginSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UEMSPluginSettings_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(Z_Construct_UClass_UEMSPluginSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UEMSPluginSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UEMSPluginSettings()
	{
		if (!Z_Registration_Info_UClass_UEMSPluginSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEMSPluginSettings.OuterSingleton, Z_Construct_UClass_UEMSPluginSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UEMSPluginSettings.OuterSingleton;
	}
	template<> EASYMULTISAVE_API UClass* StaticClass<UEMSPluginSettings>()
	{
		return UEMSPluginSettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UEMSPluginSettings);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSPluginSettings_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSPluginSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UEMSPluginSettings, UEMSPluginSettings::StaticClass, TEXT("UEMSPluginSettings"), &Z_Registration_Info_UClass_UEMSPluginSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEMSPluginSettings), 4233205600U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSPluginSettings_h_3525611977(TEXT("/Script/EasyMultiSave"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSPluginSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSPluginSettings_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
