#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "IMapLocator.generated.h"

UINTERFACE(Blueprintable, MinimalAPI)
class UIMapLocator : public UInterface {
    GENERATED_BODY()
};

class IIMapLocator : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector OverrideMapLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FVector OverrideMapForward() const;
    
};

