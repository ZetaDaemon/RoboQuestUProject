#pragma once
#include "CoreMinimal.h"
#include "DelegateUpdateScopeChargedRatioDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateUpdateScopeChargedRatio, float, NewRatio);

