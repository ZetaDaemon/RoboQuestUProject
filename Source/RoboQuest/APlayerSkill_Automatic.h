#pragma once
#include "CoreMinimal.h"
#include "APlayerSkill.h"
#include "APlayerSkill_Automatic.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROBOQUEST_API UAPlayerSkill_Automatic : public UAPlayerSkill {
    GENERATED_BODY()
public:
    UAPlayerSkill_Automatic(const FObjectInitializer& ObjectInitializer);

};

