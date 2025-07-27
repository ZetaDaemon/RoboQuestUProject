#pragma once
#include "CoreMinimal.h"
#include "ActionPriority.h"
#include "EAction.h"
#include "EInputRecordType.h"
#include "Action.generated.h"

USTRUCT(BlueprintType)
struct FAction {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInputRecordType RecordType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RecordTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAction pressedAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FActionPriority> actionPriorities;
    
    ROBOQUEST_API FAction();
};

