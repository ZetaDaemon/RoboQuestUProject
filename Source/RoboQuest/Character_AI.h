#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "ACharacter.h"
#include "EAIMovementType.h"
#include "EAIState.h"
#include "EAction.h"
#include "EDamageType.h"
#include "EDirection.h"
#include "ERotationDirection.h"
#include "ETeam.h"
#include "IReplicatedActor.h"
#include "ISpawnable.h"
#include "RQDamageInfo.h"
#include "TargetInfo.h"
#include "Templates/SubclassOf.h"
#include "Character_AI.generated.h"

class AAPlayerController;
class AActor;
class ACharacter_AI;
class ACharacter_Player;
class UACompassLocator;
class UAStatManager;
class UAnimInstance;
class UAnimMontage;
class UAudioComponent;
class UCurveFloat;
class UDataTable;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UParticleSystem;
class USkeletalMesh;
class USoundCue;
class UStaticMesh;
class UStaticMeshComponent;
class UTexture2D;

UCLASS(Blueprintable)
class ROBOQUEST_API ACharacter_AI : public AACharacter, public IISpawnable, public IIReplicatedActor {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateUpdateStaggerDuration, float, Duration);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateUpdatePreshootRatio, float, PreshootRatio);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateUpdateAIState, EAIState, State, bool, bIsStart);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnTokenPriorityRecept);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnActivate, bool, bIsActivate);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateEmpower, ACharacter_AI*, AIRef, bool, bIsStart);
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInterface*> OverridedMaterial;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Name;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor PlaceholderColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ShieldScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* ShieldMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* ShieldMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthBarSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector MeshRelativeScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* SM_Shield;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, float> CustomFloatValue;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> DynamicMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> DeathMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* EyePatchMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* EyePatchSpawnMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* EyePatchDeathMaterial;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* EyePatchMeshComponent;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERotationDirection WantedRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLockRotation;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMesh* SkeletalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldRotate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAnimInstance> AnimInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseYawAimInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float YawAimInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PitchAimInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BasePitchAimInterpSpeed;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AIMSpeedRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLockAIM;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceAIMLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ForcedAIMLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimVelocityRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MoveSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAIMovementType MovementType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHaveGravity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool bAutoCheckActivation;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnActivate DelegateOnActivate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasAIActivated;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bVisionStartTraceFromLocation;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCalculateSightBlock;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnTokenPriorityRecept DelegateOnTokenPriorityRecept;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimMontage* HitAnimation[4];
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<EDamageType> NoGravityDeathDamageTypes;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform InitialRelativeTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRagdollDeath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRQDamageInfo RagdollDamageInfo;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTargetInfo CurrentTargetInfo;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Threat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ThreatModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLockTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* NetworkedTarget;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateEmpower DelegateEmpower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasAI;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveFloat* SpawnEffectCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* SpawnSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystem* SpawnParticle;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsSpawned;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCurrentlySpawned;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AACharacter* SpawnOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSummonDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> SpawnMaterials;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* MoveAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* IdleAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* FootstepSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* MoveSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* IdleSound;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateUpdateAIState DelegateUpdateAIState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAIState AIState;
    
private:
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShieldPod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsWorker;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAPlayerController* LocalPlayerControllerRef;
    
public:
    ACharacter_AI(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void UseSkill(EAction Action);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateTimeDilatation(float NewTimeDilation);
    
    UFUNCTION(BlueprintCallable)
    void UpdateMoveSpeed(float NewSpeed);
    
    UFUNCTION(BlueprintCallable)
    void TriggerTurnRotation(ERotationDirection Direction);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void TriggerDeathMaterialEffects(const FRQDamageInfo& DamageInfo);
    
    UFUNCTION(BlueprintCallable)
    void StoreDynamicMaterials();
    
public:
    UFUNCTION(BlueprintCallable)
    void StopRefreshDynamicLoadingState();
    
    UFUNCTION(BlueprintCallable)
    void StopCheckVision();
    
    UFUNCTION(BlueprintCallable)
    void StartSpawnEffect();
    
    UFUNCTION(BlueprintCallable)
    void StartRefreshDynamicLoadingState();
    
    UFUNCTION(BlueprintCallable)
    void StartAutoCheckActivation();
    
    UFUNCTION(BlueprintCallable)
    void SimulateSetYawAIM(float InYawAIM);
    
    UFUNCTION(BlueprintCallable)
    void SimulateSetPitchAIM(float InPitchAIM);
    
    UFUNCTION(BlueprintCallable)
    void SetNewAiState(EAIState NewState);
    
    UFUNCTION(BlueprintCallable)
    void SetMeshActivated(bool bActivate);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetLoopingSoundActivate(bool bActivate);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetIconActivate(bool bIsActivate);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetDynamicMaterialVectorParam(FName ParameterName, FVector NewVector);
    
    UFUNCTION(BlueprintCallable)
    void SetDynamicMaterialFloatParamByIndex(FName ParameterName, float NewValue, int32 Materialindex);
    
    UFUNCTION(BlueprintCallable)
    void SetDynamicMaterialFloatParam(FName ParameterName, float NewValue);
    
    UFUNCTION(BlueprintCallable)
    void SetDynamicMaterialColorParamByIndex(FName ParameterName, FLinearColor NewColor, int32 Materialindex);
    
    UFUNCTION(BlueprintCallable)
    void SetDynamicMaterialColorParam(FName ParameterName, FLinearColor NewColor);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetCurrentTarget(FTargetInfo NewTargetInfo);
    
    UFUNCTION(BlueprintCallable)
    void SetCompassIconActivate(bool bIsActivate);
    
    UFUNCTION(BlueprintCallable)
    void SetCollisionEnabled(bool bIsEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetAIActivated(bool bActivate);
    
    UFUNCTION(BlueprintCallable)
    void ResetCurrentTarget();
    
    UFUNCTION(BlueprintCallable)
    void RemoveCustomFloatValue(FName PropertyName);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnTimerLifeSpanFinished();
    
    UFUNCTION(BlueprintCallable)
    void OnNotifyCurrentTargetUpdateTargetable(bool IsTargetable, AActor* NewTarget);
    
    UFUNCTION(BlueprintCallable)
    void OnNotifyCurrentTargetDeath(const FRQDamageInfo& DamageInfo);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnEndTimerFootstep();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnCommonAIDataAssetLoaded();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintUpdateState(EAIState NewState, bool bIsStart);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintUnactivate();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintHitAnimation(EDirection Direction);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    float OnBlueprintGetPitchAIM() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool OnBlueprintGetIsMortar() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool OnBlueprintGetIsInBeamState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool OnBlueprintGetHeadbonkProtection() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintActivate();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSetNetworkedTarget(AActor* NewTarget);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSetCollisionEnabled(bool bIsEnabled);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastLockAim(bool NewLockAim);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastActivateWithSpawnEffect();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool IsWorkerInTurboMode();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool IsPodInAAState();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool IsPodBurrowed();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsClassicEnemy() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBoss() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool IsBoomNestCurrentlySpawning();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBig() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void InitializeEyePatchMaterial(UStaticMeshComponent* InMesh);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetYawAIMToLocation(const FVector& TargetLocation, float& OutTargetYawAIM) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetYawAIMDifference() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetYawAIM();
    
    UFUNCTION(BlueprintCallable)
    FTargetInfo GetVisibilityInfoOnTarget(AActor* Target);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<ETeam> GetTargetsTeam() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AActor*> GetTargetsArround() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetTargetNavLocationFLyingOffset();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSummonTimeRemaining() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPitchAIMToLocation(const FVector& TargetLocation) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPitchAIM();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACharacter_Player* GetLocalPlayerRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAPlayerController* GetLocalPlayerControllerRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHitBlend() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UAnimMontage* GetHitAnimation(const FRQDamageInfo& DamageInfo) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLinearColor GetFXColor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FVector GetCustomVelocity();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCustomFloatValue(FName PropertyName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTargetInfo GetCurrentTargetInfo();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetCurrentTarget() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UACompassLocator* GetCompassLocator();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLinearColor GetCableColor();
    
    UFUNCTION(BlueprintCallable)
    void ForceActivation(bool bActivate);
    
    UFUNCTION(BlueprintCallable)
    void ExtractDatatable(UDataTable* DataTable, UAStatManager* InStatManager);
    
    UFUNCTION(BlueprintCallable)
    void DisableHealthBar();
    
    UFUNCTION(BlueprintCallable)
    void CheckVisibilityOnTargets();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanProcessTurnRotation();
    
    UFUNCTION(BlueprintCallable)
    void AddSummonDuration(float AddDuration);
    
    UFUNCTION(BlueprintCallable)
    void AddCustomFloatValue(FName PropertyName, float Value);
    

    // Fix for true pure virtual functions not being implemented
};

