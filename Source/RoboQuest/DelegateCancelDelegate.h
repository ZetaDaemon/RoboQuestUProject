#pragma once
#include "CoreMinimal.h"
#include "EAction.h"
#include "DelegateCancelDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateCancel, EAction, TargetAction);

