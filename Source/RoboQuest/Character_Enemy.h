#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "Character_AI.h"
#include "EDamageType.h"
#include "EElement.h"
#include "EEnemyType.h"
#include "IFocusable.h"
#include "PatternData.h"
#include "RQDamageInfo.h"
#include "RQHitResult.h"
#include "SurfaceSoundAndFx.h"
#include "Character_Enemy.generated.h"

class AACharacter;
class AActor;
class ACharacter_Enemy;
class ACharacter_Player;
class UAnimMontage;
class UAudioComponent;
class UCurveFloat;
class UHitDecalComponent;
class UMaterialInterface;
class UModifier_Stat;
class UParticleSystem;
class UPhysicsAsset;
class USoundCue;
class UTexture2D;

UCLASS(Blueprintable)
class ROBOQUEST_API ACharacter_Enemy : public ACharacter_AI, public IIFocusable {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateSetBeamState, bool, bNewState);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnStartBeam);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnPreTriggerLoots, const TArray<AActor*>&, Loots);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnEndInitialization, ACharacter_Enemy*, Enemy);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnEndHook, ACharacter_Player*, PlayerRef, bool, bError);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnEndBeam);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateLeashState, bool, Leash);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateDangerState, bool, bDangerState);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 SpawnParameters;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSurfaceSoundAndFx DeathSoundsAndFX;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Cells;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Wrench;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreForReinforcements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreForWeaponAndTicketLoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemyType EnemyType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UModifier_Stat*> LevelModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UModifier_Stat*> MultiModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableLoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ACharacter_Player* AutoLootPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> Loots;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FocusDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UnfocusDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FocusCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFocusState;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveStunRegeneration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveImpactRegeneration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveIceRegeneration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UHitDecalComponent*> DecalHitCompenents;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bImpactInvulnerability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StaggerDuration;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* StunAnimation;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ACharacter_Player* AttachedPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* LeashMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveLeash;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ACharacter_Player* HookedPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HookSpeed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnEndHook DelegateOnEndHook;
    
public:
    UPROPERTY(BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateSetBeamState DelegateSetBeamState;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnEndBeam DelegateOnEndBeam;
    
    UPROPERTY(BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnEndBeam DelegateOnStartBeam;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* BecameProjectileSoundLoaded;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanBecomeProjectile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTickBecameProjectile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ProjectileForward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectileCurrentTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundCue> BecameProjectileSound;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystem* PlateDestructionFX;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<AACharacter*, float> DamagingCharacters;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<EElement> ElementalResistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UPhysicsAsset* BasePhysicsAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UPhysicsAsset* PhysicsAssetOnDeath;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystem* DashVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* DashSFX;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanDash;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UParticleSystem> DashVFXSoftPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundCue> DashSFXSoftPtr;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform InitialTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FPatternData> PatternData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UModifier_Stat*> EliteModifiers;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveBossStunRegeneration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveBossImpactRegeneration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveBossIceRegeneration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* BossDeathSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* BossDeathHapticSound;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsEnrage;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateDangerState DelegateDangerState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> BigQuestIconOn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> BigQuestIconOff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 EncounterID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 AreaID;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanUpdateShieldCasterPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* ShieldInstigator;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModifier_Stat* DifficultyHealthModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModifier_Stat* DifficultyImpactModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModifier_Stat* DifficultyDamageModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DifficultySpeedModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModifier_Stat* ActHealthModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModifier_Stat* ActImpactModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModifier_Stat* ActDamageModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BotMinUpdateRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BotMaxUpdateRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsBot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsShieldBot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AACharacter>> ExcludedClassesForShields;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundCue> BuffSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* BuffSoundLoaded;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacter_Enemy* ShieldedAlly;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsBuffFly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AACharacter>> ExcludedClassesForBuff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundCue> StartBuffFlySound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundCue> LoopBuffFlySound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundCue> StopBuffFlySound;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* StartBuffFlySoundLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* StopBuffFlySoundLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* LoopBuffFlySoundComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacter_Enemy* MoveToAlly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacter_Enemy* CurrentBuffedAlly;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKeepMapLocatorWhenIdled;
    
    ACharacter_Enemy(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
    UFUNCTION(BlueprintCallable)
    void UnregisterHitDecalComponent(UHitDecalComponent* DecalComp);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UnbuffAlly(ACharacter_Enemy* EnemyRef);
    
private:
    UFUNCTION(BlueprintCallable)
    void TryFindAllyToShield();
    
public:
    UFUNCTION(BlueprintCallable)
    void StopHookPlayer();
    
protected:
    UFUNCTION(BlueprintCallable)
    void StopBeProjectile();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldExplodeOnDeath() const;
    
private:
    UFUNCTION(BlueprintCallable)
    void SetSlowState(bool bNewState);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetHealthBarVisibility(bool bVisible);
    
private:
    UFUNCTION(BlueprintCallable)
    void SetFrozenState(bool bNewState);
    
    UFUNCTION(BlueprintCallable)
    void SetEnergizeState(bool bNewState);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetBuffedAlly(ACharacter_Enemy* AllyRef);
    
    UFUNCTION(BlueprintCallable)
    void ResetDeathSFX();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void RemoveHeadbonkProtection();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void RemoveEyeProtection();
    
    UFUNCTION(BlueprintCallable)
    void RemoveElementalResistance();
    
private:
    UFUNCTION(BlueprintCallable)
    void PlayDeathSFX(EDamageType DeathDamageType);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlayDashVFX(float DashDuration);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlayDashSFX();
    
public:
    UFUNCTION(BlueprintCallable)
    void OverrideDeathsFX(USoundCue* NewSound, UParticleSystem* NewFX);
    
    UFUNCTION(BlueprintCallable)
    void OnRepBuffedAllyInternal(ACharacter_Enemy* BuffedAlly);
    
protected:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastBoneDestroyed(FName BoneName);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnEndHookPlayer(bool bError);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnDetachPlayer();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnCommonEnemyDataAssetLoaded();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnBuffedAllyDeath(const FRQDamageInfo& DamageInfo);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBoneDestroyed(FName BoneName);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintTriggerRegularDeath();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintTriggerElementalDeath(EDamageType DamageType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintStopShieldAlly();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintJumpedByPlayer(ACharacter_Player* PlayerRef);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintDeactivateWorker();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintApplyHeadbonkDamage(ACharacter_Player* PlayerRef);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintActivateWorker();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintActivateShield();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnAttachPlayer(ACharacter_Player* InPlayer);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnAlerted(AActor* TargetActor);
    
private:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastStartStateStun(AACharacter* StunInstigator);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastStartStateStagger(float NewApplyImpactForce, AACharacter* DamageInstigator);
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastStartStateIce(AACharacter* IceInstigator);
    
protected:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastStartHookPlayer(ACharacter_Player* InPlayer);
    
private:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastShieldAlly(ACharacter_Enemy* NewShieldedAlly);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSetMoveToAlly(ACharacter_Enemy* NewAlly);
    
protected:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastEndBecameProjectile();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastDetachPlayer();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void MulticastBecameProjectile();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastAttachPlayer(ACharacter_Player* InPlayer);
    
public:
    UFUNCTION(BlueprintCallable)
    void LootMaxHealthPickup(int32 Amount, bool bAutoGather);
    
    UFUNCTION(BlueprintCallable)
    void LootHealthPickup(int32 Amount, bool bAutoGather);
    
private:
    UFUNCTION(BlueprintCallable)
    void LoopShieldDistance();
    
protected:
    UFUNCTION(BlueprintCallable)
    void LoadDashVFX(bool bPlayEventAfterLoading, float DashDuration);
    
    UFUNCTION(BlueprintCallable)
    void LoadDashSFX(bool bPlayEventAfterLoading);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsValidAllyToBuff(ACharacter_Enemy* EnemyRef) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTurretEmpowered() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsElite() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAlwaysShielded() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasHeadbonkBubble() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasEyeProtection() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GrantXP() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UAnimMontage* GetStunAnimation() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UAnimMontage* GetStaggerAnimation(FRQDamageInfo DamageInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAnimMontage* GetPatternDeathAnimation(const FName& Pattern);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetLevel() const;
    
protected:
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetImpactResistanceMultiplayerScale();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetHealthMultiplayerScale();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    float GetFocusDistance() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetEnemyBaseTimeDilatation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetEncounterID() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<ACharacter_Enemy*> GetCharactersInSquad();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    ACharacter_Enemy* GetBuffedAlly() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetAreaID() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ContainBones(const TArray<FRQHitResult>& Results, const FName& BoneName) const;
    
    UFUNCTION(BlueprintCallable)
    void ClearLoots();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanTriggerFocus();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanLoot() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool CanBeJumped();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BuffAlly(ACharacter_Enemy* EnemyRef);
    
    UFUNCTION(BlueprintCallable)
    void ApplyStunImpact(float ImpactForce, AACharacter* DamageInstigator);
    
    UFUNCTION(BlueprintCallable)
    void ApplyImpactForce(float ImpactForce, AACharacter* DamageInstigator);
    
    UFUNCTION(BlueprintCallable)
    void ApplyIceImpact(float ImpactForce, AACharacter* DamageInstigator);
    
    UFUNCTION(BlueprintCallable)
    void ApplyFocusCooldown();
    
private:
    UFUNCTION(BlueprintCallable)
    void ApplyDestructibleBoneDamage(FName BoneName, float DamageAmount);
    
public:
    UFUNCTION(BlueprintCallable)
    void AddNewLoot(AActor* Loot);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void AddHeadbonkProtection();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void AddEyeProtection();
    

    // Fix for true pure virtual functions not being implemented
};

