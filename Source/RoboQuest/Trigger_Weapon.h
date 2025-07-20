#pragma once
#include "CoreMinimal.h"
#include "ATriggerMultiple.h"
#include "DelegateOnTriggerWeaponDelegate.h"
#include "Trigger_Weapon.generated.h"

class AAWeapon;
class ACharacter_Player;
class UAWeaponAffix;

UCLASS(Blueprintable)
class ROBOQUEST_API UTrigger_Weapon : public UATriggerMultiple {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnTriggerWeapon DelegateOnTriggerWeapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ACharacter_Player* PlayerCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAWeaponAffix*> Affixes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDamagePower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpeedPower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAWeapon* TriggerWeapon;
    
    UTrigger_Weapon();

    UFUNCTION(BlueprintCallable)
    void UpdateTriggerStatConditionValue(float NewValue);
    
};

