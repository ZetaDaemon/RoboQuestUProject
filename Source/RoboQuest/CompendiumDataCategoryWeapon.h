#pragma once
#include "CoreMinimal.h"
#include "CompendiumDataCategory.h"
#include "CompendiumDataWithLevel.h"
#include "CompendiumDataCategoryWeapon.generated.h"

USTRUCT(BlueprintType)
struct FCompendiumDataCategoryWeapon : public FCompendiumDataCategory {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCompendiumDataWithLevel> Weapons;
    
    ROBOQUEST_API FCompendiumDataCategoryWeapon();
};

