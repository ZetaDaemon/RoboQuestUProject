#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "ATrigger.generated.h"

class UModifier_Damage;
class UModifier_Stat;

UCLASS(Blueprintable)
class ROBOQUEST_API UATrigger : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UModifier_Stat*> StatModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UModifier_Damage*> DamageModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSuperTextFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMegaTextFeedback;
    
    UATrigger();

    UFUNCTION(BlueprintCallable)
    void RemoveModifierStat(UModifier_Stat* Modifier);
    
    UFUNCTION(BlueprintCallable)
    void OnCreate();
    
    UFUNCTION(BlueprintCallable)
    void Deactivate();
    
    UFUNCTION(BlueprintCallable)
    void AddModifierStat(UModifier_Stat* Modifier);
    
    UFUNCTION(BlueprintCallable)
    void Activate();
    
};

