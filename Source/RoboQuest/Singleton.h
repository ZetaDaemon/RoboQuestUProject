#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=PrimaryAssetId -FallbackName=PrimaryAssetId
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EEndPlayReason -FallbackName=EEndPlayReason
//CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
//CROSS-MODULE INCLUDE V2: -ModuleName=PhysicsCore -ObjectName=EPhysicalSurface -FallbackName=EPhysicalSurface
#include "BazarItemRowHandle.h"
#include "CasinoFrequency.h"
#include "ControllerICon.h"
#include "DotData.h"
#include "EAnimPose.h"
#include "EAnisotropy.h"
#include "EAntiAlliasing.h"
#include "EAspectRatio.h"
#include "EAutoReloadMode.h"
#include "EBoolean.h"
#include "EBuildType.h"
#include "ECasinoLoot.h"
#include "EColorBlindType.h"
#include "EConsole.h"
#include "EController.h"
#include "ECreditCategory.h"
#include "ECrosshairColor.h"
#include "ECrosshairMode.h"
#include "ECrouchMode.h"
#include "ECustomCost.h"
#include "EDisplayMode.h"
#include "EEnemyGenerationState.h"
#include "EForceTileDirection.h"
#include "EGarryAnimation.h"
#include "EGarryReward.h"
#include "EGraphicQualityPreset.h"
#include "EItemRarity.h"
#include "ELocalization.h"
#include "ERandomLuck.h"
#include "ERandomMeshTag.h"
#include "EScopeMode.h"
#include "ESessionRegion.h"
#include "ESettingsQuality.h"
#include "ESettingsQualityWithOff.h"
#include "ESprintMode.h"
#include "EStat.h"
#include "EStatPrefix.h"
#include "EStatSuffix.h"
#include "EStatus.h"
#include "EStorePlatform.h"
#include "EWeaponAffixParticle.h"
#include "EWeaponAffixRarity.h"
#include "EWeaponColor.h"
#include "EWeaponProcType.h"
#include "GarryReward.h"
#include "GraphicConsole.h"
#include "GraphicQuality.h"
#include "HapticData.h"
#include "IntArray.h"
#include "Keyword.h"
#include "RQDamageInfo.h"
#include "Templates/SubclassOf.h"
#include "Singleton.generated.h"

class AAProjectile;
class AATrap;
class AActor;
class UCurveFloat;
class UEndpointSubmix;
class UMaterialParameterCollection;
class UParticleSystem;
class USoundAttenuation;
class USoundConcurrency;
class UStaticMesh;
class UTexture2D;

UCLASS(Blueprintable)
class ROBOQUEST_API USingleton : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEndpointSubmix* DefaultSubmix;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEndpointSubmix* Haptic_EndPointSubmix;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundAttenuation* Haptic_AttenuationGlobal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundAttenuation* Haptic_AttenuationSpatialized;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundConcurrency* Haptic_Concurrency;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InfiniteRunUnlockWrenchAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CommandoUnlockKillAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SparkFirerate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SparkMultiFirerate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EliteLootTickLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentTargetDistanceRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FlyingTargetLocationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IAShotLocationCapsuleRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IACheckVisibilityDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IASeekingDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IAAlertedDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IAMaxSeekingTimeDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BigMaxSeekingTimeDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayImpactRecovery;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayStunRecovery;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayIceRecovery;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TokenDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* TokenDurationCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebugEnemyVision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VisionRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 VisionAwarness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TurnReactionDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LockHitBlendTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HitBlendRecoverySpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D HitBlendDirectionValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveHitBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthAndResistanceByLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamageByLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ElementalResistanceDamageReduction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D SideRotationValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D BackwardRotationValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxHitBlendOnStunned;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GarryMaxUseAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> GarryPrice;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector2D> GarryRewardLuck;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FGarryReward GarryReward[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGarryAnimation GarryRewardAnimation[15];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BazarBlueprintLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EnchantedAffixPrice;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> CustomCostIcon[2];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 UpgradeWeaponPriceByRarity[5];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WeaponPriceByRarity[5];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RerollAffixPriceByRarity[5];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 UpgradeAffixQualityPriceByRarity[5];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GarryWrenchMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GarryPowercellAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GarryPowercell2Amount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GarryPowercell3Amount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealBotBaseRecoverHealth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealBotBaseRecoverHealthByLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SummonMaxRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor HealthBarColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor HealthBarSubColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundAttenuation* AttenuationFPV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundAttenuation* AttenuationFPVMono;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundAttenuation* AttenuationProjectileImpact;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VolumeMultiplierWeaponTPV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VolumeMultiplierPlayerTPV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnemyFootstepLockDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MusicVolumeMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SafeMusicMaxDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CombatMusicMaxDurationWhenNoEnemies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CombatMusicRetriggerEnemyAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HoldKeyTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InvulnerabilityDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AllyInvulnerabilityDuration;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform WeaponMeshTransformByType[5];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor WeaponProcColor[5];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeaponProcIntensity[5];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeaponLevelDamagePercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeaponModLevelDamagePercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeaponLevelRangePercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WeaponLevelRangeClamp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WeaponLevelMaxStarDisplayed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeaponLevelSummonHealthPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeaponLevelSummonDamagePercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WeaponCollectorTokenAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WeaponChaosCategoryAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WeaponChaosCategoryAmountLootLevel1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTexture2D*> WeaponStarIcons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StealthInvulnerabilityDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StealthBonusMoveSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StealthMaxHeadbonkAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AffixSkillMinimalFirerate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanCriticalInFalloff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float baseCriticalRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxChargeRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxChargeDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* PitchSoundFirerateModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* PitchSoundReloadModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* WarmupFirerateModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WarmupRegenMultiplierWhenReloading;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseSkillDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AAProjectile> BasePlayerProjectileClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AAProjectile> BaseAIProjectileClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectilePoolDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PickupSpawnDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PickupWallOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PickupSpawnHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectileBounceFeedbackDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectileMaxSimTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AIProjectileMaxSimTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HomingBounceRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HomingBounceDotTolerance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bProjectileHomingBounceCorrectForward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectileHomingBounceRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectileHomingBounceDotTolerance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectileHomingBounceAccelerationMagnitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectileBounceCollisionDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectileHomingCollisionDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectileLifetime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectileTrailDisparitionDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ricochetRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseCableGlowIntensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebugSlowProjectile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SlowProjectileRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SlowProjectileDotTolerance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SlowProjectileRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SlowProjectileLerpDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BounceResetTargetDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectileTriggerRangeMaxLifetime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveArcProjectile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebugConfirmAOE;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MultiHitDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MarkDamageModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BossMarkDamageModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TotalDamageRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TotalEnemyDamageRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TotalImpactRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FXTimeDilatation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamageStunRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamageIceRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bScopeGatherPickup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText ScopeDescription;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    float ImpactDamageRatio[7];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScopeChargeDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D ChargedScopeDamageRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnemyJumpDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnemyJumpImpact;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UParticleSystem> WeaponAffixParticle[5];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor WeaponColor[5];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FText WeaponRarityName[5];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxChestCommonItemLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpecialChestCorruptedItemLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBazarItemRowHandle EmptyItemRow;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FBazarItemRowHandle EmptyItemRows[5];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ItemPrice[5];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PingStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PingCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PingDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HitFeedbackLockDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HitFeedbackSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HitFeedbackSoundAutoCriticalPitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HitFeedbackSoundFalloffPitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HitFeedbackSoundFalloffVolumeMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CoolingPerShotFirerateModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoolingEndOverheatAnimationDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoolingRecoverDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoolingRecoverDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoolingRecoverSpeedMultiplierInPocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoolingRecoverSpeedMultiplierWhileCharge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HighCoolingActionDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayStunLockGamepadInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EStat> SpeedStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EStat> InversedModiferStat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D DamageTakenRatioClamp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D MoveSpeedRatioClamp;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    float StatusDuration[19];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FDotData DotData[4];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DotDamageRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FullDotDamageModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SlowDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SlowPlayerRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveIceEnemyRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FullIceEnemyRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveIceBossRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FullIceBossRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveIceEnemyMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MarkBossDurationRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor DamageHealthColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor DamageShieldColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxRaycastLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinRaycastLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpreadClampDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxCameraRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ViewportOffsetY;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> ExperienceByLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* MultiplayerHealthPercentBonus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MultiplayerDamagePercentBonus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* MultiplayerImpactPercentBonus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WorkerMultiplayerHealthPercentBonus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WorkerMultiplayerImpactPercentBonus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MultiplayerTriggerKillHealthPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WorkerTurboRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BossEnrageHealthPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BossEnrageTimeDilatation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BossStunDamagePercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRQDamageInfo BossStunDamageInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BossDamageRatioOnAlly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BossHealthPickupDuringLife;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BossHealthPickupOnDeath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BigHealthPickupOnDeath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WorkerHealthPickupOnDeath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InteractiveStencilValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WeaponMachineWrenchCost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIntArray> LevelUpWeaponWrenchCost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> RerollAffixWrenchCost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveImpactForceDestructible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPrimaryAssetId CommonPlayerDataAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPrimaryAssetId CommonAIDataAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPrimaryAssetId CommonEnemyDataAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPrimaryAssetId CommonCharacterDataAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPrimaryAssetId CommonSkillDataAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPrimaryAssetId CommonAISkillDataAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPrimaryAssetId CommonPlayerSkillDataAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPrimaryAssetId CommonWeaponDataAsset;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor AffixColorByRarity[3];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AffinityUpgradeTriggeredLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> MetaRewardsLevelPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> MetaRewardsLevel;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FGraphicQuality GraphicQualityPreset[6];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FGraphicConsole GraphicQualityConsole[6];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ControllerMenuAxisOffset;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FHapticData HapticPresets[4];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    float HapticMultiplierByPlatform[5];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AccelerationThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* AccelerationCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSlowSensitivityMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* MagnetismPitchCrosshairFOVCorrectionCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MagnetismPitchCrosshairFOVCorrectionWhileScopped;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* MagnetismCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* MagnetismCurveOffsetByDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MagnetismSpeedMultiplierWhenMoving;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MagnetismSpeedMultiplierWhenShooting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDistanceToSelectReinforcementSpawner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReinforcementValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReinforcementActivationInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SafetyArenaValidationHealthPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SafetyArenaValidationDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DontSpawnRangeAroundArenaDoors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PercentChanceToSelectSameEnemyClassAsReinforcement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowIngameRandomization;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EForceTileDirection ForceTileEnteringDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPickRandomTile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bActivateMirrorTile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* MPC_Theme;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemyGenerationState EnemyGenerationState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 AdditionalMultiplayerPack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ELocalization> HiddenLocalizations;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EBoolean LocalizationWarning[19];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText LocalizationWarningMessage;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FText LocalizationControllerType[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FText LocalizationSessionRegion[7];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FText LocalizationStatPrefix[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FText LocalizationStatSuffix[4];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FText LocalizationNames[19];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FText ScopeModeNames[2];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FText AutoReloadNames[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FText SprintModeNames[4];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FText CrouchModeNames[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FText CrosshairModeNames[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FText CrosshairColorNames[9];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor CrosshairColors[9];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FText GraphicQualityPresetNames[6];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FText SettingsQualityWithoffNames[5];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FText SettingsQualityNames[4];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FText AspectRatioNames[5];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DisplayModeNames[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FText AnisotropyNames[4];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FText AntiAlliasingNames[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FText ColorBlindNames[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FText CreditCategories[3];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ERandomMeshTag, uint8> EditorCurrentTagFrequencies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> EditorCurrentRandomMeshLevelsChecked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> PlaceholderRandomMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EditorCurrentLevelSpecificSlot;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 EditorCurrentTrapCountByType[11];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> EditorCurrentTrapsLevelsChecked;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AATrap> TrapClasses[11];
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AATrap> LoadedTrapClasses[11];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DemoMaxBasecampLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowNavMeshBoundsVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShippingWithCheatCode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EBuildType BuildType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowStaticMeshBlocker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWasRandomizedIngame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowTilesRoofBlockingBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowEnemySpawnersInGame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowLookAtPointsInGame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowObjectSlotsInGame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowTrapSlotsInGame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowWallTurretSlotsInGame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowHoleSpawnerSlotsInGame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowWorkerTriggersInGame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowPickupPointsInGame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceStorePlateform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStorePlatform ForcedStorePlateform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceConsolePlateform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EConsole ForcedConsolePlateform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ForceClassicGraphicSettingsOnConsole;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowLinkAccountAndServerBrowser;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* DefaultIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FKey, FControllerICon> ControllerIcons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FKey, UTexture2D*> KeyboardIcons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* TutorialGamepadMoveImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WrenchesRewardByStoryCapsule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FKeyword> KeywordData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCasinoFrequency> CasinoFrequencies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FramesBeforePrint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanTriggerWarning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FramerateMinBeforeWarning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanRecordStats;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RecordStatsDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RecordStatsMaxDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EnemyAmountToUpgradeWeapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CorruptedMetarewardValueForCompletion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxGameRecapAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ItemsEqquipedValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PowercellsSpentValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LevelMaxValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ChainHeadbonkAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EngineerSummonAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpearDamageAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MeteorDamageAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RocketMultiKillAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SlashMultiKillAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GuardianBonusAmmo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HeroLandingAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EndlessMutatorValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EndlessPerksValue;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GadgetUnlockByRank[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LogUnlockByRank[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BossTakedownByRank[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CrystalUnlockByRank[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PowercellGatherByRank[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WrenchGatherByRank[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DamageDealtByRank[3];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EnemyDestroyByRank[3];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebugAchievements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* PreloadedLogo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* PreloadedThrobber;
    
    USingleton();

    UFUNCTION(BlueprintCallable)
    void OnTrapEndPlay(AActor* Actor, const TEnumAsByte<EEndPlayReason::Type> EndPlayReason);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsValidNavLocation(const FVector& Location, FVector& ProjectedLocationOnNavMesh) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEnemyGenerationDisabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HaveLocalizationWarning(ELocalization InLocalization) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTexture2D* GetWeaponStarIcon(int32 Level);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetWeaponRarityName(EWeaponColor Color) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetWeaponProcIntensity(EWeaponProcType Type) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLinearColor GetWeaponProcColor(EWeaponProcType Type) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetWeaponPrice(EWeaponColor InWeaponColor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetWeaponMeshTransformByType(EAnimPose Type) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLinearColor GetWeaponColor(EWeaponColor Color) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSoftObjectPtr<UParticleSystem> GetWeaponAffixParticle(EWeaponAffixParticle InParticle) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetUpgradeWeaponPrice(EWeaponColor InWeaponColor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetUpgradeAffixQualityPrice(EWeaponColor InWeaponColor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetStatusDuration(EStatus Status) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetSprintModeNames(ESprintMode InEnum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetSettingsQualityWithoffNames(ESettingsQualityWithOff InEnum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetSettingsQualityNames(ESettingsQuality InEnum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetScopeModeNames(EScopeMode InEnum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRerollAffixPrice(EWeaponColor InWeaponColor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRerollAffixCost(int32 Level);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetRandomizerPercentChances(ERandomLuck Luck) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMetaRewardsLevelPercent(int32 Level) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMagnetismSettingSliderValue(float X) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetLocalizationStatSuffix(EStatSuffix InEnum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetLocalizationStatPrefixe(EStatPrefix InEnum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetLocalizationSessionRegion(ESessionRegion InEnum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetLocalizationNames(ELocalization InEnum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetLocalizationControllerType(EController InEnum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetLevelUpWeaponWrenchCost(int32 Level, int32 WeaponLevel);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    TArray<FKeyword> GetKeywordData(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTexture2D* GetKeyboardIcon(const FKey& Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetItemPrice(EItemRarity InRarity) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetInverseMagnetismSettingSliderValue(float Y) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetGraphicQualityPresetNames(EGraphicQualityPreset InEnum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGraphicQuality GetGraphicQualityPreset(EGraphicQualityPreset Preset) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FGraphicConsole GetGraphicQualityConsole() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetGarryRewardLuck(uint8 CurrentUseAmount) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<EGarryReward> GetGarryRewardByLuck(ERandomLuck RandomLuck) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EGarryAnimation GetGarryRewardAnimation(EGarryReward RewardType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetGarryPrice(uint8 CurrentUseAmount) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetFPSLimitOnConsole() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetEmptyItemRow(EItemRarity InRarity) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetDisplayModeNames(EDisplayMode InEnum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSoftObjectPtr<UTexture2D> GetCustomCostIcon(ECustomCost Type) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetCrouchModeNames(ECrouchMode InEnum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetCrosshairModeNames(ECrosshairMode InEnum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetCrosshairColorNames(ECrosshairColor InEnum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLinearColor GetCrosshairColor(ECrosshairColor InEnum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetCreditCategory(ECreditCategory InEnum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTexture2D* GetControllerIcon(EController Controller, const FKey& Key);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetColorBlindNames(EColorBlindType InEnum);
    
    UFUNCTION(BlueprintCallable)
    TArray<ECasinoLoot> GetCasinoLootPool(int32 CasinoLevel);
    
    UFUNCTION(BlueprintCallable)
    int32 GetCasinoLootAmountByType(int32 CasinoLevel, ECasinoLoot CasinoLootType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetAutoReloadModeNames(EAutoReloadMode InEnum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetAspectRatioNames(EAspectRatio InEnum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetAntiAlliasingNames(EAntiAlliasing InEnum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetAnisotropyNames(EAnisotropy InEnum);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLinearColor GetAffixColorByRarity(EWeaponAffixRarity Rarity);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    void GenerateKeywordData(const UObject* WorldContextObject);
    
};

