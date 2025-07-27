#pragma once
#include "CoreMinimal.h"
#include "CreditEntry.generated.h"

USTRUCT(BlueprintType)
struct FCreditEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Description;
    
    ROBOQUEST_API FCreditEntry();
};

