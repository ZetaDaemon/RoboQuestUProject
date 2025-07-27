#pragma once
#include "CoreMinimal.h"
#include "ABotAnimInstance.h"
#include "APawnAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAPawnAnimInstance : public UABotAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FallingValue;
    
    UAPawnAnimInstance();

};

