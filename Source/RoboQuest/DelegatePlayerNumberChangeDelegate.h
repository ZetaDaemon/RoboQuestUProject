#pragma once
#include "CoreMinimal.h"
#include "DelegatePlayerNumberChangeDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegatePlayerNumberChange, int32, Number);

