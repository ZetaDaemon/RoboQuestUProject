#pragma once
#include "CoreMinimal.h"
#include "EnvironementType.generated.h"

USTRUCT(BlueprintType)
struct FEnvironementType {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EnvironmentTypes;
    
    ROBOQUEST_API FEnvironementType();
};

