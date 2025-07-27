#pragma once
#include "CoreMinimal.h"
#include "EGarryReward.h"
#include "GarryReward.generated.h"

USTRUCT(BlueprintType)
struct FGarryReward {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EGarryReward> Rewards;
    
    ROBOQUEST_API FGarryReward();
};

