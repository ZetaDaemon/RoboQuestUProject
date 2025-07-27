#pragma once
#include "CoreMinimal.h"
#include "BlueprintUserStats.h"
#include "QueryStatsCallbackDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FQueryStatsCallbackDelegate, const TArray<FName>&, SuccessfulOSS, const FBlueprintUserStats&, UserStats);

