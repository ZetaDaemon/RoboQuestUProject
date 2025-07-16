#pragma once
#include "CoreMinimal.h"
#include "DelegateOnTriggerWeaponDelegate.generated.h"

class AAWeapon;
class UATrigger;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDelegateOnTriggerWeapon, UATrigger*, Trigger, AAWeapon*, Weapon, bool, bIsTriggered);

