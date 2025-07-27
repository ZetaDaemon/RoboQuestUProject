#pragma once
#include "CoreMinimal.h"
#include "ERank.h"
#include "DifficultyCompletion.generated.h"

USTRUCT(BlueprintType)
struct FDifficultyCompletion {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BestCompletionTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERank BestRank;
    
    ROBOQUEST_API FDifficultyCompletion();
};

