#pragma once
#include "CoreMinimal.h"
#include "AInteractive.h"
#include "EPermanentReward.h"
#include "AInteractiveCodeButton.generated.h"

class AAInteractiveCodeButton;
class AATile;
class UMaterialInterface;
class UWidgetComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AAInteractiveCodeButton : public AAInteractive {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnPressed, AAInteractiveCodeButton*, Button);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 InputDigit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPermanentReward DoorReward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* InitMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* PressedMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DisabledMaterial;
    
    AAInteractiveCodeButton(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void Reset();
    
    UFUNCTION(BlueprintCallable)
    void OnPressed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    UWidgetComponent* GetWidgetComponent() const;
    
    UFUNCTION(BlueprintCallable)
    void Disable();
    
private:
    UFUNCTION(BlueprintCallable)
    void AllDoorsRegistered(AATile* Tile);
    
};

