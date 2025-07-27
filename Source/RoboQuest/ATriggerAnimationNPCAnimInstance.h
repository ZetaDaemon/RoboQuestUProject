#pragma once
#include "CoreMinimal.h"
#include "ANPCAnimInstance.h"
#include "ATriggerAnimationNPCAnimInstance.generated.h"

class UAnimMontage;

UCLASS(Blueprintable, NonTransient)
class ROBOQUEST_API UATriggerAnimationNPCAnimInstance : public UANPCAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldTriggerAnim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TriggerAnimDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimMontage* AIMAnimMontage;
    
public:
    UATriggerAnimationNPCAnimInstance();

};

