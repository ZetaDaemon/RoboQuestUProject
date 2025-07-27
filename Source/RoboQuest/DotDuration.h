#pragma once
#include "CoreMinimal.h"
#include "DotDuration.generated.h"

USTRUCT(BlueprintType)
struct FDotDuration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Damage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TickAmount;
    
    ROBOQUEST_API FDotDuration();
};

