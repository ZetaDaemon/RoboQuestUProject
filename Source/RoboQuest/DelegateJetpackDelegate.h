#pragma once
#include "CoreMinimal.h"
#include "DelegateJetpackDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateJetpack, bool, bIsActive);

