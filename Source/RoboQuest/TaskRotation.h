#pragma once
#include "CoreMinimal.h"
#include "TaskRotation.generated.h"

USTRUCT(BlueprintType)
struct FTaskRotation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bProcessRotate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCancelTask;
    
    ROBOQUEST_API FTaskRotation();
};

