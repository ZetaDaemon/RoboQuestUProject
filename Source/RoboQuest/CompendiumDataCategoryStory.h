#pragma once
#include "CoreMinimal.h"
#include "CompendiumData.h"
#include "CompendiumDataCategory.h"
#include "CompendiumDataCategoryStory.generated.h"

USTRUCT(BlueprintType)
struct FCompendiumDataCategoryStory : public FCompendiumDataCategory {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCompendiumData> Stories;
    
    ROBOQUEST_API FCompendiumDataCategoryStory();
};

