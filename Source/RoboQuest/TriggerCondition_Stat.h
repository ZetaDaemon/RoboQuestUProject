#pragma once
#include "CoreMinimal.h"
#include "ATriggerCondition.h"
#include "EComparator.h"
#include "EModifierStatType.h"
#include "EStat.h"
#include "ETargetType.h"
#include "TriggerCondition_Stat.generated.h"

class AAWeapon;

UCLASS(Blueprintable)
class ROBOQUEST_API UTriggerCondition_Stat : public UATriggerCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStat TriggerStat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EComparator Comparator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EModifierStatType ValueType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETargetType targetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TriggerValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAWeapon* BindWeapon;
    
    UTriggerCondition_Stat();

    UFUNCTION(BlueprintCallable)
    void OnWeaponChange(AAWeapon* NewWeapon);
    
    UFUNCTION(BlueprintCallable)
    void OnStatNotify(EStat Stat, float currentValue, float Value);
    
};

