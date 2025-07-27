#pragma once
#include "CoreMinimal.h"
#include "PredefinedEnemy.h"
#include "PredefinedEncounter.generated.h"

USTRUCT(BlueprintType)
struct FPredefinedEncounter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPredefinedEnemy> Enemies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPredefinedEnemy> AdditionalsInMultiplayer;
    
    ROBOQUEST_API FPredefinedEncounter();
};

