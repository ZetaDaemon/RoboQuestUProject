#pragma once
#include "CoreMinimal.h"
#include "ClientAuthorativeCMC.h"
#include "RoboquestMovementComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROBOQUEST_API URoboquestMovementComponent : public UClientAuthorativeCMC {
    GENERATED_BODY()
public:
    URoboquestMovementComponent(const FObjectInitializer& ObjectInitializer);

};

