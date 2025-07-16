#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "ClientDamageInfo.h"
#include "DelayRetriggerArea.h"
#include "DelegateCancelDelegate.h"
#include "DelegateOnProjectileDeathDelegate.h"
#include "DelegateOnTriggerEndResultDelegate.h"
#include "DelegateOnTriggerKillDelegate.h"
#include "DelegatePostUsedDelegate.h"
#include "DelegateStartBehaviorDelegate.h"
#include "DelegateTagUpdateDelegate.h"
#include "DelegateTriggerAreaEffectDelegate.h"
#include "DelegateUpdateCooldownRatioDelegate.h"
#include "DelegateUsedDelegate.h"
#include "EAOEType.h"
#include "EAction.h"
#include "EAreaDecalMaterialTypes.h"
#include "EDamageType.h"
#include "EDamageTypeGameplay.h"
#include "EElement.h"
#include "EGameplayTags.h"
#include "EHitType.h"
#include "EInputRecordType.h"
#include "EKillRagdollType.h"
#include "EProjectileTriggerType.h"
#include "ESettingsQuality.h"
#include "ESkillBehavior.h"
#include "ESkillImpactDecalTypes.h"
#include "ESkillMuzzleType.h"
#include "ESpawnPosition.h"
#include "EStat.h"
#include "EStatus.h"
#include "ETeam.h"
#include "IStatManager.h"
#include "NetworkSkillInfo.h"
#include "NetworkSkillValues.h"
#include "ParticleSystemComponentsPoolArray.h"
#include "PendingInitProjectile.h"
#include "PlayerSkillRow.h"
#include "RQDamageInfo.h"
#include "StatValues.h"
#include "SurfaceSoundAndFx.h"
#include "Templates/SubclassOf.h"
#include "ASkill.generated.h"

class AACharacter;
class AAProjectile;
class AActor;
class UASkill;
class UAStatManager;
class UAudioComponent;
class UCurveFloat;
class UDataTable;
class UHitDecalComponent;
class UMaterialInterface;
class UModifier_Damage;
class UModifier_Stat;
class UParticleSystem;
class UParticleSystemComponent;
class USkeletalMeshComponent;
class USoundCue;
class UStaticMesh;
class UTexture2D;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROBOQUEST_API UASkill : public UActorComponent, public IIStatManager {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    EAction TargetAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInputRecordType RecordType;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateCancel DelegateCancel;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateUsed DelegateUsed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateStartBehavior DelegateStartBehavior;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegatePostUsed DelegatePostUsed;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_PlayerSkills;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_EnemySkill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_AllySkill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_ModSkills;
    
public:
    UPROPERTY(BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateTagUpdate DelegateTagUpdate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModifier_Stat* ModifierWarmupFirerate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBaseAreaOfEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAreaOfEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanTriggerRocketJump;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HealthPickupOnMeleeHitBossModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GameplayTags;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBeamFire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AACharacter* CharacterOwner;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpeedRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModifier_Stat* ModifierSpeedRatio;
    
private:
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsInitialized;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsPressed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsUsed;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRecoverCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoRecoverCooldown;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CooldownSpeedRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCustomStack;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentDuration;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateUpdateCooldownRatio DelegateUpdateCooldownRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHitType HitType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHitType BaseHitType;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnTriggerEndResult DelegateOnTriggerEndResult;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMultiHitLinked;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNoCollisionProjectile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 RaycastBounceAmount;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<AActor*, float> MultiHitTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<AActor*, FRQDamageInfo> MultiHitDamageInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<AActor*, FRQDamageInfo> MultiRaycastHitDamageInfo;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Range;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RangeRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RicochetAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RicochetDamageRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TargetTeams;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AAProjectile> ProjectileClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* ProjectileMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* BaseProjectileMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform ProjectileMeshRelativeTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform BaseProjectileMeshRelativeTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* ProjectileFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* BaseProjectileFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform ProjectileFXRelativeTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform BaseProjectileFXRelativeTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* TrailFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* BaseTrailFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* EndProjectileFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform ProjectileTrailRelativeTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform BaseProjectileTrailRelativeTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* ProjectileTravelSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectileSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseProjectileSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 ProjectileBounceAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* ProjectileTickSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* ProjectileBounceSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* ProjectileBounceFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTriggerAreaOnBounce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectileBounciness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectileFriction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectileGravityScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseProjectileGravityScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTickProjectile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TickProjectileRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TickProjectileFirerate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStickingProjectile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EProjectileTriggerType ProjectileTriggerType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectileTriggerTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectileTriggerRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bProjectileInstantCalculateRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHomingProjectile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HomingDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HomingRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HomingAccelerationMagnitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HomingDotTolerance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectileLifetime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ProjectileScale;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectileCollisionSize;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnProjectileDeath DelegateOnProjectileDeath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FPendingInitProjectile> PendingInitializationProjectiles;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESpawnPosition AreaSpawnPosition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConeAngle;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SphereRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector BoxSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector BaseBoxSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConeLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCustomTargetArea;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAOEType AreaType;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateTriggerAreaEffect DelegateTriggerAreaEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDelayRetriggerArea> RetriggeredAreas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelayRetriggerArea CurrentRetriggeredArea;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowHomingIfBouncing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModifier_Stat* CriticalModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModifier_Stat* AssaultModifier;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveFallOffDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveFallOffImpactForce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveAreaBoneFallOff;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnTriggerKill DelegateOnTriggerKill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DotDamageRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoCritical;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FriendlyDamage;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UModifier_Damage*> DamageModifiers;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IceRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShockRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<EStatus> AppliedStatus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<EStatus> SelfAppliedStatus;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector2D> SpawnLocationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector2D> SpawnRotationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector2D> BaseSpawnRotationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpreadPatternWithUseAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpreadPatternWithMuzzleIndex;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D Spread;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 RandomSeed;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkillMuzzleType MuzzleType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> MuzzleIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentMuzzle;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> DeactivateIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor SkillColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDamageType DamageType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EKillRagdollType RagdollType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SuperFeedbackAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MegaFeedbackAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisplayOnlyFirstHitEvent;
    
private:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSurfaceSoundAndFx SoundsAndFXBySurface[63];
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkillBehavior Type;
    
private:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystem* DeathFxByDamageType[10];
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystem* ExplosionByElement[3];
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystem* TrailByElement[3];
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystem* ProjectileParticleByElement[3];
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystem* ProjectileTrailByElement[3];
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystem* BashByElement[3];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<UHitDecalComponent*, FVector> HitDecals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<UParticleSystemComponent*, UParticleSystem*> SurfaceHitFxComponents;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<EElement> MuzzleElementOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<EElement> TrailElementOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<EElement> HitElementOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<EElement> ProjectileElementTrailOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<EElement> ExplosionElementOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTriggerSurfaceEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* MuzzleFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseMuzzleFXScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MuzzleFXScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* BaseHitFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* BaseDeathHitFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* HitFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HitFXScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* DeathHitFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* DeathNoHitFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* RaycastTrailFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* BaseRaycastTrailFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> RaycastTrailEmiterBeamIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* BaseAreaOfEffectFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* AreaOfEffectFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* AreaOfEffectHitFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAreaDecalMaterialTypes AreaDecalType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AreaDecalFadeDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkillImpactDecalTypes ImpactDecalType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DecalSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* ImpactHitFxComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESettingsQuality EffectQuality;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<EElement> ProjectileElementOrder;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreElementalProjectileFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* UseSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLoopSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* LoopSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* HapticLoopSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* StopSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* CancelSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* AreaOfEffectSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* BaseHitSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* HitSound;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* CurrentUseSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* LoopingSoundComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* LoopingHapticSoundComponent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInterface* HoloMeshMaterial;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsIgnoredByBarrier;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InitialParticleSystemPoolCount[8];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxParticleSystemPoolCount[8];
    
private:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FParticleSystemComponentsPoolArray ParticleSystemComponentsPool[8];
    
public:
    UASkill(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void UseSkill();
    
protected:
    UFUNCTION(BlueprintCallable)
    void UpdateSpeedRatio(float NewSpeedRatio);
    
public:
    UFUNCTION(BlueprintCallable)
    void UnregisterHitDecal(UHitDecalComponent* DecalComp);
    
protected:
    UFUNCTION(BlueprintCallable)
    void StartCooldownDelay();
    
    UFUNCTION(BlueprintCallable)
    void SpawnProjectiles(const FNetworkSkillInfo& NetworkInfo, const FNetworkSkillValues& NetworkSkillValues, float Speed, float GravityScale);
    
    UFUNCTION(BlueprintCallable)
    TArray<AAProjectile*> SpawnCustomProjectiles(const TArray<FNetworkSkillInfo>& NetworkInfos, float Speed, float GravityScale, FName CustomTag);
    
public:
    UFUNCTION(BlueprintCallable)
    void SimulateTriggerAreaEffect(const FNetworkSkillInfo& NetworkInfo, AAProjectile* Projectile);
    
    UFUNCTION(BlueprintCallable)
    void SimulateReleased();
    
    UFUNCTION(BlueprintCallable)
    void SimulatePressed();
    
    UFUNCTION(BlueprintCallable)
    void SimulateCancel();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetSkillEnable(bool bNewEnable);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetAreaSoundParameter(UAudioComponent* InSound, AAProjectile* Projectile);
    
protected:
    UFUNCTION(BlueprintCallable)
    void ResetSkillRow();
    
    UFUNCTION(BlueprintCallable)
    void ResetProjectileClass();
    
public:
    UFUNCTION(BlueprintCallable)
    void ResetCooldown();
    
    UFUNCTION(BlueprintCallable)
    void RemoveSuperTextFeedback();
    
    UFUNCTION(BlueprintCallable)
    void RemoveShockTag();
    
    UFUNCTION(BlueprintCallable)
    void RemovePierceState();
    
    UFUNCTION(BlueprintCallable)
    void RemoveMegaTextFeedback();
    
protected:
    UFUNCTION(BlueprintCallable)
    void RemoveImpactForceState();
    
public:
    UFUNCTION(BlueprintCallable)
    void RemoveIceTag();
    
    UFUNCTION(BlueprintCallable)
    void RemoveGameplayTag(EGameplayTags Tag);
    
    UFUNCTION(BlueprintCallable)
    void RemoveExplosiveTag();
    
    UFUNCTION(BlueprintCallable)
    void RemoveDamageModifier(UModifier_Damage* Modifier);
    
    UFUNCTION(BlueprintCallable)
    void RemoveBurnTag();
    
    UFUNCTION(BlueprintCallable)
    void RemoveBounceState();
    
    UFUNCTION(BlueprintCallable)
    void ReduceCooldown(float ReduceTime);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnTriggerTarget(const FRQDamageInfo& DamageInfo);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnTriggerSkillCustomEffect(FNetworkSkillInfo NetworkInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnTriggerPostSkillCustomEffect(FNetworkSkillInfo NetworkInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnTriggerKill(const FRQDamageInfo& DamageInfo);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSurfaceHitFxComponentFinished(UParticleSystemComponent* PSystem);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSpawnProjectile(AAProjectile* InProjectile, const FNetworkSkillInfo& NetworkInfo, const FNetworkSkillValues& NetworkSkillValues, float Speed, float GravityScale, FName CustomTag, int32 ProjectileIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnSpawnMuzzleFX(UParticleSystemComponent* NewMuzzleFX);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSkillEndInitialization();
    
private:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerCancelSkill();
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerApplyDamages(const TArray<FClientDamageInfo>& DamageInfos);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerApplyDamage(const FClientDamageInfo& DamageInfo);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnProjectileTick(AAProjectile* Projectile);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnProjectileStartOverlap(const FHitResult& HitResult, AAProjectile* Projectile);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnProjectileSpawnCustomEffect(const TArray<AAProjectile*>& Projectiles);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnProjectileRicochet(AActor* TargetCharacter, AAProjectile* Projectile);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnProjectileEndLife(AAProjectile* Projectile);
    
private:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastCancelSkill();
    
protected:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastApplyDamages(const TArray<FClientDamageInfo>& DamageInfos);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastApplyDamage(const FClientDamageInfo& DamageInfo);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnGameStateDestroyed(AActor* Actor);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnDealCustomDamage(FHitResult HitResult, AAProjectile* Projectile);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnCommonSkillDataAssetLoaded();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintUpdateCharacterOwner();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintStartBehavior();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSpawnMuzzleFX(UParticleSystemComponent* InMuzzleFX);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintDealDamage(FClientDamageInfo DamageInfo);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool OnBlueprintCanUseSkill();
    
protected:
    UFUNCTION(BlueprintCallable)
    void MulticastUseSkill(const FNetworkSkillInfo& NetworkInfo);
    
    UFUNCTION(BlueprintCallable)
    void LoadFXAndSounds();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocallyControlled() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAvailable();
    
    UFUNCTION(BlueprintCallable)
    void InitShockTag(float InElemntalRatio);
    
    UFUNCTION(BlueprintCallable)
    void InitPierceState(int32 NewPierceAmount);
    
protected:
    UFUNCTION(BlueprintCallable)
    void InitImpactForceState(float DamageRatio);
    
public:
    UFUNCTION(BlueprintCallable)
    void InitIceTag(float InElemntalRatio);
    
    UFUNCTION(BlueprintCallable)
    void InitializeProjectilesFromQueue();
    
    UFUNCTION(BlueprintCallable)
    void InitExplosiveTag(float Radius, UParticleSystem* AreaFX, USoundCue* AreaSound, bool bPermanent, bool bDecal);
    
    UFUNCTION(BlueprintCallable)
    void InitBurnTag(float BurnRatio);
    
    UFUNCTION(BlueprintCallable)
    void InitBounceState(int32 NewBounceAmount, float NewBounciness, float NewFriction);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    USoundCue* GetUseSound();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetStartTrace(int32 Index) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetSpread();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSphereRadius(const FNetworkSkillInfo& SKillInfo) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    TArray<FVector2D> GetSpawnRotationOffset() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    TArray<FVector2D> GetSpawnLocationOffset() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSeededRandomRange(int32 Min, int32 Max);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRange() const;
    
private:
    UFUNCTION(BlueprintCallable)
    FVector2D GetRandomPointInElipse(FVector2D InSpread);
    
    UFUNCTION(BlueprintCallable)
    FVector2D GetRandomPointInCircle(float Radius);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetProjectileSpeed(const FNetworkSkillInfo& SKillInfo) const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FHitResult GetProjectileEndHitResult(const FVector& StartTrace, const FVector& Velocity, float GravityScale, float MaxSimeTime) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPlayerOrModSkillRowFromSoftClass(const TSoftClassPtr<UASkill>& SkillClass, FPlayerSkillRow& OutPlayerSkill) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPlayerOrModSkillRowFromRowName(const FName& RowName, FPlayerSkillRow& OutPlayerSkill) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPlayerOrModSkillRowFromClass(const TSubclassOf<UASkill>& SkillClass, FPlayerSkillRow& OutPlayerSkill) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPlayerOrModSkillRow(FPlayerSkillRow& OutPlayerSkill) const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetMuzzleLocation(int32 Index) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    TArray<int32> GetMuzzleIndex() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USkeletalMeshComponent* GetMuzzleComponent() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMaxTarget() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMaxHitAmount(AAProjectile* Projectile);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAudioComponent* GetLoopingSoundComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetImpactForceAmount(float ChargeRatio);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TArray<AActor*> GetIgnoredActors() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    int32 GetHitAmount(float ChargeRatio) const;
    
protected:
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<EGameplayTags> GetGameplayTagList();
    
protected:
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FVector GetForwardVector(int32 Index) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetDurationDelay();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<EDamageTypeGameplay> GetDamageTypeGameplay(bool bBase);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetDamageAmount(float ChargeRatio);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCustomFloatProperties(FName PropertyName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCooldownRatio();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetConeLength(const FNetworkSkillInfo& SKillInfo) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetConeAngle();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AACharacter* GetCharacter() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCalculateFirerate() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCalculateBaseImpactForce() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCalculateBaseDamage() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetBoxSize(const FNetworkSkillInfo& SKillInfo) const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetBaseImpactForceAmount(float ChargeRatio);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<EGameplayTags> GetBaseGameplayTagList();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetBaseDamageAmount(float ChargeRatio);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetAreaStartTrace(const FNetworkSkillInfo& SKillInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TSet<EStatus> GetAppliedStatus(int32 InGameplayTags);
    
    UFUNCTION(BlueprintCallable)
    void DelayRetriggerAreaEffect(const FNetworkSkillInfo& SKillInfo, float Delay, float DamageModifier, float RadiusModifier, AAProjectile* Projectile);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanUseSkill();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanCritical(AAProjectile* Projectile);
    
public:
    UFUNCTION(BlueprintCallable)
    void ApplyDamageModifier(UModifier_Damage* NewModifier);
    
    UFUNCTION(BlueprintCallable)
    void AddSuperTextFeedback();
    
    UFUNCTION(BlueprintCallable)
    void AddNewTargetTeam(ETeam Team);
    
    UFUNCTION(BlueprintCallable)
    void AddNewGameplayTag(EGameplayTags Tag);
    
    UFUNCTION(BlueprintCallable)
    void AddMegaTextFeedback();
    
    UFUNCTION(BlueprintCallable)
    void AddCustomFloatProperties(FName PropertyName, float AddValue);
    

    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    bool RestoreStat(EStat enumStat, float Modifier) override PURE_VIRTUAL(RestoreStat, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool ReduceStat(EStat enumStat, float Modifier) override PURE_VIRTUAL(ReduceStat, return false;);
    
    UFUNCTION()
    void OnNotifyStatFull(EStat enumStat) override PURE_VIRTUAL(OnNotifyStatFull,);
    
    UFUNCTION()
    void OnNotifyStatEmpty(EStat enumStat) override PURE_VIRTUAL(OnNotifyStatEmpty,);
    
    UFUNCTION()
    void OnNotifyStat(EStat enumStat, float curVal, float Value) override PURE_VIRTUAL(OnNotifyStat,);
    
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

