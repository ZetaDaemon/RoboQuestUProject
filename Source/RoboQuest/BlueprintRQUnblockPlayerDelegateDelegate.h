#pragma once
#include "CoreMinimal.h"
#include "BlueprintRQUnblockPlayerDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBlueprintRQUnblockPlayerDelegate, bool, bSuccess);

