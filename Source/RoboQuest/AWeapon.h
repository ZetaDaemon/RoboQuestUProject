#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "Animation.h"
#include "EAction.h"
#include "EAnimPose.h"
#include "EAnimationType.h"
#include "EElement.h"
#include "EGameplayTags.h"
#include "EStat.h"
#include "EWeaponAffixRarity.h"
#include "EWeaponAffixType.h"
#include "EWeaponCategory.h"
#include "EWeaponProcType.h"
#include "IReplicatedActor.h"
#include "ISkillManager.h"
#include "IStatManager.h"
#include "RQDamageInfo.h"
#include "StatValues.h"
#include "Templates/SubclassOf.h"
#include "WeaponAffix.h"
#include "WeaponAffixData.h"
#include "WeaponAffixRarity.h"
#include "WeaponAffixRowHandle.h"
#include "WeaponRunSaveGame.h"
#include "WeaponSpecificHandPose.h"
#include "AWeapon.generated.h"

class AAWeapon;
class ACharacter_Player;
class UASkill;
class UASkillManager;
class UAStatManager;
class UAnimInstance;
class UAnimMontage;
class UAnimSequence;
class UAudioComponent;
class UCurveFloat;
class UDataTable;
class UDynamicCrosshairWidget;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UModifier_Damage;
class UModifier_Stat;
class UModifier_Stat_Scale;
class UParticleSystem;
class UParticleSystemComponent;
class USkeletalMesh;
class USkeletalMeshComponent;
class USoundCue;
class UTexture2D;

UCLASS(Blueprintable)
class ROBOQUEST_API AAWeapon : public AActor, public IISkillManager, public IIStatManager, public IIReplicatedActor {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateWeaponElement, EElement, NewElement);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateUpdateSpread, float, NewSpread);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateUpdatePocketReloadRatio, float, NewRatio);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateUpdateCharacterOwner, ACharacter_Player*, Player);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateUpdateAffix);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateRegisterSkill, UASkill*, Skill);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegatePocketReload);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOverheat);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnWarmupUpdate, float, WarmupRatio);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnUpdateCrosshair, const TSoftClassPtr<UDynamicCrosshairWidget>&, NewCrosshairClass);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnStartReload);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnReload);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnModIconLoaded);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnLevelUp, int32, Level);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnKill, FRQDamageInfo, DamageInfo);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnDealDamage, const FRQDamageInfo&, DamageInfo);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateIsInitialized, AAWeapon*, Weapon);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateIsCurrent, ACharacter_Player*, PlayerOwner, bool, bIsCurrent);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateEndOverheat);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateCommonWeaponDataAssetLoaded);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateBoneHidden, const FName&, BoneName, bool, bNewHidden);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isEquiped;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool bInitialWeapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNeedReload;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=RepNotify_CharacterOwner, meta=(AllowPrivateAccess=true))
    ACharacter_Player* CharacterOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bExcludeForSuperbot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText ExcludeForSuperbotText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> CustomFloatProperties;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<int32> FeedbackMuzzleIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FeedbackMuzzleScale;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_WeaponAffix;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_WeaponMod;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnReload DelegateOnReload;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnStartReload DelegateOnStartReload;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnDealDamage DelegateOnDealDamage;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnKill DelegateOnKill;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateUpdateCharacterOwner DelegateUpdateCharacterOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOneHand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHeavy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAStatManager* WeaponStatManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UASkillManager* WeaponSkillManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeaponAffixRowHandle> Affixes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeaponAffixRowHandle> TmpAffixPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeaponAffixRowHandle> RandomAffixes;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RandomAffixesRarity[3];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWeaponCategory LootCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTexture2D* Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* ReloadSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* HapticReloadSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EAction, TSoftClassPtr<UASkill>> SoftSkillClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAnimInstance> AnimClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimPose HandPoseType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAnimation ReloadAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAnimation LowCoolingAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAnimation HighCoolingAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CoolingSpeedRatioByAmmo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponSpecificHandPose SpecificHandPose;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponSpecificHandPose SpecificHandPoseTPV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 UpgradePriceReduction;
    
    UPROPERTY(BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnUpdateCrosshair DelegateOnUpdateCrosshair;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UDynamicCrosshairWidget> CrosshairClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D CrosshairSizeAmplitude;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* WarmupFirerateModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WarmupDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCoolingWeapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentRecoilRecoverySpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RecoilRecoveryMultiplierPerSecond;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxRecoilRecoverySpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RecoilRecoverySpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnergizedReloadSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnergizedFirerate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnergizedDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* IdleSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* IdleSoundComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PickupMeshLocationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator PickupMeshRotationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PickupMeshScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector StarLocationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ModLocationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimSequence* PickupMeshPose;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMesh* PickupOverrideMesh;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateIsInitialized DelegateIsInitialized;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsInitialized;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* TemporaryMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UASkill*> SkillToRegistered;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateRegisterSkill DelegateRegisterSkill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* OverridePlayerReloadFPV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* OverridePlayerReloadTPV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* OverrideWeaponReloadFPV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* OverrideWeaponReloadTPV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* OverridePlayerHighCoolingReloadFPV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* OverridePlayerLowCoolingReloadFPV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* OverrideWeaponHighCoolingReloadFPV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* OverrideWeaponLowCoolingReloadFPV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* OverridePlayerHighCoolingReloadTPV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* OverrideWeaponHighCoolingReloadTPV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* OverrideMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* OverrideOverheatFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> DynamicMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> BaseDynamicMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInterface*> OverrideMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bScope;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanShotWhileScopped;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> HiddenBones;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EElement WeaponElement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSecondaryFireCancelAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 Level;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnLevelUp DelegateOnLevelUp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FName> GunEffectMuzzles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bThrowable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PocketReloadRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCalculatePocketReload;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* WarmupLoopAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* WarmupStartSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* WarmupLoopSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* WarmupStopSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpreadModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D SpreadClamp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpreadIncreaseCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxOverheat;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateIsCurrent DelegateIsCurrent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* StartOverheatSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* StartOverheatHapticSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* LoopOverheatSound;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRecoverCooling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCoolingOverheat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoolingOverheatDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoolingOverheatRecoverSpeedRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor LowCoolingColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor HighCoolingColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystem* OverheatFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OverheatFXSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DualOverheatFXSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* OverheatFXRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* DualOverheatFXRef;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOverheat DelegateOverheat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UModifier_Stat_Scale*> LevelModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UModifier_Stat_Scale*> LevelSecondaryModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DamagePower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpeedPower;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bExcludeForRandomEliteAffix;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateUpdateAffix DelegateUpdateAffix;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponAffixData AffixDatas[4];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 LootLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 AffixAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 AffixEliteLuckLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponAffixRarity CurrentAffixBundle;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FWeaponRunSaveGame WeaponSavedData;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* WeaponModIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 BaseRandomSeed;
    
private:
    
    UPROPERTY(EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int64 CreationTime;
    
public:
    AAWeapon(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void UpgradeWeaponAffixQuality();
    
    UFUNCTION(BlueprintCallable)
    void UpdateWeaponMaterialParameter(const FName& ParameterName, float Value);
    
    UFUNCTION(BlueprintCallable)
    void UpdateSpreadModifier(float NewSpreadModifier);
    
    UFUNCTION(BlueprintCallable)
    void StoreMonitoringTimer(const FString& Context, bool bPrint);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void StartMaterialProcEffect(EWeaponProcType Type);
    
    UFUNCTION(BlueprintCallable)
    void SpawnGunEffectParticle(UParticleSystem* InParticle);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetWeaponVisibility(bool bNewVisibility);
    
    UFUNCTION(BlueprintCallable)
    void SetWeaponLevel(int32 NewLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetWeaponElement(EElement Element);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetWeaponCurrent(bool bIsCurrent);
    
    UFUNCTION(BlueprintCallable)
    void SetVectorDynamicParameter(FName ParameterName, FVector Value);
    
    UFUNCTION(BlueprintCallable)
    void SetSecondaryFireCancelAction(bool bCancelAction);
    
    UFUNCTION(BlueprintCallable)
    void SetScalarDynamicParameter(FName ParameterName, float Value);
    
    UFUNCTION(BlueprintCallable)
    void SetNewWeaponMaterials(UMaterialInstanceDynamic* NewMaterial);
    
    UFUNCTION(BlueprintCallable)
    void SetNewSpreadClamp(FVector2D NewSpreadClamp);
    
    UFUNCTION(BlueprintCallable)
    void SetBoneHidden(FName BoneName, bool bNewHidden);
    
    UFUNCTION(BlueprintCallable)
    void ResetWeaponMaterials();
    
    UFUNCTION(BlueprintCallable)
    void RerollRandomAffixes(bool bKeepAffixBundle);
    
    UFUNCTION(BlueprintCallable)
    void RepNotify_CharacterOwner();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void RemoveWeaponElement(EElement Element);
    
    UFUNCTION(BlueprintCallable)
    void RemoveSuperFeedback();
    
    UFUNCTION(BlueprintCallable)
    void RemoveStatModifier(UModifier_Stat* Modifier);
    
    UFUNCTION(BlueprintCallable)
    void RemoveSpeedPower();
    
protected:
    UFUNCTION(BlueprintCallable)
    void RemoveScopeState();
    
public:
    UFUNCTION(BlueprintCallable)
    void RemoveInfiniteClip();
    
    UFUNCTION(BlueprintCallable)
    void RemoveEliteAffixe();
    
    UFUNCTION(BlueprintCallable)
    void RemoveDamagePower();
    
    UFUNCTION(BlueprintCallable)
    void RemoveDamageModifier(UModifier_Damage* Modifier);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OverrideActionProperties(ACharacter_Player* Player, bool bOverride);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSwitch();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerApplyReload();
    
    UFUNCTION(BlueprintCallable)
    void OnNotifyStatFull(EStat enumStat);
    
    UFUNCTION(BlueprintCallable)
    void OnNotifyStatEmpty(EStat enumStat);
    
    UFUNCTION(BlueprintCallable)
    void OnNotifyStat(EStat enumStat, float curVal, float Value);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastApplyReload();
    
    UFUNCTION(BlueprintCallable)
    void OnEndSwitchReload();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnCommonWeaponDataAssetLoaded();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintUpdateCharacterOwner(ACharacter_Player* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintThrow();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetWarmupRatio(float NewRatio);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetSkillWarmupRatio(EAction TargetSkill, float NewRatio);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetActiveEnergizedFX(bool bIsActive);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintEndInitialization();
    
    UFUNCTION(BlueprintCallable)
    void LevelUpWeapon();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocallyControlled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCurrentWeapon() const;
    
private:
    UFUNCTION(BlueprintCallable)
    void InitWeaponSavedData();
    
public:
    UFUNCTION(BlueprintCallable)
    void InitInfiniteClip();
    
    UFUNCTION(BlueprintCallable)
    void InitializeAffixe(const FName& RowName, EWeaponAffixType Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetWeaponName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetWeaponBaseStat(EStat Stat, EAction Action, ACharacter_Player* PlayerRef, bool bMultiHitPacked);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetWarmupRegenDuration();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetWarmupDuration();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSeededRandomRange(int32 Min, int32 Max, const FString& Context);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetRandomAffixString();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetMuzzleSocketName(int32 Index) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTexture2D* GetModIcon();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMinSpread();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMaxSpread();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAnimSequence* GetHandPose(bool bWantLeft, bool bTPV) const;
    
private:
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<EGameplayTags> GetGameplayTagList();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetDisplayName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetDataRowName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCustomFloatProperty(const FName& PropertyName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentSpread();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentRecoil();
    
    UFUNCTION(BlueprintCallable)
    FName GetCurrentEnchantedAffixRowName();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UParticleSystemComponent* GetCoolingReloadParticle();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCoolingRatio() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UParticleSystemComponent* GetCoolingFeedbackParticle();
    
    UFUNCTION(BlueprintCallable)
    FLinearColor GetCoolingColor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACharacter_Player* GetCharacter();
    
    UFUNCTION(BlueprintCallable)
    EWeaponAffixRarity GetBestAffixRarity();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<EGameplayTags> GetBaseGameplayTagList();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAnimInstance* GetAnimInstanceByType(EAnimationType Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetAffixRowNames(EWeaponAffixType Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetAffixRow(const FName& RowName, FWeaponAffix& OutWeaponAffix) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAffixLevel();
    
    UFUNCTION(BlueprintCallable)
    int32 GetAffixAmountByRarity(EWeaponAffixRarity Rarity);
    
    UFUNCTION(BlueprintCallable)
    void ExtractDatatable();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanReload();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void CancelMaterialProcEffect();
    
    UFUNCTION(BlueprintCallable)
    void ApplySuperFeedback();
    
    UFUNCTION(BlueprintCallable)
    void ApplyStatModifier(UModifier_Stat* Modifier);
    
    UFUNCTION(BlueprintCallable)
    void ApplyReload();
    
    UFUNCTION(BlueprintCallable)
    void ApplyDamageModifier(UModifier_Damage* Modifier);
    
    UFUNCTION(BlueprintCallable)
    void AddSpeedPower();
    
    UFUNCTION(BlueprintCallable)
    FWeaponAffixRowHandle AddRandomAffixe();
    
    UFUNCTION(BlueprintCallable)
    void AddEnchantedAffix(FName EnchantedAffixRowName);
    
    UFUNCTION(BlueprintCallable)
    void AddDamagePower();
    

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

