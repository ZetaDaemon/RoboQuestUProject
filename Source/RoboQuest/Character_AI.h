#pragma once
#include "CoreMinimal.h"
#include "ACharacter.h"
#include "IReplicatedActor.h"
#include "ISpawnable.h"
#include "Templates/SubclassOf.h"
#include "Character_AI.generated.h"


UCLASS(Blueprintable)
class ROBOQUEST_API ACharacter_AI : public AACharacter, public IISpawnable, public IIReplicatedActor {
    GENERATED_BODY()
};

