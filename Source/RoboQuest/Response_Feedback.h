#pragma once
#include "CoreMinimal.h"
#include "Response_Feedback.generated.h"

USTRUCT(BlueprintType)
struct FResponse_Feedback {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ID;
    
    ROBOQUEST_API FResponse_Feedback();
};

