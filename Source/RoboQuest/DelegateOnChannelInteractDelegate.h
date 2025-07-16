#pragma once
#include "CoreMinimal.h"
#include "DelegateOnChannelInteractDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnChannelInteract, float, Ratio);

