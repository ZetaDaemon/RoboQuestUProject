#pragma once
#include "CoreMinimal.h"
#include "CompendiumDataCategory.h"
#include "CompendiumDataWithLevel.h"
#include "CompendiumDataCategoryLevel.generated.h"

USTRUCT(BlueprintType)
struct FCompendiumDataCategoryLevel : public FCompendiumDataCategory {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCompendiumDataWithLevel> Levels;
    
    ROBOQUEST_API FCompendiumDataCategoryLevel();
};

