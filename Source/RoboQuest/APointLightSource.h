#pragma once
#include "CoreMinimal.h"
#include "ALightSource.h"
#include "APointLightSource.generated.h"

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AAPointLightSource : public AALightSource {
    GENERATED_BODY()
public:
    AAPointLightSource(const FObjectInitializer& ObjectInitializer);

};

