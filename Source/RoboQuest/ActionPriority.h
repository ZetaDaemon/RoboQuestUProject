#pragma once
#include "CoreMinimal.h"
#include "EAction.h"
#include "ActionPriority.generated.h"

USTRUCT(BlueprintType)
struct FActionPriority {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAction currentAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool havePriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CancelAction;
    
    ROBOQUEST_API FActionPriority();
};

