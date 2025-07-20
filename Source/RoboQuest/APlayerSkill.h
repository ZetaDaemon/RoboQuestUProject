#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TimerHandle -FallbackName=TimerHandle
#include "ASkill.h"
#include "Animation.h"
#include "Cost.h"
#include "DelegateOnStackUpdateDelegate.h"
#include "EChargeType.h"
#include "EElement.h"
#include "ElementalParticle.h"
#include "ModAnimation.h"
#include "ModAnimationGunfeel.h"
#include "NetworkSkillInfo.h"
#include "OnomatopoeiaRowHandle.h"
#include "PlayerSkillRow.h"
#include "Templates/SubclassOf.h"
#include "APlayerSkill.generated.h"

class AAProjectile;
class AAWeapon;
class ACharacter_Player;
class UAPlayerSkill;
class UAnimInstance;
class UAnimMontage;
class UAnimSequence;
class UAudioComponent;
class UBlendSpace1D;
class UCurveFloat;
class UParticleSystem;
class UParticleSystemComponent;
class USkeletalMesh;
class USoundCue;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROBOQUEST_API UAPlayerSkill : public UASkill {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateUpdateChargeRatio, UAPlayerSkill*, Skill, float, ChargeRatio);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateStoreSkillRow, bool, bIsInit);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateStoreSkillRow DelegateStoreSkillRow;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlySecondaryDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayerSkill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWarmup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBurstFire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bChargedFire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverheat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBashSkill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCustomNetworkReplication;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDualFire;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bClassSkill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bScope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCooling;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacter_Player* PlayerOwner;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAWeapon* WeaponOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInfiniteCooldownWhenTimePaused;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGameTimePaused;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseCooldown;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnStackUpdate DelegateOnStackUpdate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BaseStackAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StackAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNoCostForNextShot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCost> CostList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoolingPerShot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoolingPerShotModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* ClassSkillModuleUseAnmation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* ClassSkillModuleMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAnimInstance> ClassSkillModuleAnimBlueprint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ClassSkillModuleAttachSocket;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAimAssist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FirstHitAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AddHitAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxHitAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CriticalHitAmount;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanCritical;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutomaticFireRecover;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LateralRecoilPerShot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RecoilUpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RecoilUpMultiplierPerSecond;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LateralRecoilSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinRecoilUpRatio;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* ChargeLoopSoundComponent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* ChargeStartSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* ChargeLoopSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D ChargeLoopFadeDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStopChargeLoopWhenMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* MaxChargeSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ChargeDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoReleaseOnMaxCharge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsChargeUp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentCharge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDamageRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinImpactRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* WarmupFirerateModifier;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EChargeType ChargeType;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateUpdateChargeRatio DelegateUpdateChargeRatio;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OverheatPerShot;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimation DualAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimation DualCameraAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimation SkillAnimation;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnomatopoeiaRowHandle OnomatopoeiaRow[3];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequence* AutomaticFire_Shake;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D AutomaticFire_BlendDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBlendSpace1D* CharacterChargedBlendSpace;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FModAnimation ModAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FModAnimationGunfeel ModGunFeel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBlendSpace1D* WeaponChargedBlendSpace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseAnimNotify;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWaitForNotify;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle TimerSecurityNotify;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* ChargeFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* SmokeFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<UParticleSystem*, FElementalParticle> ElementalParticles;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* BaseMuzzleInstantFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* MuzzleInstantFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MuzzleInstantFXScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* CastSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* HapticCastSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* HapticUseSound;
    
    UAPlayerSkill(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateStackAmount(int32 NewAddStack);
    
    UFUNCTION(BlueprintCallable)
    void StoreSkillRow(UPARAM(Ref) FPlayerSkillRow& SkillRow, bool bIsInit);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ShouldUseAnimationNotify();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetUseSoundParameter(UAudioComponent* InSound);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetCastSoundParameter(UAudioComponent* InSound);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SecurityAnimNotify();
    
    UFUNCTION(BlueprintCallable)
    void RemoveWarmupState();
    
public:
    UFUNCTION(BlueprintCallable)
    void RemoveStack();
    
    UFUNCTION(BlueprintCallable)
    void RemoveCustomStack();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnUseSkill(const FNetworkSkillInfo& NetworkInfo);
    
private:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerUseSkill(const FNetworkSkillInfo& NetworkInfo);
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerSetCalculateCharge(bool bIsUp);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerPlayAnimNotify();
    
    UFUNCTION(BlueprintCallable)
    void OnReceptAnimNotify();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPlaySkillAnimNotify();
    
private:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastUseSkill(const FNetworkSkillInfo& NetworkInfo);
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastSetCalculateCharge(bool bIsUp);
    
protected:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastPlayAnimNotify();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnGameTimePaused(bool bNewPaused);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnCommonPlayerSkillDataAssetLoaded();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSpawnLoopingMuzzle(UParticleSystemComponent* InMuzzle);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintPreAnimNotify();
    
public:
    UFUNCTION(BlueprintCallable)
    void MaximiseStack();
    
protected:
    UFUNCTION(BlueprintCallable)
    void InitWarmupState(float WarmupDuration, UCurveFloat* WarmupCurve, bool bModifyPitch);
    
    UFUNCTION(BlueprintCallable)
    void InitializeGameTimePausedDelegate();
    
public:
    UFUNCTION(BlueprintCallable)
    void InitializeCustomStack(int32 Amount, float Cooldown);
    
protected:
    UFUNCTION(BlueprintCallable)
    bool HaveCost();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HaveChargeDuration() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAWeapon* GetWeapon() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FAnimation GetSkillAnimation();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetProjectileCustomArc() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACharacter_Player* GetPlayer() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UParticleSystem* GetElementalParticle(UParticleSystem* BaseParticle, const TArray<EElement>& ElementOrder, AAProjectile* Projectile) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetChargeRatio();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetChargeDuration() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBaseChargeDuration();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetAnimationPlayrate();
    
public:
    UFUNCTION(BlueprintCallable)
    void ConsumeStack();
    
    UFUNCTION(BlueprintCallable)
    void AddStack();
    
};

