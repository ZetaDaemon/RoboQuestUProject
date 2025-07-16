#pragma once
#include "CoreMinimal.h"
#include "DelegateOnUpdateMaxSummonRefDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnUpdateMaxSummonRef, int32, NewMaxSummonRef);

