#pragma once
#include "CoreMinimal.h"
#include "DelegateCameraShakeDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateCameraShake, bool, bNewValue);

