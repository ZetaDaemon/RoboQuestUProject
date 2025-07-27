#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "IPingable.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UIPingable : public UInterface {
    GENERATED_BODY()
};

class IIPingable : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPingged(bool bLocal, FVector Location);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanBePingged();
    
};

