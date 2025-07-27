#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
#include "ISecretTrigger.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UISecretTrigger : public UInterface {
    GENERATED_BODY()
};

class IISecretTrigger : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Reset();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool IsTriggered() const;
    
};

