#pragma once
#include "CoreMinimal.h"
#include "DelegateJetpackFuelRatioDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateJetpackFuelRatio, float, InRatio);

