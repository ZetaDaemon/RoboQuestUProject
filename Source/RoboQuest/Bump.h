#pragma once
#include "CoreMinimal.h"
#include "Bump.generated.h"

USTRUCT(BlueprintType)
struct FBump {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HorizontalImpulse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VerticalImpulse;
    
    ROBOQUEST_API FBump();
};

