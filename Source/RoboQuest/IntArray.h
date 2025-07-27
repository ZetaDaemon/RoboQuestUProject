#pragma once
#include "CoreMinimal.h"
#include "IntArray.generated.h"

USTRUCT(BlueprintType)
struct FIntArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> Array;
    
    ROBOQUEST_API FIntArray();
};

