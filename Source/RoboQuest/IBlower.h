#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "IBlower.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UIBlower : public UInterface {
    GENERATED_BODY()
};

class IIBlower : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnExitBlower(FVector OutImpulse);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnEnterBlower(bool bIsLateral);
    
};

