#pragma once
#include "CoreMinimal.h"
#include "WeaponAffixLuck.generated.h"

USTRUCT(BlueprintType)
struct FWeaponAffixLuck {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> LuckByAffix;
    
    ROBOQUEST_API FWeaponAffixLuck();
};

