// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "KIMGYEONGWOONG/KIMGYEONGWOONGGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeKIMGYEONGWOONGGameMode() {}
// Cross Module References
	KIMGYEONGWOONG_API UClass* Z_Construct_UClass_AKIMGYEONGWOONGGameMode_NoRegister();
	KIMGYEONGWOONG_API UClass* Z_Construct_UClass_AKIMGYEONGWOONGGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_KIMGYEONGWOONG();
// End Cross Module References
	void AKIMGYEONGWOONGGameMode::StaticRegisterNativesAKIMGYEONGWOONGGameMode()
	{
	}
	UClass* Z_Construct_UClass_AKIMGYEONGWOONGGameMode_NoRegister()
	{
		return AKIMGYEONGWOONGGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AKIMGYEONGWOONGGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AKIMGYEONGWOONGGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_KIMGYEONGWOONG,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AKIMGYEONGWOONGGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "KIMGYEONGWOONGGameMode.h" },
		{ "ModuleRelativePath", "KIMGYEONGWOONGGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AKIMGYEONGWOONGGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AKIMGYEONGWOONGGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AKIMGYEONGWOONGGameMode_Statics::ClassParams = {
		&AKIMGYEONGWOONGGameMode::StaticClass,
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
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AKIMGYEONGWOONGGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AKIMGYEONGWOONGGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AKIMGYEONGWOONGGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AKIMGYEONGWOONGGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AKIMGYEONGWOONGGameMode, 2336043227);
	template<> KIMGYEONGWOONG_API UClass* StaticClass<AKIMGYEONGWOONGGameMode>()
	{
		return AKIMGYEONGWOONGGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AKIMGYEONGWOONGGameMode(Z_Construct_UClass_AKIMGYEONGWOONGGameMode, &AKIMGYEONGWOONGGameMode::StaticClass, TEXT("/Script/KIMGYEONGWOONG"), TEXT("AKIMGYEONGWOONGGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AKIMGYEONGWOONGGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
