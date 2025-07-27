#pragma once
#include "CoreMinimal.h"
#include "CompendiumData.h"
#include "CompendiumDataCategory.h"
#include "CompendiumDataCategoryCinematic.generated.h"

USTRUCT(BlueprintType)
struct FCompendiumDataCategoryCinematic : public FCompendiumDataCategory {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCompendiumData> Cinematics;
    
    ROBOQUEST_API FCompendiumDataCategoryCinematic();
};

