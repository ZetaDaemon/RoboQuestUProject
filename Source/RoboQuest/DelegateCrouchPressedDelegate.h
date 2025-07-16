#pragma once
#include "CoreMinimal.h"
#include "DelegateCrouchPressedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateCrouchPressed, bool, bCrouchPressed);

