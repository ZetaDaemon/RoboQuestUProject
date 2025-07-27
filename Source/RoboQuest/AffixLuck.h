#pragma once
#include "CoreMinimal.h"
#include "AffixLuck.generated.h"

USTRUCT(BlueprintType)
struct FAffixLuck {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    float LuckByType[3];
    
    ROBOQUEST_API FAffixLuck();
};

