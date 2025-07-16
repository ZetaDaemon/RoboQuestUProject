#pragma once
#include "CoreMinimal.h"
#include "EAction.h"
#include "DelegateOnStackUpdateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnStackUpdate, EAction, TargetAction, int32, CurrentStack);

