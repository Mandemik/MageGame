// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
enum class EAsyncCheckType : uint8;
class UEMSAsyncWait;
#ifdef EASYMULTISAVE_EMSAsyncWait_generated_h
#error "EMSAsyncWait.generated.h already included, missing '#pragma once' in EMSAsyncWait.h"
#endif
#define EASYMULTISAVE_EMSAsyncWait_generated_h

#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncWait_h_13_DELEGATE \
static inline void FAsyncWaitOutputPin_DelegateWrapper(const FMulticastScriptDelegate& AsyncWaitOutputPin) \
{ \
	AsyncWaitOutputPin.ProcessMulticastDelegate<UObject>(NULL); \
}


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncWait_h_18_SPARSE_DATA
#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncWait_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execAsyncWaitForOperation);


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncWait_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAsyncWaitForOperation);


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncWait_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUEMSAsyncWait(); \
	friend struct Z_Construct_UClass_UEMSAsyncWait_Statics; \
public: \
	DECLARE_CLASS(UEMSAsyncWait, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/EasyMultiSave"), NO_API) \
	DECLARE_SERIALIZER(UEMSAsyncWait)


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncWait_h_18_INCLASS \
private: \
	static void StaticRegisterNativesUEMSAsyncWait(); \
	friend struct Z_Construct_UClass_UEMSAsyncWait_Statics; \
public: \
	DECLARE_CLASS(UEMSAsyncWait, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/EasyMultiSave"), NO_API) \
	DECLARE_SERIALIZER(UEMSAsyncWait)


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncWait_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEMSAsyncWait(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEMSAsyncWait) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEMSAsyncWait); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEMSAsyncWait); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UEMSAsyncWait(UEMSAsyncWait&&); \
	NO_API UEMSAsyncWait(const UEMSAsyncWait&); \
public:


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncWait_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UEMSAsyncWait(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UEMSAsyncWait(UEMSAsyncWait&&); \
	NO_API UEMSAsyncWait(const UEMSAsyncWait&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UEMSAsyncWait); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UEMSAsyncWait); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UEMSAsyncWait)


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncWait_h_15_PROLOG
#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncWait_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncWait_h_18_SPARSE_DATA \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncWait_h_18_RPC_WRAPPERS \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncWait_h_18_INCLASS \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncWait_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncWait_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncWait_h_18_SPARSE_DATA \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncWait_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncWait_h_18_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncWait_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> EASYMULTISAVE_API UClass* StaticClass<class UEMSAsyncWait>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_EasyMultiSave_Source_EasyMultiSave_Public_EMSAsyncWait_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
