#pragma once
#include "CoreMinimal.h"
#include "DelegateOnSprintDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnSprint, bool, bIsSprinting);

