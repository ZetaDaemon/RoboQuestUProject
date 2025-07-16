#pragma once
#include "CoreMinimal.h"
#include "EPermanentReward.h"
#include "DelegateOnUnlockPermanentRewardDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnUnlockPermanentReward, EPermanentReward, PermanentReward);

