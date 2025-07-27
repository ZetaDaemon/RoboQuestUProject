#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
#include "EMultiplayerLoot.h"
#include "IMultiplayerLoot.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UIMultiplayerLoot : public UInterface {
    GENERATED_BODY()
};

class IIMultiplayerLoot : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetMultiplayerLoot(EMultiplayerLoot MultiplayerLoot);
    
};

