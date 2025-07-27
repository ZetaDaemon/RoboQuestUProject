#pragma once
#include "CoreMinimal.h"
#include "DotDuration.h"
#include "Dot.generated.h"

USTRUCT(BlueprintType)
struct FDot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Damage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NextTickDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDotDuration> TotalDots;
    
    ROBOQUEST_API FDot();
};

