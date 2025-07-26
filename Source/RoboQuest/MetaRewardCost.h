#pragma once
#include "CoreMinimal.h"
#include "MetaRewardRowHandle.h"
#include "MetaRewardCost.generated.h"

USTRUCT(BlueprintType)
struct FMetaRewardCost {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMetaRewardRowHandle MetaReward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Cost;
    
    ROBOQUEST_API FMetaRewardCost();
};

