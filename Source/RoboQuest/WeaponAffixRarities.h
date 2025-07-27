#pragma once
#include "CoreMinimal.h"
#include "WeaponAffixRarity.h"
#include "WeaponAffixRarities.generated.h"

USTRUCT(BlueprintType)
struct FWeaponAffixRarities {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeaponAffixRarity> AffixRarity;
    
    ROBOQUEST_API FWeaponAffixRarities();
};

