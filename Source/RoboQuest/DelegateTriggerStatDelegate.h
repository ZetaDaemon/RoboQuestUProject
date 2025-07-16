#pragma once
#include "CoreMinimal.h"
#include "EStat.h"
#include "DelegateTriggerStatDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDelegateTriggerStat, EStat, Stat, float, currentValue, float, Value);

