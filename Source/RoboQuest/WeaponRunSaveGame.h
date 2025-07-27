#pragma once
#include "CoreMinimal.h"
#include "EWeaponAffixType.h"
#include "WeaponAffixRecap.h"
#include "WeaponRunSaveGame.generated.h"

class AAWeapon;

USTRUCT(BlueprintType)
struct FWeaponRunSaveGame {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AAWeapon> SoftClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AffixAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AffixBundleSubIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EWeaponAffixType, FWeaponAffixRecap> Affixes;
    
    ROBOQUEST_API FWeaponRunSaveGame();
};

