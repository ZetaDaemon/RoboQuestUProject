#pragma once
#include "CoreMinimal.h"
#include "EPickup.h"
#include "DelegateOnGrantPickupDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDelegateOnGrantPickup, EPickup, Type, float, Value, UClass*, Source);

