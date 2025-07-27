#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Interface -FallbackName=Interface
#include "ECustomCost.h"
#include "Templates/SubclassOf.h"
#include "IInterractible.generated.h"

class ACharacter_Player;

UINTERFACE(Blueprintable, MinimalAPI)
class UIInterractible : public UInterface {
    GENERATED_BODY()
};

class IIInterractible : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateChannelInteractRatio(float NewRatio);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void StartInterract(ACharacter_Player* PlayerCharacter);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void StartChannelInterract(ACharacter_Player* PlayerCharacter);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnCancelInteractChannel(ACharacter_Player* PlayerCharacter, float CurrentTime, bool bServerValidate);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsWaitingMultiplayer(ACharacter_Player* PlayerCharacter);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool HaveServerValidation();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    int32 GetWrenchCost(ACharacter_Player* PlayerCharacter);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    int32 GetTicketCost(ACharacter_Player* PlayerCharacter);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FText GetMultiWaitingInteractText(ACharacter_Player* PlayerCharacter);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetMinInteractTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FText GetInteractTimeText(ACharacter_Player* PlayerCharacter);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetInteractTime(ACharacter_Player* PlayerCharacter) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FText GetInteractText(ACharacter_Player* PlayerCharacter);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FText GetErrorText(ACharacter_Player* PlayerCharacter) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    ECustomCost GetCustomCostType(ACharacter_Player* PlayerCharacter);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    int32 GetCustomCost(ACharacter_Player* PlayerCharacter);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void FailInteract(ACharacter_Player* PlayerCharacter);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanInteract(ACharacter_Player* PlayerCharacter);
    
};

