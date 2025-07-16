#pragma once
#include "CoreMinimal.h"
#include "RQDamageInfo.h"
#include "DelegateOnTriggerKillDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnTriggerKill, const FRQDamageInfo&, DamageInfo);

