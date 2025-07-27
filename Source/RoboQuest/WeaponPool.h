#pragma once
#include "CoreMinimal.h"
#include "EWeaponCategory.h"
#include "WeaponPool.generated.h"

USTRUCT(BlueprintType)
struct FWeaponPool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EWeaponCategory> Categories;
    
    ROBOQUEST_API FWeaponPool();
};

