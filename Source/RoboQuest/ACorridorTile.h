#pragma once
#include "CoreMinimal.h"
#include "ATile.h"
#include "ACorridorTile.generated.h"

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AACorridorTile : public AATile {
    GENERATED_BODY()
public:
    AACorridorTile(const FObjectInitializer& ObjectInitializer);

};

