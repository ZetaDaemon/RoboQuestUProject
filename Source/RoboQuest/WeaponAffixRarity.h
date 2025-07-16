#pragma once
#include "CoreMinimal.h"
#include "EWeaponAffixParticle.h"
#include "EWeaponAffixRarity.h"
#include "EWeaponColor.h"
#include "WeaponAffixRarity.generated.h"

USTRUCT(BlueprintType)
struct FWeaponAffixRarity {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EWeaponAffixRarity> AffixRarities;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWeaponColor Color;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWeaponAffixParticle Particle;
    
    ROBOQUEST_API FWeaponAffixRarity();
};

