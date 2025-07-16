#pragma once
#include "CoreMinimal.h"
#include "EInteractErrorReason.h"
#include "DelegateOnInteractErrorDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnInteractError, EInteractErrorReason, Reason);

