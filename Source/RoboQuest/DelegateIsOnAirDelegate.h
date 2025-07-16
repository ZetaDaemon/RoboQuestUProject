#pragma once
#include "CoreMinimal.h"
#include "DelegateIsOnAirDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateIsOnAir, bool, bIsOnAir);

