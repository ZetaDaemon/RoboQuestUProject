#pragma once
#include "CoreMinimal.h"
#include "ATriggerAnimationNPCAnimInstance.h"
#include "ABurgerBillAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ROBOQUEST_API UABurgerBillAnimInstance : public UATriggerAnimationNPCAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCageState;
    
    UABurgerBillAnimInstance();

};

