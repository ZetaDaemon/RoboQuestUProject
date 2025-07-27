#pragma once
#include "CoreMinimal.h"
#include "EWeaponAffixRarity.h"
#include "EWeaponAffixType.h"
#include "WeaponAffixDisplay.generated.h"

USTRUCT(BlueprintType)
struct FWeaponAffixDisplay {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWeaponAffixType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWeaponAffixRarity Rarity;
    
    ROBOQUEST_API FWeaponAffixDisplay();
};

