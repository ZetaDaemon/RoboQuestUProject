#pragma once
#include "CoreMinimal.h"
#include "CompendiumDataCategory.h"
#include "CompendiumDataWithLevel.h"
#include "CompendiumDataCategoryEnemy.generated.h"

USTRUCT(BlueprintType)
struct FCompendiumDataCategoryEnemy : public FCompendiumDataCategory {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCompendiumDataWithLevel> Enemies;
    
    ROBOQUEST_API FCompendiumDataCategoryEnemy();
};

