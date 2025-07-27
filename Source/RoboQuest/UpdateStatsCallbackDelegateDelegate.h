#pragma once
#include "CoreMinimal.h"
#include "UpdateStatsCallbackDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdateStatsCallbackDelegate, const TArray<FName>&, SuccessfulOSS);

