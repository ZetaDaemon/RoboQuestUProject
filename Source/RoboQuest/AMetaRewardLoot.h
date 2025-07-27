#pragma once
#include "CoreMinimal.h"
#include "AMetaReward.h"
#include "AMetaRewardLoot.generated.h"

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API UAMetaRewardLoot : public UAMetaReward {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Type;
    
    UAMetaRewardLoot();

};

