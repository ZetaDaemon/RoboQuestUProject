#pragma once
#include "CoreMinimal.h"
#include "DelegateOnReloadDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnReload, bool, bIsStart);

