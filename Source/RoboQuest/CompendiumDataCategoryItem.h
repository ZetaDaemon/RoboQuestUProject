#pragma once
#include "CoreMinimal.h"
#include "CompendiumData.h"
#include "CompendiumDataCategory.h"
#include "CompendiumDataCategoryItem.generated.h"

USTRUCT(BlueprintType)
struct FCompendiumDataCategoryItem : public FCompendiumDataCategory {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCompendiumData> Items;
    
    ROBOQUEST_API FCompendiumDataCategoryItem();
};

