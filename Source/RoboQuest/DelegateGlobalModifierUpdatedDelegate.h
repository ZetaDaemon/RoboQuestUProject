#pragma once
#include "CoreMinimal.h"
#include "EStat.h"
#include "DelegateGlobalModifierUpdatedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateGlobalModifierUpdated, EStat, Stat);

