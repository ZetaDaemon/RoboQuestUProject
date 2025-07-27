#pragma once
#include "CoreMinimal.h"
#include "AFlyAnimInstance.h"
#include "AJetFlyAnimInstance.generated.h"

class UAnimMontage;

UCLASS(Blueprintable, NonTransient)
class UAJetFlyAnimInstance : public UAFlyAnimInstance {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* AnimRollLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* AnimRollRight;
    
public:
    UAJetFlyAnimInstance();

};

