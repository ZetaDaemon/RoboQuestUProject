#pragma once
#include "CoreMinimal.h"
#include "DelegateUpdateFallDurationDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateUpdateFallDuration, float, InDuration);

