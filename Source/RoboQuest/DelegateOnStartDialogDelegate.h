#pragma once
#include "CoreMinimal.h"
#include "DelegateOnStartDialogDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnStartDialog, FName, RowName, bool, bEraseQueue);

