#pragma once
#include "CoreMinimal.h"
#include "AnimationIntensityLoaded.h"
#include "AnimationIntensityByDirectionLoaded.generated.h"

USTRUCT(BlueprintType)
struct FAnimationIntensityByDirectionLoaded {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationIntensityLoaded Directions[4];
    
    ROBOQUEST_API FAnimationIntensityByDirectionLoaded();
};

