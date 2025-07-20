#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
#include "IFocusable.generated.h"

class ACharacter_Player;

UINTERFACE(Blueprintable, MinimalAPI)
class UIFocusable : public UInterface {
    GENERATED_BODY()
};

class IIFocusable : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ShouldIgnoreFocus();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnBlueprintFocus(bool bIsStarting, ACharacter_Player* PlayerCharacter);
    
};

