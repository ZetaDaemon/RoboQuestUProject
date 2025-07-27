#pragma once
#include "CoreMinimal.h"
#include "ATriggerCondition.h"
#include "TriggerCondition_AWeapon.generated.h"

class AAWeapon;

UCLASS(Blueprintable)
class ROBOQUEST_API UTriggerCondition_AWeapon : public UATriggerCondition {
    GENERATED_BODY()
public:
    UTriggerCondition_AWeapon();

    UFUNCTION(BlueprintCallable)
    void OnWeaponChange(AAWeapon* NewWeapon);
    
};

