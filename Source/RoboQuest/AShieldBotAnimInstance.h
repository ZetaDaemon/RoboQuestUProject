#pragma once
#include "CoreMinimal.h"
#include "ABotAnimInstance.h"
#include "AShieldBotAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ROBOQUEST_API UAShieldBotAnimInstance : public UABotAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShieldState;
    
public:
    UAShieldBotAnimInstance();

};

