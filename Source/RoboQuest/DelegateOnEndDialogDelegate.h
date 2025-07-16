#pragma once
#include "CoreMinimal.h"
#include "DelegateOnEndDialogDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnEndDialog, FName, RowName, bool, bCancelled);

