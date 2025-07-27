#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=AnimInstance -FallbackName=AnimInstance
#include "AAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAAnimInstance : public UAnimInstance {
    GENERATED_BODY()
public:
    UAAnimInstance();

};

