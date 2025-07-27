#pragma once
#include "CoreMinimal.h"
#include "BlueprintRQReportPlayerDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBlueprintRQReportPlayerDelegate, bool, bSuccess);

