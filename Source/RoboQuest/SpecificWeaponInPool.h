#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SpecificWeaponInPool.generated.h"

class AAWeapon;

USTRUCT(BlueprintType)
struct FSpecificWeaponInPool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AAWeapon> WeaponClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Count;
    
    ROBOQUEST_API FSpecificWeaponInPool();
};

