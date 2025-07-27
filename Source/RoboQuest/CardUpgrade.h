#pragma once
#include "CoreMinimal.h"
#include "CardUpgrade.generated.h"

USTRUCT(BlueprintType)
struct FCardUpgrade {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> Upgrades;
    
    ROBOQUEST_API FCardUpgrade();
};

