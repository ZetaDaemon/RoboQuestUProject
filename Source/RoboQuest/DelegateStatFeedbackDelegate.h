#pragma once
#include "CoreMinimal.h"
#include "DelegateStatFeedbackDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateStatFeedback, int32, NewAmount);

