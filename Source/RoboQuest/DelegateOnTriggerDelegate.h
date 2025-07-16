#pragma once
#include "CoreMinimal.h"
#include "DelegateOnTriggerDelegate.generated.h"

class UATrigger;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnTrigger, UATrigger*, Trigger, bool, bIsTriggered);

