#pragma once
#include "CoreMinimal.h"
#include "AAISkill.h"
#include "AEnemySkill.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROBOQUEST_API UAEnemySkill : public UAAISkill {
    GENERATED_BODY()
public:
    UAEnemySkill(const FObjectInitializer& ObjectInitializer);

};

