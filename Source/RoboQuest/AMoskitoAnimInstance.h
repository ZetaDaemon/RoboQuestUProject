#pragma once
#include "CoreMinimal.h"
#include "AFlyAnimInstance.h"
#include "AMoskitoAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ROBOQUEST_API UAMoskitoAnimInstance : public UAFlyAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsDrinking;
    
public:
    UAMoskitoAnimInstance();

};

