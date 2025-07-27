#pragma once
#include "CoreMinimal.h"
#include "AnimationIntensity.h"
#include "AnimationIntensityByDirection.generated.h"

USTRUCT(BlueprintType)
struct FAnimationIntensityByDirection {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationIntensity Directions[4];
    
    ROBOQUEST_API FAnimationIntensityByDirection();
};

