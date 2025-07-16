#pragma once
#include "CoreMinimal.h"
#include "EAction.h"
#include "DelegateTriggerActionDelegate.generated.h"

class ACharacter_Player;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDelegateTriggerAction, ACharacter_Player*, Player, EAction, Action, bool, bIsStarting);

