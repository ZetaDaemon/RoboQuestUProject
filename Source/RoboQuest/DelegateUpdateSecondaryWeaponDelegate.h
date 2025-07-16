#pragma once
#include "CoreMinimal.h"
#include "DelegateUpdateSecondaryWeaponDelegate.generated.h"

class AAWeapon;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateUpdateSecondaryWeapon, AAWeapon*, OldSecondaryWeapon, AAWeapon*, NewSecondaryWeapon);

