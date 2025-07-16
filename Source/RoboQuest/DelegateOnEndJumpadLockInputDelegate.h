#pragma once
#include "CoreMinimal.h"
#include "DelegateOnEndJumpadLockInputDelegate.generated.h"

class ACharacter_Player;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnEndJumpadLockInput, ACharacter_Player*, PlayerRef);

