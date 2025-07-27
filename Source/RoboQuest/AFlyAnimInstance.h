#pragma once
#include "CoreMinimal.h"
#include "AEnemyAnimInstance.h"
#include "AFlyAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAFlyAnimInstance : public UAEnemyAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsFalling;
    
    UAFlyAnimInstance();

};

