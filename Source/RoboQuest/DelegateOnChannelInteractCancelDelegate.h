#pragma once
#include "CoreMinimal.h"
#include "DelegateOnChannelInteractCancelDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnChannelInteractCancel, float, CurrentTime);

