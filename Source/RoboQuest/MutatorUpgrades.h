#pragma once
#include "CoreMinimal.h"
#include "LevelGeneratorMutatorRow.h"
#include "MutatorUpgrades.generated.h"

USTRUCT(BlueprintType)
struct FMutatorUpgrades {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelGeneratorMutatorRow ParentMutator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLevelGeneratorMutatorRow> SubMutators;
    
    ROBOQUEST_API FMutatorUpgrades();
};

