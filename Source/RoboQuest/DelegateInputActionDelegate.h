#pragma once
#include "CoreMinimal.h"
#include "EAction.h"
#include "DelegateInputActionDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateInputAction, EAction, TargetAction, bool, bIsPressed);

