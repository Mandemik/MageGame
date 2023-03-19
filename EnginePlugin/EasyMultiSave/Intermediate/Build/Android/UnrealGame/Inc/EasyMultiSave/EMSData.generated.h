// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef EASYMULTISAVE_EMSData_generated_h
#error "EMSData.generated.h already included, missing '#pragma once' in EMSData.h"
#endif
#define EASYMULTISAVE_EMSData_generated_h

#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSData_h_141_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSaveSlotInfo_Statics; \
	EASYMULTISAVE_API static class UScriptStruct* StaticStruct();


template<> EASYMULTISAVE_API UScriptStruct* StaticStruct<struct FSaveSlotInfo>();

#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSData_h_159_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FComponentSaveData_Statics; \
	EASYMULTISAVE_API static class UScriptStruct* StaticStruct();


template<> EASYMULTISAVE_API UScriptStruct* StaticStruct<struct FComponentSaveData>();

#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSData_h_177_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FGameObjectSaveData_Statics; \
	EASYMULTISAVE_API static class UScriptStruct* StaticStruct();


template<> EASYMULTISAVE_API UScriptStruct* StaticStruct<struct FGameObjectSaveData>();

#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSData_h_193_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FActorSaveData_Statics; \
	EASYMULTISAVE_API static class UScriptStruct* StaticStruct();


template<> EASYMULTISAVE_API UScriptStruct* StaticStruct<struct FActorSaveData>();

#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSData_h_220_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FLevelScriptSaveData_Statics; \
	EASYMULTISAVE_API static class UScriptStruct* StaticStruct();


template<> EASYMULTISAVE_API UScriptStruct* StaticStruct<struct FLevelScriptSaveData>();

#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSData_h_241_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FLevelArchive_Statics; \
	EASYMULTISAVE_API static class UScriptStruct* StaticStruct();


template<> EASYMULTISAVE_API UScriptStruct* StaticStruct<struct FLevelArchive>();

#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSData_h_282_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FLevelStackArchive_Statics; \
	EASYMULTISAVE_API static class UScriptStruct* StaticStruct();


template<> EASYMULTISAVE_API UScriptStruct* StaticStruct<struct FLevelStackArchive>();

#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSData_h_306_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMultiLevelStreamingData_Statics; \
	EASYMULTISAVE_API static class UScriptStruct* StaticStruct();


template<> EASYMULTISAVE_API UScriptStruct* StaticStruct<struct FMultiLevelStreamingData>();

#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSData_h_349_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPawnSaveData_Statics; \
	EASYMULTISAVE_API static class UScriptStruct* StaticStruct();


template<> EASYMULTISAVE_API UScriptStruct* StaticStruct<struct FPawnSaveData>();

#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSData_h_367_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FControllerSaveData_Statics; \
	EASYMULTISAVE_API static class UScriptStruct* StaticStruct();


template<> EASYMULTISAVE_API UScriptStruct* StaticStruct<struct FControllerSaveData>();

#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSData_h_383_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPlayerArchive_Statics; \
	EASYMULTISAVE_API static class UScriptStruct* StaticStruct();


template<> EASYMULTISAVE_API UScriptStruct* StaticStruct<struct FPlayerArchive>();

#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSData_h_403_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPlayerPositionArchive_Statics; \
	EASYMULTISAVE_API static class UScriptStruct* StaticStruct();


template<> EASYMULTISAVE_API UScriptStruct* StaticStruct<struct FPlayerPositionArchive>();

#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSData_h_428_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPlayerStackArchive_Statics; \
	EASYMULTISAVE_API static class UScriptStruct* StaticStruct();


template<> EASYMULTISAVE_API UScriptStruct* StaticStruct<struct FPlayerStackArchive>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSData_h


#define FOREACH_ENUM_EUPDATEACTORRESULT(op) \
	op(EUpdateActorResult::RES_Success) \
	op(EUpdateActorResult::RES_Skip) \
	op(EUpdateActorResult::RES_ShouldSpawnNewActor) 

enum class EUpdateActorResult : uint8;
template<> EASYMULTISAVE_API UEnum* StaticEnum<EUpdateActorResult>();

#define FOREACH_ENUM_EDATALOADTYPE(op) \
	op(EDataLoadType::DATA_Level) \
	op(EDataLoadType::DATA_Player) \
	op(EDataLoadType::DATA_Object) 

enum class EDataLoadType : uint8;
template<> EASYMULTISAVE_API UEnum* StaticEnum<EDataLoadType>();

#define FOREACH_ENUM_EACTORTYPE(op) \
	op(EActorType::AT_Runtime) \
	op(EActorType::AT_Placed) \
	op(EActorType::AT_LevelScript) \
	op(EActorType::AT_Player) \
	op(EActorType::AT_GameObject) \
	op(EActorType::AT_Persistent) 

enum class EActorType : uint8;
template<> EASYMULTISAVE_API UEnum* StaticEnum<EActorType>();

#define FOREACH_ENUM_ESAVEGAMEMODE(op) \
	op(ESaveGameMode::MODE_Player) \
	op(ESaveGameMode::MODE_Level) \
	op(ESaveGameMode::MODE_All) 

enum class ESaveGameMode : uint8;
template<> EASYMULTISAVE_API UEnum* StaticEnum<ESaveGameMode>();

#define FOREACH_ENUM_EASYNCCHECKTYPE(op) \
	op(EAsyncCheckType::CT_Both) \
	op(EAsyncCheckType::CT_Save) \
	op(EAsyncCheckType::CT_Load) 

enum class EAsyncCheckType : uint8;
template<> EASYMULTISAVE_API UEnum* StaticEnum<EAsyncCheckType>();

#define FOREACH_ENUM_ELOADMETHOD(op) \
	op(ELoadMethod::LM_Default) \
	op(ELoadMethod::LM_Deferred) \
	op(ELoadMethod::LM_Thread) 

enum class ELoadMethod : uint8;
template<> EASYMULTISAVE_API UEnum* StaticEnum<ELoadMethod>();

#define FOREACH_ENUM_EFILESAVEMETHOD(op) \
	op(EFileSaveMethod::FM_Desktop) \
	op(EFileSaveMethod::FM_Console) 

enum class EFileSaveMethod : uint8;
template<> EASYMULTISAVE_API UEnum* StaticEnum<EFileSaveMethod>();

#define FOREACH_ENUM_ESAVETYPEFLAGS(op) \
	op(ESaveTypeFlags::SF_Player) \
	op(ESaveTypeFlags::SF_Level) 

enum class ESaveTypeFlags : uint8;
template<> EASYMULTISAVE_API UEnum* StaticEnum<ESaveTypeFlags>();

#define FOREACH_ENUM_ELOADTYPEFLAGS(op) \
	op(ELoadTypeFlags::LF_Player) \
	op(ELoadTypeFlags::LF_Level) 

enum class ELoadTypeFlags : uint8;
template<> EASYMULTISAVE_API UEnum* StaticEnum<ELoadTypeFlags>();

#define FOREACH_ENUM_EMULTILEVELSAVEMETHOD(op) \
	op(EMultiLevelSaveMethod::ML_Disabled) \
	op(EMultiLevelSaveMethod::ML_Normal) \
	op(EMultiLevelSaveMethod::ML_Stream) \
	op(EMultiLevelSaveMethod::ML_Slow) 

enum class EMultiLevelSaveMethod : uint8;
template<> EASYMULTISAVE_API UEnum* StaticEnum<EMultiLevelSaveMethod>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
