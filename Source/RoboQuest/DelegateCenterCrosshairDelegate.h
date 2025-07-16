#pragma once
#include "CoreMinimal.h"
#include "DelegateCenterCrosshairDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateCenterCrosshair, bool, bCenterCrosshair);

