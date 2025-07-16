#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "AModifier.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API UAModifier : public UObject {
    GENERATED_BODY()
public:
    UAModifier();

    UFUNCTION(BlueprintCallable)
    void OnRemove();
    
    UFUNCTION(BlueprintCallable)
    void OnApply();
    
};

