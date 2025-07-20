#pragma once
#include "CoreMinimal.h"
#include "ActionPriorityParam.generated.h"

USTRUCT(BlueprintType)
struct FActionPriorityParam {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsBlocked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsCancel;
    
    ROBOQUEST_API FActionPriorityParam();
};

