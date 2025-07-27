#pragma once
#include "CoreMinimal.h"
#include "EAction.h"
#include "EInputRecordType.h"
#include "RecordAction.generated.h"

USTRUCT(BlueprintType)
struct FRecordAction {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAction Action;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInputRecordType RecordType;
    
    ROBOQUEST_API FRecordAction();
};

