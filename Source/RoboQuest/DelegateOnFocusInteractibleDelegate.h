#pragma once
#include "CoreMinimal.h"
#include "DelegateOnFocusInteractibleDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnFocusInteractible, AActor*, Interactible, bool, bIsStart);

