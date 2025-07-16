#pragma once
#include "CoreMinimal.h"
#include "RQDamageInfo.h"
#include "DelegateOnTriggerTargetDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnTriggerTarget, const FRQDamageInfo&, DamageInfo);

