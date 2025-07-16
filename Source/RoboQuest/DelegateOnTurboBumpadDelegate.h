#pragma once
#include "CoreMinimal.h"
#include "DelegateOnTurboBumpadDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnTurboBumpad, bool, bIsStart);

