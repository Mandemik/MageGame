// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class UEMSAsyncSaveGame;
#ifdef EASYMULTISAVE_EMSAsyncSaveGame_generated_h
#error "EMSAsyncSaveGame.generated.h already included, missing '#pragma once' in EMSAsyncSaveGame.h"
#endif
#define EASYMULTISAVE_EMSAsyncSaveGame_generated_h

#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncSaveGame_h_14_DELEGATE \
static inline void FAsyncSaveOutputPin_DelegateWrapper(const FMulticastScriptDelegate& AsyncSaveOutputPin) \
{ \
	AsyncSaveOutputPin.ProcessMulticastDelegate<UObject>(NULL); \
}


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncSaveGame_h_26_SPARSE_DATA
#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncSaveGame_h_26_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAsyncSaveActors);


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncSaveGame_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAsyncSaveActors);


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncSaveGame_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEMSAsyncSaveGame(); \
	friend struct Z_Construct_UClass_UEMSAsyncSaveGame_Statics; \
public: \
	DECLARE_CLASS(UEMSAsyncSaveGame, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/EasyMultiSave"), NO_API) \
	DECLARE_SERIALIZER(UEMSAsyncSaveGame)


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncSaveGame_h_26_INCLASS \
private: \
	static void StaticRegisterNativesUEMSAsyncSaveGame(); \
	friend struct Z_Construct_UClass_UEMSAsyncSaveGame_Statics; \
public: \
	DECLARE_CLASS(UEMSAsyncSaveGame, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/EasyMultiSave"), NO_API) \
	DECLARE_SERIALIZER(UEMSAsyncSaveGame)


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncSaveGame_h_26_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEMSAsyncSaveGame(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEMSAsyncSaveGame) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEMSAsyncSaveGame); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEMSAsyncSaveGame); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UEMSAsyncSaveGame(UEMSAsyncSaveGame&&); \
	NO_API UEMSAsyncSaveGame(const UEMSAsyncSaveGame&); \
public:


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncSaveGame_h_26_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEMSAsyncSaveGame(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UEMSAsyncSaveGame(UEMSAsyncSaveGame&&); \
	NO_API UEMSAsyncSaveGame(const UEMSAsyncSaveGame&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEMSAsyncSaveGame); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEMSAsyncSaveGame); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEMSAsyncSaveGame)


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncSaveGame_h_23_PROLOG
#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncSaveGame_h_26_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncSaveGame_h_26_SPARSE_DATA \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncSaveGame_h_26_RPC_WRAPPERS \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncSaveGame_h_26_INCLASS \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncSaveGame_h_26_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncSaveGame_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncSaveGame_h_26_SPARSE_DATA \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncSaveGame_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncSaveGame_h_26_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncSaveGame_h_26_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class EMSAsyncSaveGame."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EASYMULTISAVE_API UClass* StaticClass<class UEMSAsyncSaveGame>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncSaveGame_h


#define FOREACH_ENUM_ENEXTSTEPTYPE(op) \
	op(ENextStepType::SaveLevel) \
	op(ENextStepType::FinishSave) 

enum class ENextStepType : uint8;
template<> EASYMULTISAVE_API UEnum* StaticEnum<ENextStepType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
