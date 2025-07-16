#pragma once
#include "CoreMinimal.h"
#include "DelegateOnActivateSummonRefDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnActivateSummonRef, AActor*, SummonRef, bool, bIsActivate);

