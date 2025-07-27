#pragma once
#include "CoreMinimal.h"
#include "APoint.h"
#include "ASequencePoint.generated.h"

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AASequencePoint : public AAPoint {
    GENERATED_BODY()
public:
    AASequencePoint(const FObjectInitializer& ObjectInitializer);

};

