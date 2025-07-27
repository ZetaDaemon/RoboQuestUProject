#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "Components/BoxComponent.h"
#include "AInteractive.h"
#include "EDirection.h"
#include "EDoorBehaviour.h"
#include "EDoorDestination.h"
#include "EDoorState.h"
#include "EDoorWayBehaviour.h"
#include "EPermanentReward.h"
#include "ETutoDoorType.h"
#include "ADoor.generated.h"

class AACodeScreen;
class AADoor;
class AAInteractiveCodeButton;
class AActor;
class ACharacter_Player;
class AController;
class UAnimMontage;
class UAudioComponent;
class UBoxComponent;
class UMaterialInstanceDynamic;
class UPhysicsAsset;
class UPrimitiveComponent;
class USkeletalMeshComponent;
class USoundCue;
class UStaticMeshComponent;
class UTexture2D;

UCLASS(Blueprintable)
class ROBOQUEST_API AADoor : public AAInteractive {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnPlayerStartEnteringDoor, AADoor*, Door, ACharacter_Player*, Player);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDelegateOnDoorCrossedByPlayer, AADoor*, Door, ACharacter_Player*, Player, const FVector&, Forward);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnDoorCrossedByAllPlayers, AADoor*, Door);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateDoorStateChanged, AADoor*, Door, EDoorState, NewDoorState);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* PathBlocker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* TriggerBox1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* TriggerBox2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* OneWayCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* HitBlocker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* HitBlockerBack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* UnderConstruction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* UnderConstructionBack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* StaticMeshBlocker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* TutoBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDirection ConnectorDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText UnlockText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText YouNeedKeyText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText BrobotNeedKeyText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText BrobotNeedUnlockText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText YouNeedCodeText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText BrobotNeedCodeText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText NeedQuestGoalText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* UnlockSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UPhysicsAsset> MirroredPhysicsAsset;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* UnlockAudioComponent;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> UROVisibleDistanceFactorThesholds;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRepRealInteractedPlayers, meta=(AllowPrivateAccess=true))
    TArray<ACharacter_Player*> RealInteractedPlayers;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnPlayerStartEnteringDoor DelegateOnPlayerStartEnteringDoor;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UBoxComponent* EnteringTriggerBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ACharacter_Player*> EnteringPlayers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ACharacter_Player*> ExitingPlayers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ACharacter_Player*> AlreadyExitedPlayers;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceOpenBehavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceCloseBehavior;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDoorBehaviour DoorBehaviour;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDoorDestination CurrentDestination;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName PathLevelRowName;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsUnderConstruction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsSpecialDoor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsSpecialDoorValidated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsBossDoor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsInfiniteInteriorBossDoor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsCodeDoor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DigitsCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Code;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AACodeScreen* CodeScreenRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAInteractiveCodeButton*> CodeButtons;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETutoDoorType TutoDoorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWaitingMultiplayer;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateDoorStateChanged DelegateDoorStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnDoorCrossedByPlayer DelegateOnDoorCrossedByPlayer;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnDoorCrossedByAllPlayers DelegateOnDoorCrossedByAllPlayers;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* RegularDoorIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* LockedDoorIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* LockedBySecretDoorIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* SpecialDoorIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* SpecialDoorValidatedIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* BossDoorIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* UnderConstructionIcon;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSecretDoor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* SecretUnlockMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPermanentReward SecretDoor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPermanentReward SecretKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* SecretIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SecretIconScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor SecretColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor SecretScreenColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceUnlockRewardForAllPlayers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsQuestGoalDoor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor BaseLightColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor BossLightColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor SpecialLightColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor LockedLightColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor WaitingLightColor;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> LightDynamicMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> ScreenDynamicMaterials;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<int32> LightMaterialIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<int32> ScreenMaterialIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor InitScreenColor;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* NavModifier;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> NavModifierClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector NavModifierOffset;
    
    AADoor(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void UpdateMapIcon();
    
    UFUNCTION(BlueprintCallable)
    void UpdateLightColor(const FLinearColor& Color);
    
private:
    UFUNCTION(BlueprintCallable)
    void UpdateDoorOnPlayerDisconnected(AController* ExitingPlayer);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UnlockSecretDoor(ACharacter_Player* PlayerCharacter);
    
private:
    UFUNCTION(BlueprintCallable)
    void TryingToOpenCodeDoor();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool ShouldInitSecretDoorState() const;
    
    UFUNCTION(BlueprintCallable)
    void SetUnderConstruction();
    
    UFUNCTION(BlueprintCallable)
    void SetDoorWayBehavior(EDoorWayBehaviour Behaviour, bool bIsEntering);
    
    UFUNCTION(BlueprintCallable)
    void SetDoorState(EDoorState NewState);
    
    UFUNCTION(BlueprintCallable)
    void SetDoorDestination(EDoorDestination Destination);
    
    UFUNCTION(BlueprintCallable)
    void SetDoorBehaviour(EDoorBehaviour NewBehaviour);
    
    UFUNCTION(BlueprintCallable)
    void SetActivateCompassIcon(bool bActivate);
    
private:
    UFUNCTION(BlueprintCallable)
    void RemovePlayerDisconnected(ACharacter_Player* DisconnectedPlayer);
    
    UFUNCTION(BlueprintCallable)
    void OnRepRealInteractedPlayers();
    
    UFUNCTION(BlueprintCallable)
    void OnQuestGoalValidated();
    
    UFUNCTION(BlueprintCallable)
    void OnPressedResetButton(AAInteractiveCodeButton* Button);
    
    UFUNCTION(BlueprintCallable)
    void OnPressedDigitButton(AAInteractiveCodeButton* Button);
    
    UFUNCTION(BlueprintCallable)
    void OnNavModifierClassLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnEndTriggerBoxOverlap(UPrimitiveComponent* OverlappedComp, AActor* OverlappedActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetUnderConstruction();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetPathLevelRowName(const FName& RowName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetOasisCorruptedDoorScreenTime(float GameTime);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetDoorDestination(EDoorDestination Destination);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintReplicatedActorInitializationFinished();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintOpenSpecialDoor();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintInitSecretDoorState();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintDoorStateChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintCloseSpecialDoor();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnBeginTriggerBoxOverlap(UPrimitiveComponent* OverlappedComp, AActor* OverlappedActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOpen() const;
    
    UFUNCTION(BlueprintCallable)
    void InitSecretDoorState();
    
    UFUNCTION(BlueprintCallable)
    void InitSecretDoorDisplay();
    
private:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasCrossedDoor(ACharacter_Player* Player) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLinearColor GetLightColorByDestination(EDoorDestination Destination) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetForwardDirection() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EDoorState GetDoorState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetDoorPathLevelRowName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetCrossedTeleportDistance() const;
    
private:
    UFUNCTION(BlueprintCallable)
    void DelayedFailInteract();
    
    UFUNCTION(BlueprintCallable)
    void DelayedDisableCompassWidgetTick();
    
    UFUNCTION(BlueprintCallable)
    void DelayedCodeSuccessState();
    
    UFUNCTION(BlueprintCallable)
    void DelayedCodeErrorState();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanUnlockSecretDoor(ACharacter_Player* PlayerCharacter);
    
};

