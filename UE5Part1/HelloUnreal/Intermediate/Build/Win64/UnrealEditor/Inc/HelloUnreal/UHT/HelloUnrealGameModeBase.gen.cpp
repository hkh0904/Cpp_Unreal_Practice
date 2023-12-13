// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HelloUnreal/HelloUnrealGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHelloUnrealGameModeBase() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	HELLOUNREAL_API UClass* Z_Construct_UClass_AHelloUnrealGameModeBase();
	HELLOUNREAL_API UClass* Z_Construct_UClass_AHelloUnrealGameModeBase_NoRegister();
	UPackage* Z_Construct_UPackage__Script_HelloUnreal();
// End Cross Module References
	void AHelloUnrealGameModeBase::StaticRegisterNativesAHelloUnrealGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AHelloUnrealGameModeBase);
	UClass* Z_Construct_UClass_AHelloUnrealGameModeBase_NoRegister()
	{
		return AHelloUnrealGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AHelloUnrealGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHelloUnrealGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_HelloUnreal,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHelloUnrealGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "HelloUnrealGameModeBase.h" },
		{ "ModuleRelativePath", "HelloUnrealGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHelloUnrealGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHelloUnrealGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AHelloUnrealGameModeBase_Statics::ClassParams = {
		&AHelloUnrealGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AHelloUnrealGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AHelloUnrealGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHelloUnrealGameModeBase()
	{
		if (!Z_Registration_Info_UClass_AHelloUnrealGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AHelloUnrealGameModeBase.OuterSingleton, Z_Construct_UClass_AHelloUnrealGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AHelloUnrealGameModeBase.OuterSingleton;
	}
	template<> HELLOUNREAL_API UClass* StaticClass<AHelloUnrealGameModeBase>()
	{
		return AHelloUnrealGameModeBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHelloUnrealGameModeBase);
	AHelloUnrealGameModeBase::~AHelloUnrealGameModeBase() {}
	struct Z_CompiledInDeferFile_FID_HelloUnreal_Source_HelloUnreal_HelloUnrealGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HelloUnreal_Source_HelloUnreal_HelloUnrealGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AHelloUnrealGameModeBase, AHelloUnrealGameModeBase::StaticClass, TEXT("AHelloUnrealGameModeBase"), &Z_Registration_Info_UClass_AHelloUnrealGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AHelloUnrealGameModeBase), 3034231416U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HelloUnreal_Source_HelloUnreal_HelloUnrealGameModeBase_h_3628432267(TEXT("/Script/HelloUnreal"),
		Z_CompiledInDeferFile_FID_HelloUnreal_Source_HelloUnreal_HelloUnrealGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HelloUnreal_Source_HelloUnreal_HelloUnrealGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
