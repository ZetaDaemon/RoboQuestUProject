#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
#include "IOrderableActor.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UIOrderableActor : public UInterface {
    GENERATED_BODY()
};

class IIOrderableActor : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OrderedInit();
    
};

