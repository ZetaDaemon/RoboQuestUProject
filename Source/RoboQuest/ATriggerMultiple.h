#pragma once
#include "CoreMinimal.h"
#include "ATrigger.h"
#include "DelegateOnTriggerDelegate.h"
#include "ATriggerMultiple.generated.h"

class UATriggerCondition;

UCLASS(Blueprintable)
class ROBOQUEST_API UATriggerMultiple : public UATrigger {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnTrigger DelegateOnTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UATriggerCondition*> Conditions;
    
    UATriggerMultiple();

    UFUNCTION(BlueprintCallable)
    void OnConditionValidate(UATriggerCondition* Condition, bool bIsValid);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsValidate();
    
    UFUNCTION(BlueprintCallable)
    void AddCondition(UATriggerCondition* NewCondition);
    
};

