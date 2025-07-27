#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
#include "IObjectSlot.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UIObjectSlot : public UInterface {
    GENERATED_BODY()
};

class IIObjectSlot : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetParameters(uint8 Amount, uint8 Level, int32 ID);
    
};

