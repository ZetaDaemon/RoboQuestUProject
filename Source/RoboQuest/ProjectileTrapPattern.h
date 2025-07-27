#pragma once
#include "CoreMinimal.h"
#include "ProjectileTrapPattern.generated.h"

USTRUCT(BlueprintType)
struct FProjectileTrapPattern {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> IDToActivate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Delay;
    
    ROBOQUEST_API FProjectileTrapPattern();
};

