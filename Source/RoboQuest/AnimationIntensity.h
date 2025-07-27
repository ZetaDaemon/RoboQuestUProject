#pragma once
#include "CoreMinimal.h"
#include "AnimationIntensity.generated.h"

class UAnimMontage;

USTRUCT(BlueprintType)
struct FAnimationIntensity {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAnimMontage> Intensity[4];
    
    ROBOQUEST_API FAnimationIntensity();
};

