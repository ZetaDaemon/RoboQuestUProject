#pragma once
#include "CoreMinimal.h"
#include "DelegateOnRemoveDelegate.generated.h"

class UAModifier;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnRemove, UAModifier*, Modifier);

