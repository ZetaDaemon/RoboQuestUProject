#pragma once
#include "CoreMinimal.h"
#include "AnimationIntensityLoaded.generated.h"

class UAnimMontage;

USTRUCT(BlueprintType)
struct FAnimationIntensityLoaded {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* Intensity[4];
    
    ROBOQUEST_API FAnimationIntensityLoaded();
};

