#pragma once
#include "CoreMinimal.h"
#include "ModifierValue.generated.h"

USTRUCT(BlueprintType)
struct FModifierValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float flat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Ratio;
    
    ROBOQUEST_API FModifierValue();
};

