#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "DelegateOnPlayerInteractDelegate.h"
#include "ECustomCost.h"
#include "EInteractState.h"
#include "IFocusable.h"
#include "IInterractible.h"
#include "IPingable.h"
#include "IReplicatedActor.h"
#include "ITileReplicatedActor.h"
#include "AInteractive.generated.h"

class AAGameState;
class AALevelGenerator;
class AAPlayerController;
class AATile;
class ACharacter_Player;
class UAMapLocator;
class UAudioComponent;
class UBoxComponent;
class UCurveVector;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UParticleSystem;
class UPrimitiveComponent;
class USceneComponent;
class USoundCue;
class UTexture2D;
class UUserWidget;
class UWidgetComponent;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AAInteractive : public AActor, public IIFocusable, public IIInterractible, public IITileReplicatedActor, public IIReplicatedActor, public IIPingable {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnNotifyMultiplayerInteract, ACharacter_Player*, InteractPlayer);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* InteractCollision;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InteractTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinInteractTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* StartChannelSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* ChannelingSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* CancelInteractSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D ChannelingSoundFadeDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText InteractTimeText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText InteractText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText ErrorText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInteractState InteractState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TicketCost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WrenchCost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CustomCost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECustomCost CustomCostType;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMultiInteraction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bServerValidation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLocalInteraction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool bStartDeactivate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStencilInteraction;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText MultiWaitingInteractText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundCue> InteractSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundCue> InteractHaptic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UParticleSystem> InteractFX;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRegisterMapLocatorOnFirstActivation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRegisterMapLocatorWhenActivated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUnregisterMapLocatorWhenDeactivated;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* InteractSoundLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* InteractHapticLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystem* InteractFXLoaded;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ACharacter_Player*> InteractPlayers;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* ChannelingSoundComponent;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnPlayerInteract DelegateOnPlayerInteract;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> DynamicDiscoverMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DiscoverMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPingable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D PingWidgetSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PingWidgetOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* PingIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveVector* HoverMeshLocationCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveVector* HoverMeshRotationCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform BaseHoverMeshRelativeTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveVector* HoverWidgetLocationCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveVector* HoverWidgetRotationCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform BaseHoverWidgetRelativeTransform;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AALevelGenerator* LevelGeneratorRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAGameState* GameStateRef;
    
public:
    AAInteractive(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
    UFUNCTION(BlueprintCallable)
    void UpdateHoverWidgetRotationAnim(const FVector& Rotation);
    
    UFUNCTION(BlueprintCallable)
    void UpdateHoverWidgetLocationAnim(const FVector& Location);
    
    UFUNCTION(BlueprintCallable)
    void UpdateHoverMeshRotationAnim(const FVector& Rotation);
    
    UFUNCTION(BlueprintCallable)
    void UpdateHoverMeshLocationAnim(const FVector& Location);
    
public:
    UFUNCTION(BlueprintCallable)
    bool TryingToDestroy(bool bForceDestroy);
    
    UFUNCTION(BlueprintCallable)
    void StopHoverAnim();
    
    UFUNCTION(BlueprintCallable)
    void StartHoverAnim();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void StartDiscoveryState();
    
    UFUNCTION(BlueprintCallable)
    void SimulateOnPlayerInteract(ACharacter_Player* PlayerCharacter);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetTickEnabled(bool bEnable);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetCustomParamterForDiscoveryMaterial(UMaterialInstanceDynamic* DynamicMaterial, int32 Index);
    
    UFUNCTION(BlueprintCallable)
    void SetActiveReplicatedActorState();
    
protected:
    UFUNCTION(BlueprintCallable)
    void RemoveTicketCost();
    
    UFUNCTION(BlueprintCallable)
    void RemoveCustomCost();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnWidgetCompassLoaded(UUserWidget* NewWidget);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnUnloadPreviousLevel();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnTimerPingEnd();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnStartInteract(ACharacter_Player* PlayerCharacter);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnPlayerDisconnected(ACharacter_Player* DisconnectedPlayer);
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastStartInteract(ACharacter_Player* PlayerCharacter);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastMultiplayerInteract(ACharacter_Player* PlayerCharacter, bool bIsServerPlayer);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastDeactivateInteractive(bool bHide);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastActivateInteractive(bool bShow);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintWidgetCompassLoaded();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintTryingToDestroy();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintMultiplayerInteract(ACharacter_Player* PlayerCharacter);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintDeactivateInteractive();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintActivateInteractive();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocalInteraction();
    
protected:
    UFUNCTION(BlueprintCallable)
    void InitTicketCost(int32 NewTicketCost);
    
    UFUNCTION(BlueprintCallable)
    void InitCustomCost(ECustomCost Type, int32 NewCustomCost);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UPrimitiveComponent* GetPrimitiveComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AATile* GetParentTile();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UAMapLocator* GetMapLocator() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACharacter_Player* GetLocalPlayerRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAPlayerController* GetLocalPlayerControllerRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AALevelGenerator* GetLevelGeneratorRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    USoundCue* GetInteractSound(ACharacter_Player* PlayerCharacter);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    USceneComponent* GetHoveringWidgetComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    USceneComponent* GetHoveringMeshComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAGameState* GetGameStateRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FString GetDisplayName();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void DeactivateInteractive(bool bHide);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ActivateInteractive(bool bShow);
    

    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    AATile* GetSlotParentTile() const override PURE_VIRTUAL(GetSlotParentTile, return NULL;);
    
    UFUNCTION(BlueprintCallable)
    AActor* GetSlotParentActor() const override PURE_VIRTUAL(GetSlotParentActor, return NULL;);
    
    UFUNCTION(BlueprintCallable)
    USceneComponent* GetSlotComponent() const override PURE_VIRTUAL(GetSlotComponent, return NULL;);
    
};

