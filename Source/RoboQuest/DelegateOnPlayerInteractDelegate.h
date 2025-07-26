#pragma once
#include "CoreMinimal.h"
#include "DelegateOnPlayerInteractDelegate.generated.h"

class AAInteractive;
class ACharacter_Player;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnPlayerInteract, AAInteractive*, InteractiveActor, ACharacter_Player*, InteractPlayer);

