#pragma once
#include "CoreMinimal.h"
#include "Action.h"
#include "StateMachine.generated.h"

USTRUCT(BlueprintType)
struct FStateMachine {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAction> actions;
    
    ROBOQUEST_API FStateMachine();
};

