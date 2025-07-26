#pragma once
#include "CoreMinimal.h"
#include "ETrapType.h"
#include "TrapCount.generated.h"

USTRUCT(BlueprintType)
struct FTrapCount {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETrapType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 Count;
    
    ROBOQUEST_API FTrapCount();
};

