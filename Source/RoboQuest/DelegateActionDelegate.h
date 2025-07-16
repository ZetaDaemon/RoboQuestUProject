#pragma once
#include "CoreMinimal.h"
#include "EAction.h"
#include "DelegateActionDelegate.generated.h"

class ACharacter_Player;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDelegateAction, EAction, TargetAction, ACharacter_Player*, Player, bool, bIsStarting);

