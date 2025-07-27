#pragma once
#include "CoreMinimal.h"
#include "APawnAnimInstance.h"
#include "AFlyPawnAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAFlyPawnAnimInstance : public UAPawnAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsNotStunnedAndFalling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsNotStunnedAndNotFalling;
    
    UAFlyPawnAnimInstance();

};

