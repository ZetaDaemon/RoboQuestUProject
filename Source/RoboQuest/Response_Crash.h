#pragma once
#include "CoreMinimal.h"
#include "Response_Crash.generated.h"

USTRUCT(BlueprintType)
struct FResponse_Crash {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ID;
    
    ROBOQUEST_API FResponse_Crash();
};

