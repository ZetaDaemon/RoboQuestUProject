#pragma once
#include "CoreMinimal.h"
#include "APoint.h"
#include "ABossLayerPoint.generated.h"

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AABossLayerPoint : public AAPoint {
    GENERATED_BODY()
public:
    AABossLayerPoint(const FObjectInitializer& ObjectInitializer);

};

