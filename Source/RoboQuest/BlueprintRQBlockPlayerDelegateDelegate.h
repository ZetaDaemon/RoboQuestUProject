#pragma once
#include "CoreMinimal.h"
#include "BlueprintRQBlockPlayerDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBlueprintRQBlockPlayerDelegate, bool, bSuccess);

