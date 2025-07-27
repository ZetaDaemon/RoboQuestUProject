#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "EBlendable.h"
#include "LightScenarioRowHandle.h"
#include "PostProcessClass.h"
#include "ALightSelector.generated.h"

class AAGameState;
class AALightPostProcess;
class AALightSource;
class UAGameInstance;
class UMaterialInstanceDynamic;
class USceneComponent;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AALightSelector : public AActor {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnUpdateLightScenario, bool, bNeedsFlashLight);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightScenarioRowHandle LightScenarioRowHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AALightPostProcess* CurrentPostProcessActor;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, FPostProcessClass> PostProcessClasses;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<EBlendable> CurrentBlendables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ForcedYaw;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<EBlendable> TemporarilyDisabledBlendables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AALightSource*> LightSources;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAGameInstance* GameInstanceRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAGameState* GameStateRef;
    
public:
    AALightSelector(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    FName UpdateLightScenario();
    
    UFUNCTION(BlueprintCallable)
    void TemporarilyDisableAllBlendables();
    
    UFUNCTION(BlueprintCallable)
    void SetLightScenario(const FName& LightScenarioName);
    
    UFUNCTION(BlueprintCallable)
    void RotateTo(float YawAngle);
    
    UFUNCTION(BlueprintCallable, Exec)
    void RotateCounterClockwise();
    
    UFUNCTION(BlueprintCallable, Exec)
    void RotateClockwise();
    
    UFUNCTION(BlueprintCallable)
    void ReEnableAllBlendables();
    
    UFUNCTION(BlueprintCallable)
    void OnPostProcessClassLoaded(FName LightScenarioRowName, bool bSetCurrent);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSwitchLightScenario();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetBlendableVisible(EBlendable InBlendable, bool bIsVisible);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    UMaterialInstanceDynamic* OnBlueprintGetDynamicBlendable(EBlendable InBlendable) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool NeedsFlashLight() const;
    
    UFUNCTION(BlueprintCallable, Exec)
    FName IncrementLightScenario();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAGameState* GetGameStateRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAGameInstance* GetGameInstanceRef() const;
    
    UFUNCTION(BlueprintCallable, Exec)
    FName DecrementLightScenario();
    
};

