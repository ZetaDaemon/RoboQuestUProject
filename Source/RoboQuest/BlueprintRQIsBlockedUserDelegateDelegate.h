#pragma once
#include "CoreMinimal.h"
#include "BlueprintRQIsBlockedUserDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBlueprintRQIsBlockedUserDelegate, bool, bIsBlocked);

