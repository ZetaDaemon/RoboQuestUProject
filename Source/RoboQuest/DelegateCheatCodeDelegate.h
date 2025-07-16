#pragma once
#include "CoreMinimal.h"
#include "ECheatCode.h"
#include "DelegateCheatCodeDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateCheatCode, ECheatCode, CheatCode, bool, bNewState);

