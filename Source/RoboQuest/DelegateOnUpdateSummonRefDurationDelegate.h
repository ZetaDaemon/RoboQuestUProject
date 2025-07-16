#pragma once
#include "CoreMinimal.h"
#include "DelegateOnUpdateSummonRefDurationDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnUpdateSummonRefDuration, AActor*, SummonRef, float, InDuration);

