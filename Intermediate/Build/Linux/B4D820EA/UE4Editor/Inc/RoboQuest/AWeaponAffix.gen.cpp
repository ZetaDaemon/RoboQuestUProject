// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RoboQuest/AWeaponAffix.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAWeaponAffix() {}
// Cross Module References
	ROBOQUEST_API UClass* Z_Construct_UClass_UAWeaponAffix_NoRegister();
	ROBOQUEST_API UClass* Z_Construct_UClass_UAWeaponAffix();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_RoboQuest();
// End Cross Module References
	void UAWeaponAffix::StaticRegisterNativesUAWeaponAffix()
	{
	}
	UClass* Z_Construct_UClass_UAWeaponAffix_NoRegister()
	{
		return UAWeaponAffix::StaticClass();
	}
	struct Z_Construct_UClass_UAWeaponAffix_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAWeaponAffix_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_RoboQuest,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAWeaponAffix_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "AWeaponAffix.h" },
		{ "ModuleRelativePath", "AWeaponAffix.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAWeaponAffix_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAWeaponAffix>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAWeaponAffix_Statics::ClassParams = {
		&UAWeaponAffix::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UAWeaponAffix_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UAWeaponAffix_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAWeaponAffix()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAWeaponAffix_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAWeaponAffix, 2563157137);
	template<> ROBOQUEST_API UClass* StaticClass<UAWeaponAffix>()
	{
		return UAWeaponAffix::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAWeaponAffix(Z_Construct_UClass_UAWeaponAffix, &UAWeaponAffix::StaticClass, TEXT("/Script/RoboQuest"), TEXT("UAWeaponAffix"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAWeaponAffix);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
