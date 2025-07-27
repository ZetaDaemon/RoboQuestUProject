#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
#include "IWeaponWarmup.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UIWeaponWarmup : public UInterface {
    GENERATED_BODY()
};

class IIWeaponWarmup : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetWarmupRatio(float NewRatio);
    
};

