#pragma once
#include "CoreMinimal.h"
#include "DelegateOnScoppedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnScopped, bool, bIsScopped);

