#pragma once
#include "CoreMinimal.h"
#include "WeaponAffixRecap.generated.h"

USTRUCT(BlueprintType)
struct FWeaponAffixRecap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> AffixesRowNames;
    
    ROBOQUEST_API FWeaponAffixRecap();
};

