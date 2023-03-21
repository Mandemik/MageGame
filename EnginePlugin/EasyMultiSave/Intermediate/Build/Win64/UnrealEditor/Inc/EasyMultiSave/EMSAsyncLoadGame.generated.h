// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class UEMSAsyncLoadGame;
#ifdef EASYMULTISAVE_EMSAsyncLoadGame_generated_h
#error "EMSAsyncLoadGame.generated.h already included, missing '#pragma once' in EMSAsyncLoadGame.h"
#endif
#define EASYMULTISAVE_EMSAsyncLoadGame_generated_h

#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncLoadGame_h_14_DELEGATE \
static inline void FAsyncLoadOutputPin_DelegateWrapper(const FMulticastScriptDelegate& AsyncLoadOutputPin) \
{ \
	AsyncLoadOutputPin.ProcessMulticastDelegate<UObject>(NULL); \
}


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncLoadGame_h_15_DELEGATE \
static inline void FAsyncLoadFailedPin_DelegateWrapper(const FMulticastScriptDelegate& AsyncLoadFailedPin) \
{ \
	AsyncLoadFailedPin.ProcessMulticastDelegate<UObject>(NULL); \
}


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncLoadGame_h_20_SPARSE_DATA
#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncLoadGame_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAsyncLoadActors);


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncLoadGame_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAsyncLoadActors);


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncLoadGame_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEMSAsyncLoadGame(); \
	friend struct Z_Construct_UClass_UEMSAsyncLoadGame_Statics; \
public: \
	DECLARE_CLASS(UEMSAsyncLoadGame, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/EasyMultiSave"), NO_API) \
	DECLARE_SERIALIZER(UEMSAsyncLoadGame)


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncLoadGame_h_20_INCLASS \
private: \
	static void StaticRegisterNativesUEMSAsyncLoadGame(); \
	friend struct Z_Construct_UClass_UEMSAsyncLoadGame_Statics; \
public: \
	DECLARE_CLASS(UEMSAsyncLoadGame, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/EasyMultiSave"), NO_API) \
	DECLARE_SERIALIZER(UEMSAsyncLoadGame)


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncLoadGame_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEMSAsyncLoadGame(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEMSAsyncLoadGame) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEMSAsyncLoadGame); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEMSAsyncLoadGame); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UEMSAsyncLoadGame(UEMSAsyncLoadGame&&); \
	NO_API UEMSAsyncLoadGame(const UEMSAsyncLoadGame&); \
public:


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncLoadGame_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEMSAsyncLoadGame(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UEMSAsyncLoadGame(UEMSAsyncLoadGame&&); \
	NO_API UEMSAsyncLoadGame(const UEMSAsyncLoadGame&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEMSAsyncLoadGame); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEMSAsyncLoadGame); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEMSAsyncLoadGame)


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncLoadGame_h_17_PROLOG
#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncLoadGame_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncLoadGame_h_20_SPARSE_DATA \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncLoadGame_h_20_RPC_WRAPPERS \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncLoadGame_h_20_INCLASS \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncLoadGame_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncLoadGame_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncLoadGame_h_20_SPARSE_DATA \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncLoadGame_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncLoadGame_h_20_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncLoadGame_h_20_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class EMSAsyncLoadGame."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EASYMULTISAVE_API UClass* StaticClass<class UEMSAsyncLoadGame>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncLoadGame_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
