#pragma once
#include "CoreMinimal.h"
#include "ActionPriorityParam.h"
#include "EInputRecordType.h"
#include "ActionProperty.generated.h"

USTRUCT(BlueprintType)
struct FActionProperty {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FActionPriorityParam ActionPriorityParam[21];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInputRecordType RecordType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RecordTime;
    
    ROBOQUEST_API FActionProperty();
};

