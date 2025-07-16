#pragma once
#include "CoreMinimal.h"
#include "DelegateOnValidateDelegate.generated.h"

class UATriggerCondition;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnValidate, UATriggerCondition*, TriggerCondition, bool, bIsValid);

