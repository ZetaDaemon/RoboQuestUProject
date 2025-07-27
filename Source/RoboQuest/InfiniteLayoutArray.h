#pragma once
#include "CoreMinimal.h"
#include "InfiniteLayoutRowHandle.h"
#include "InfiniteLayoutArray.generated.h"

USTRUCT(BlueprintType)
struct FInfiniteLayoutArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInfiniteLayoutRowHandle> Layouts;
    
    ROBOQUEST_API FInfiniteLayoutArray();
};

