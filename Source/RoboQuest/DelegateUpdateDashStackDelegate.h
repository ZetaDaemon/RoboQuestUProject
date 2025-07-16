#pragma once
#include "CoreMinimal.h"
#include "DelegateUpdateDashStackDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateUpdateDashStack, int32, StackAmount);

