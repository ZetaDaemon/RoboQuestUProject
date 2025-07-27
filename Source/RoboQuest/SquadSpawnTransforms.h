#pragma once
#include "CoreMinimal.h"
#include "EnemySpawnTransforms.h"
#include "SquadSpawnTransforms.generated.h"

USTRUCT(BlueprintType)
struct FSquadSpawnTransforms : public FEnemySpawnTransforms {
    GENERATED_BODY()
public:
    ROBOQUEST_API FSquadSpawnTransforms();
};

