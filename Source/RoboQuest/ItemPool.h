#pragma once
#include "CoreMinimal.h"
#include "ItemPool.generated.h"

USTRUCT(BlueprintType)
struct FItemPool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> RowNames;
    
    ROBOQUEST_API FItemPool();
};

