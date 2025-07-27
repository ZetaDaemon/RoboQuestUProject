#pragma once
#include "CoreMinimal.h"
#include "AFlyAnimInstance.h"
#include "ABeamFlyAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UABeamFlyAnimInstance : public UAFlyAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsInBeamState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PitchBeam;
    
public:
    UABeamFlyAnimInstance();

};

