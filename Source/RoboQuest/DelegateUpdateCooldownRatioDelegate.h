#pragma once
#include "CoreMinimal.h"
#include "DelegateUpdateCooldownRatioDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateUpdateCooldownRatio, float, NewRatio);

