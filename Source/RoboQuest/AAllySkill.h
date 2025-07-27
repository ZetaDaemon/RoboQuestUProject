#pragma once
#include "CoreMinimal.h"
#include "AAISkill.h"
#include "AAllySkill.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROBOQUEST_API UAAllySkill : public UAAISkill {
    GENERATED_BODY()
public:
    UAAllySkill(const FObjectInitializer& ObjectInitializer);

};

