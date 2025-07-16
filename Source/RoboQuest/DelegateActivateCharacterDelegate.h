#pragma once
#include "CoreMinimal.h"
#include "ETeam.h"
#include "DelegateActivateCharacterDelegate.generated.h"

class AACharacter;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDelegateActivateCharacter, AACharacter*, ActivateCharacter, ETeam, Team, bool, bIsActivate);

