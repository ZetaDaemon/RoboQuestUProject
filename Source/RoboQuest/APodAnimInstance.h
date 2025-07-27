#pragma once
#include "CoreMinimal.h"
#include "AEnemyAnimInstance.h"
#include "APodAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAPodAnimInstance : public UAEnemyAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StunnedValue;
    
    UAPodAnimInstance();

};

