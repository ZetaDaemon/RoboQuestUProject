#pragma once
#include "CoreMinimal.h"
#include "PredefinedEncounter.h"
#include "ArenaEncounter.generated.h"

USTRUCT(BlueprintType)
struct FArenaEncounter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPredefinedEncounter Base;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPredefinedEncounter Reinforcements;
    
    ROBOQUEST_API FArenaEncounter();
};

