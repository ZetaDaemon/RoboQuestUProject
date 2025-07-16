#pragma once
#include "CoreMinimal.h"
#include "DelegateJumpOnTargetDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateJumpOnTarget, AActor*, Target);

