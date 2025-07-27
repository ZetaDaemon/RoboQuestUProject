#pragma once
#include "CoreMinimal.h"
#include "GeneratorData.generated.h"

USTRUCT(BlueprintType)
struct FGeneratorData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 X;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Y;
    
    ROBOQUEST_API FGeneratorData();
};

