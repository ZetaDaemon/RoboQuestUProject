#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "EElement.h"
#include "IDamageable.h"
#include "AElementalSwitcher.generated.h"

class AAGameState;
class USceneComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AAElementalSwitcher : public AActor, public IIDamageable {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateSwitchElement, EElement, NewElement);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=RepNotify_CurrentElement, meta=(AllowPrivateAccess=true))
    EElement CurrentElement;
    
    UPROPERTY(BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateSwitchElement DelegateSwitchElement;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanSwitchElement;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAGameState* GameStateRef;
    
public:
    AAElementalSwitcher(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
    UFUNCTION(BlueprintCallable)
    void RepNotify_CurrentElement();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnApplyNewElement(EElement Element, bool bInstant);
    
public:
    UFUNCTION(BlueprintCallable)
    void InitFirstElement(EElement InElement);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAGameState* GetGameStateRef() const;
    

    // Fix for true pure virtual functions not being implemented
};

