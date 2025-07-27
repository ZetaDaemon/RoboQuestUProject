#pragma once
#include "CoreMinimal.h"
#include "Response_Text.generated.h"

USTRUCT(BlueprintType)
struct FResponse_Text {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSucess;
    
    ROBOQUEST_API FResponse_Text();
};

