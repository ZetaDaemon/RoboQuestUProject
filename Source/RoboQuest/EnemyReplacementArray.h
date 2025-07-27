#pragma once
#include "CoreMinimal.h"
#include "EnemyReplacement.h"
#include "EnemyReplacementArray.generated.h"

USTRUCT(BlueprintType)
struct FEnemyReplacementArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemyReplacement> EnemyClasses;
    
    ROBOQUEST_API FEnemyReplacementArray();
};

