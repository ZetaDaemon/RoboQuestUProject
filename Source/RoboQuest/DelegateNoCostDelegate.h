#pragma once
#include "CoreMinimal.h"
#include "EAction.h"
#include "DelegateNoCostDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateNoCost, EAction, TargetAction);

