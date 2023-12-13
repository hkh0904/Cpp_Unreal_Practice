// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHelloUnreal_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_HelloUnreal;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_HelloUnreal()
	{
		if (!Z_Registration_Info_UPackage__Script_HelloUnreal.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/HelloUnreal",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xBA45B0F7,
				0xBE29B1CE,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_HelloUnreal.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_HelloUnreal.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_HelloUnreal(Z_Construct_UPackage__Script_HelloUnreal, TEXT("/Script/HelloUnreal"), Z_Registration_Info_UPackage__Script_HelloUnreal, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xBA45B0F7, 0xBE29B1CE));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
