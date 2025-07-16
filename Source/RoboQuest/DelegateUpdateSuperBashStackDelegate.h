#pragma once
#include "CoreMinimal.h"
#include "DelegateUpdateSuperBashStackDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateUpdateSuperBashStack, int32, CurrentStack);

