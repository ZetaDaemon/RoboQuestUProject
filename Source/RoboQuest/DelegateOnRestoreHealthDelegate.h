#pragma once
#include "CoreMinimal.h"
#include "DelegateOnRestoreHealthDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnRestoreHealth, float, RestoredHealth);

