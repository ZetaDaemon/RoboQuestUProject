#pragma once
#include "CoreMinimal.h"
#include "AAIProjectile.h"
#include "AAllyProjectile.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API AAAllyProjectile : public AAAIProjectile {
    GENERATED_BODY()
public:
    AAAllyProjectile(const FObjectInitializer& ObjectInitializer);

};

