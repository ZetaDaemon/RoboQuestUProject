#pragma once
#include "CoreMinimal.h"
#include "CompendiumData.h"
#include "CompendiumDataCategory.h"
#include "CompendiumDataCategoryGadget.generated.h"

USTRUCT(BlueprintType)
struct FCompendiumDataCategoryGadget : public FCompendiumDataCategory {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCompendiumData> Gadgets;
    
    ROBOQUEST_API FCompendiumDataCategoryGadget();
};

