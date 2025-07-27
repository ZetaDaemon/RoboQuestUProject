#pragma once
#include "CoreMinimal.h"
#include "MaxAnimationSpecial.generated.h"

class UAnimMontage;

USTRUCT(BlueprintType)
struct FMaxAnimationSpecial {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* AnimMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Frequency;
    
    ROBOQUEST_API FMaxAnimationSpecial();
};

