#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Character -FallbackName=Character
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ECollisionChannel -FallbackName=ECollisionChannel
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "DifficultyRow.h"
#include "EAction.h"
#include "EDirection.h"
#include "EDot.h"
#include "EGameplayTags.h"
#include "EStat.h"
#include "EStatus.h"
#include "ETrapType.h"
#include "GlobalModifier.h"
#include "IDamageable.h"
#include "IGrappable.h"
#include "ISkillManager.h"
#include "IStatManager.h"
#include "RQDamageInfo.h"
#include "RQHitResult.h"
#include "StatValues.h"
#include "StatusSound.h"
#include "Templates/SubclassOf.h"
#include "ACharacter.generated.h"

class AACharacter;
class AAProjectile;
class AATile;
class AActor;
class ACharacter_AI;
class UASkill;
class UASkillManager;
class UAStatManager;
class UAudioComponent;
class UCurveFloat;
class UModifier_Damage;
class UModifier_Stat;
class UParticleSystemComponent;
class UPrimitiveComponent;
class USceneComponent;
class USkeletalMeshComponent;
class USoundCue;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AACharacter : public ACharacter, public IISkillManager, public IIStatManager, public IIDamageable, public IIGrappable {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateShieldDamageReduction, float, NewShieldDamageReduction);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnUpdateCurrentTile, AATile*, LastTile, AATile*, NewTile);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDelegateOnTriggerEndResult, UASkill*, Skill, FRQHitResult, RQHitResult, AAProjectile*, Projectile);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnTargetable, bool, bIsTargetable, AActor*, NewTarget);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FDelegateOnTakeDamageNetworked, float, DamageAmount, float, ImpactForceAmount, AACharacter*, DamageInstigator, int32, GameplayTags, float, IceRatio, float, ShockRatio);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnTakeDamage, const FRQDamageInfo&, DamageInfo);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnStaggerSomeone, AACharacter*, Target, const FRQDamageInfo&, InLastDamageInfo);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnSpawnSomething, AActor*, SpawnedActor, bool, bIsStart);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnSpawnSomeone, ACharacter_AI*, SpawnedCharacter, bool, bIsStart);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnPostDealDamage, AACharacter*, DamagedCharacter, int32, GameplayTags);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnKill, FRQDamageInfo, DamageInfo);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnHitSomewhere, FVector, Location, UASkill*, Skill);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnDodgeDamage, FRQDamageInfo, DamageInfo);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDelegateOnDispatchStatus, EStatus, Status, bool, bIsStart, float, Duration);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnDeath, const FRQDamageInfo&, DamageInfo);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnDealDamage, const FRQDamageInfo&, DamageInfo);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDelegateOnApplyStatusToSomeone, EStatus, Status, AActor*, Target, bool, bIsApply);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateInvulnerable, bool, bIsInvulnerable);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateEndInitialization, AACharacter*, CharacterRef);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FGlobalModifier GlobalModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isInitialized;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnDeath DelegateOnDeath;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnDispatchStatus DelegateOnDispatchStatus;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnTakeDamage DelegateOnTakeDamage;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnDealDamage DelegateOnDealDamage;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnPostDealDamage DelegateOnPostDealDamage;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnKill DelegateOnKill;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateEndInitialization DelegateEndInitialization;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnTriggerEndResult DelegateOnTriggerEndResult;
    
    UPROPERTY(BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnTargetable DelegateOnTargetable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsTargetable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UASkillManager* SkillManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AATile* CurrentTile;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnUpdateCurrentTile DelegateOnUpdateCurrentTile;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnSpawnSomeone DelegateOnSpawnSomeone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ACharacter_AI*> SpawnedCharacters;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<EStatus, AActor*> StatusInstigators;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldBeDead;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRQDamageInfo LastDamageInfo;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShieldDamageReduction;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateShieldDamageReduction DelegateShieldDamageReduction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IceRatioModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShockRatioModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanStun;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IceDurationRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShockDurationRatio;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnApplyStatusToSomeone DelegateOnApplyStatusToSomeone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<EStatus> StatusList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsDead;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLocalDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ETrapType, float> TrapTypesDamageReduction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<EDot> IgnoredDots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIceAutoCritical;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnTakeDamageNetworked DelegateOnTakeDamageNetworked;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FStatusSound StatusSound[19];
    
    UPROPERTY(EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* StatusAudioComponent[19];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<EStatus> StatusProtection;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    float StatusResistanceDuration[19];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EStatus, float> CurrentStatusResistanceDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ACharacter_AI*> TokenPriorities;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateInvulnerable DelegateInvulnerable;
    
protected:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float ActorDynamicLoadingRangeSquared[2];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float TemporaryNearStateDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveImpactForceVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveImpactForceImpulse;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bComputeIKWhenMoving;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IKMinUpdateRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IKMaxUpdateRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName IKLeftFootSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRotator IKLeftFootRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float IKLeftFootOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName IKRightFootSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRotator IKRightFootRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float IKRightFootOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IKFeetRaycastLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IKFeetInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECollisionChannel> IKFeetCollisionChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float IKHipsOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IKHipsInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InitialParticleSystemPoolCount;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UParticleSystemComponent*> ParticleSystemComponentsPool;    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool bAutoRegisterToGameState;
    
private:
    UPROPERTY(EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int64 CreationTime;
    
public:
    AACharacter(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void StoreMonitoringTimer(const FString& Context, bool bPrint);
    
    UFUNCTION(BlueprintCallable)
    void SpawnStatusLoopingParticle(EStatus Status, const FName& SocketName, float InStatusRadius);
    
    UFUNCTION(BlueprintCallable)
    UAudioComponent* SpawnSoundVibration(USoundCue* BaseSoundRef, float Intensity, bool bAttached, bool bAutoDestroy);
    
    UFUNCTION(BlueprintCallable)
    UAudioComponent* SpawnSoundAttached(USceneComponent* Root, USoundCue* Sound, const FVector& Location, bool bWeaponSound, float BaseVolumeMultiplier, bool bMono, bool bAutoDestroy);
    
    UFUNCTION(BlueprintCallable)
    UAudioComponent* SpawnSoundAtLocation(USoundCue* Sound, const FVector& Location, bool bWeaponSound, float BaseVolumeMultiplier, bool bMono);
    
    UFUNCTION(BlueprintCallable)
    void SetTargetable(bool IsTargetable, AActor* NewTarget);
    
    UFUNCTION(BlueprintCallable)
    void SetShieldDamageReduction(float NewShieldDamageReduction);
    
    UFUNCTION(BlueprintCallable)
    void SetNewDifficulty(const FName& DifficultyRowName, const FDifficultyRow& Difficulty);
    
    UFUNCTION(BlueprintCallable)
    void SetInvulnerability(bool bNewInvulnerable);
    
    UFUNCTION(BlueprintCallable)
    void RemoveGlobalSuperFeedback();
    
    UFUNCTION(BlueprintCallable)
    void RemoveGlobalStatModifier(UModifier_Stat* StatModifier);
    
    UFUNCTION(BlueprintCallable)
    void RemoveGlobalDamageModifier(UModifier_Damage* DamageModifier);
    
    UFUNCTION(BlueprintCallable)
    void RemoveAllStatus();
    
    UFUNCTION(BlueprintCallable)
    UAudioComponent* PlaySoundVibration(USoundCue* BaseSoundRef, float Intensity);
    
    UFUNCTION(BlueprintCallable)
    void PlaySoundAtLocation(USoundCue* Sound, const FVector& Location, bool bWeaponSound, float BaseVolumeMultiplier, bool bMono);
    
    UFUNCTION(BlueprintCallable)
    void OnTriggerDeathInternal(const FRQDamageInfo& DamageInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTakeCustomDamage(float DamageAmount, int32 GameplayTags, AACharacter* DamageInstigator);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerApplyDamage(float DamageAmount, float ImpactForceAmount, AACharacter* DamageInstigator, int32 GameplayTags, float IceRatio, float ShockRatio);
    
    UFUNCTION(BlueprintCallable)
    void OnNotifyStatFull(EStat enumStat);
    
    UFUNCTION(BlueprintCallable)
    void OnNotifyStatEmpty(EStat enumStat);
    
    UFUNCTION(BlueprintCallable)
    void OnNotifyStat(EStat enumStat, float curVal, float Value);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastDeathWithDamageInfo(const FRQDamageInfo& DamageInfo);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastDeath();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastApplyDamage(float DamageAmount, float ImpactForceAmount, AACharacter* DamageInstigator, int32 GameplayTags, float IceRatio, float ShockRatio);
    
    UFUNCTION(BlueprintCallable)
    void OnImpulseBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnImpulseBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnCommonCharacterDataAssetLoaded();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnCharacterDestroyed(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void OnCancelSkill(EAction Action);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintNotifyStat(EStat enumStat, float curVal, float Value);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintEndInitialization();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsValidNavLocation(const FVector& Location, FVector& ProjectedLocationOnNavMesh) const;
    
    UFUNCTION(BlueprintCallable)
    UAudioComponent* GetStatusAudioComponent(EStatus Status);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AACharacter* GetRealDamageInstigator();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRagdollDuration();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetNavLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetMuzzleSocketName(int32 MuzzleIndex) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetMuzzleSocketLocation(int32 MuzzleIndex);
    
protected:
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EDirection GetHitDirection(const FRQDamageInfo& DamageInfo) const;
    
    UFUNCTION(BlueprintCallable)
    FHitResult GetFootRaycast(bool bIgnoreOverlap);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetDisplayName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AATile* GetCurrentTile() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USkeletalMeshComponent* GetCharacterMesh();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetBodyLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    UPrimitiveComponent* GetBodyComponent() const;
    
    UFUNCTION(BlueprintCallable)
    void CancelAllSkill();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void CallServerInitialization();
    
    UFUNCTION(BlueprintCallable)
    void AddGlobalSuperFeedback();
    
    UFUNCTION(BlueprintCallable)
    void AddGlobalStatModifier(UModifier_Stat* StatModifier);
    
    UFUNCTION(BlueprintCallable)
    void AddGlobalDamageModifier(UModifier_Damage* DamageModifier);
    
    UFUNCTION(BlueprintCallable)
    void AddDamageReductionByGameplayTag(float AddDamageReduction, EGameplayTags GameplayTag);
    

    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    void PressedSkill(EAction Action) override PURE_VIRTUAL(PressedSkill,);
    
    UFUNCTION(BlueprintCallable)
    TArray<UASkill*> GetSkills() const override PURE_VIRTUAL(GetSkills, return TArray<UASkill*>(););
    
    UFUNCTION(BlueprintCallable)
    UASkillManager* GetSkillManager() override PURE_VIRTUAL(GetSkillManager, return NULL;);
    
    UFUNCTION(BlueprintCallable)
    UASkill* GetSkillByClass(TSubclassOf<UASkill> SkillClass) override PURE_VIRTUAL(GetSkillByClass, return NULL;);
    
    UFUNCTION(BlueprintCallable)
    UASkill* GetSkill(EAction Action) override PURE_VIRTUAL(GetSkill, return NULL;);
    
    UFUNCTION(BlueprintCallable)
    TArray<UASkill*> GetCurrentSkills() override PURE_VIRTUAL(GetCurrentSkills, return TArray<UASkill*>(););
    
    UFUNCTION(BlueprintCallable)
    bool RestoreStat(EStat enumStat, float Modifier) override PURE_VIRTUAL(RestoreStat, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool ReduceStat(EStat enumStat, float Modifier) override PURE_VIRTUAL(ReduceStat, return false;);
    
    UFUNCTION(BlueprintCallable)
    void MinimiseStat(EStat enumStat) override PURE_VIRTUAL(MinimiseStat,);
    
    UFUNCTION(BlueprintCallable)
    void MaximiseStat(EStat enumStat) override PURE_VIRTUAL(MaximiseStat,);
    
    UFUNCTION(BlueprintCallable)
    bool HaveStat(EStat enumStat) const override PURE_VIRTUAL(HaveStat, return false;);
    
    UFUNCTION(BlueprintCallable)
    float GetStatValue(EStat enumStat) const override PURE_VIRTUAL(GetStatValue, return 0.0f;);
    
    UFUNCTION(BlueprintCallable)
    FStatValues GetStatStruct(EStat enumStat) const override PURE_VIRTUAL(GetStatStruct, return FStatValues{};);
    
    UFUNCTION(BlueprintCallable)
    UAStatManager* GetStatManager() const override PURE_VIRTUAL(GetStatManager, return NULL;);
    
    UFUNCTION(BlueprintCallable)
    float GetStatCurrentValue(EStat enumStat) const override PURE_VIRTUAL(GetStatCurrentValue, return 0.0f;);
    
    UFUNCTION(BlueprintCallable)
    float GetMoveStatValue(float InitialValue) const override PURE_VIRTUAL(GetMoveStatValue, return 0.0f;);
    
};

