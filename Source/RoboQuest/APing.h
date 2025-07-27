#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "APing.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API AAPing : public AActor {
    GENERATED_BODY()
public:
    AAPing(const FObjectInitializer& ObjectInitializer);

};

