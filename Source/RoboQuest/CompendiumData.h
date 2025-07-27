#pragma once
#include "CoreMinimal.h"
#include "CompendiumData.generated.h"

USTRUCT(BlueprintType)
struct FCompendiumData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RowName;
    
    ROBOQUEST_API FCompendiumData();
};

