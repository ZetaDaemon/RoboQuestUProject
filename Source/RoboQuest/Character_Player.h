#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TimerHandle -FallbackName=TimerHandle
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Vector_NetQuantize -FallbackName=Vector_NetQuantize
//CROSS-MODULE INCLUDE V2: -ModuleName=PhysicsCore -ObjectName=EPhysicalSurface -FallbackName=EPhysicalSurface
//CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=ESlateVisibility -FallbackName=ESlateVisibility
#include "ACharacter.h"
#include "Animation.h"
#include "AnimationIntensityByDirectionLoaded.h"
#include "AnimationIntensityLoaded.h"
#include "ArtefactDataWithRowName.h"
#include "ArtefactRow.h"
#include "CollectableRowBase.h"
#include "DamageFeedbackRow.h"
#include "DelegateActionDelegate.h"
#include "DelegateCancelGrappleDelegate.h"
#include "DelegateClassSkillEnabilityDelegate.h"
#include "DelegateCrouchPressedDelegate.h"
#include "DelegateEndSavedRunInitializationDelegate.h"
#include "DelegateInputActionDelegate.h"
#include "DelegateIsOnAirDelegate.h"
#include "DelegateJetpackDelegate.h"
#include "DelegateJetpackFuelRatioDelegate.h"
#include "DelegateJumpOnTargetDelegate.h"
#include "DelegateOnChannelInteractCancelDelegate.h"
#include "DelegateOnChannelInteractDelegate.h"
#include "DelegateOnEndDashDelegate.h"
#include "DelegateOnEndDialogDelegate.h"
#include "DelegateOnFocusInteractibleDelegate.h"
#include "DelegateOnGrantPickupDelegate.h"
#include "DelegateOnInteractDelegate.h"
#include "DelegateOnInteractErrorDelegate.h"
#include "DelegateOnLandedDelegate.h"
#include "DelegateOnReloadDelegate.h"
#include "DelegateOnRidingSplineDelegate.h"
#include "DelegateOnSkillNotifyDelegate.h"
#include "DelegateOnStartDashDelegate.h"
#include "DelegateOnTakeHealbotDelegate.h"
#include "DelegateOnTurboBumpadDelegate.h"
#include "DelegateOnUnlockPermanentRewardDelegate.h"
#include "DelegatePowerSlideDelegate.h"
#include "DelegateTutoTextAppearDelegate.h"
#include "EAction.h"
#include "EAnimPose.h"
#include "EAnimationType.h"
#include "ECrosshairColor.h"
#include "ECrosshairMode.h"
#include "ECustomCost.h"
#include "EDirection.h"
#include "EElement.h"
#include "EGarryReward.h"
#include "EIntensity.h"
#include "EItemPointType.h"
#include "EItemType.h"
#include "EMetaRewardLootType.h"
#include "EMultiplayerLoot.h"
#include "EPerkCompendiumCategory.h"
#include "EPermanentReward.h"
#include "EPickup.h"
#include "ERandomLuck.h"
#include "ESprintMode.h"
#include "EStat.h"
#include "ETargetDetectionCircle.h"
#include "ETeam.h"
#include "ETutoPanel.h"
#include "EWeaponProcType.h"
#include "EquippedWeapon.h"
#include "IBlower.h"
#include "IReplicatedActor.h"
#include "Item.h"
#include "ItemBundle.h"
#include "LocalPlayerData.h"
#include "LootRowHandle.h"
#include "MetaReward.h"
#include "Onomatopoeia.h"
#include "PerkStatModifier.h"
#include "PlayerClassRow.h"
#include "PlayerSkillRow.h"
#include "RQDamageInfo.h"
#include "Request_Game_Weapon.h"
#include "SurfaceSoundAndFx.h"
#include "Templates/SubclassOf.h"
#include "Character_Player.generated.h"

class AADoor;
class AAInteractiveSecretRuins;
class AAInteractiveWeapon;
class AAInteractive_WeaponSpawner;
class AALightSelector;
class AAPlayerController;
class AASpline;
class AAWeapon;
class AActor;
class ACharacter_Enemy;
class ACharacter_Player;
class ASummonStaticMesh;
class UAArtefact;
class UAItem;
class UAPlayerAnimInstance;
class UASkill;
class UAStatManager;
class UATrigger;
class UATriggerMultiple;
class UAnimInstance;
class UAnimMontage;
class UAudioComponent;
class UBossHealthBarWidget;
class UCameraComponent;
class UCompassWidget;
class UCurveFloat;
class UDataTable;
class UHUDIngameWidget;
class UItemIconWidget;
class UMapWidget;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UMaterialParameterCollection;
class UModifier_Damage;
class UModifier_Stat;
class UModifier_Stat_Scale;
class UModifier_Stat_Scale_Level;
class UOverlay;
class UPanelWidget;
class UParticleSystem;
class UParticleSystemComponent;
class UPerkFeedbackWidget;
class UPerkIconWidget;
class UPrimitiveComponent;
class USkeletalMesh;
class USkeletalMeshComponent;
class USoundCue;
class USpotLightComponent;
class USpringArmComponent;
class UStaticMeshComponent;
class UTexture;
class UTexture2D;
class UTrigger_Skill;
class UTrigger_Weapon;
class UUserWidget;
class UVerticalBox;
class UWeaponTooltipWidget;

UCLASS(Blueprintable)
class ROBOQUEST_API ACharacter_Player : public AACharacter, public IIBlower, public IIReplicatedActor {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateUpdateWeaponList);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateUpdateTicketAmount, int32, NewTicketAmount);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateUpdateMaxComboPoint, int32, AddAmount);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateUpdateMagusPassiveDamage, float, NewPassiveDamage);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateUpdateFury, float, NewFury, int32, NewMaxFury);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateUpdateElementDurationRatio, float, NewRatio);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateUpdateElement, EElement, NewElement);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDelegateUpdateCustomCurrency, ECustomCost, Type, int32, NewAmount, bool, bIncreaseValue);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateUpdateComboPoint, int32, NewComboPoint);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateUnlockArtefact, const FName&, RowName, bool, bIsInit);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateStaticChargeReset);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateSpendTicket, int32, TicketAmount);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateSkillUsed, UASkill*, Skill, bool, bIsStarting);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateRegisterSkill, UASkill*, Skill);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOpenTutorialPanel, ETutoPanel, Panel);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnValidateQuestGoal);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnUpdateStaticCharge, float, NewStaticCharge);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDelegateOnUpdateMetaRewardLoot, FName, RowName, EMetaRewardLootType, RewardType, bool, bIsAdded);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnUpdateMaxStaticCharge, int32, AddAmount);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnUpdateDamageCounter);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnUpdateDamageBar, float, NewAmount);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnUnlockCrystal, const FName&, LevelName);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnUnlockClass, const FName&, RowName);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnTakeJumpad);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnSuperbotEatWeapon, ACharacter_Player*, SuperbotRef, AAWeapon*, WeaponRef);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnRollPickableLinkedItem);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnRollPickableItem);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnResurect, ACharacter_Player*, PlayerRef);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnRemoveArtefact, const FName&, RowName);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnPlayersReady);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnPickItem, const FName&, ItemRowName, EItemType, ItemType);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnPickCollectable, ACharacter_Player*, Player, const FName&, InCollectable);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnPickArtefact, const FName&, RowName);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnMaxFury);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnGrantItemPoint);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnFuryReset);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnCodeDoorUnlocked);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnBuyBazarBlueprint, FName, Name);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDelegateOnApplyItem, const FName&, ItemRowName, EItemType, ItemType, const FName&, BaseItemRowName);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnActivateCrystal, const FName&, CrystalRow, bool, bActivate);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateMoveSpeedPower, int32, NewMoveSpeedPower);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateInitializeClassKeywordData);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateInfiniteAmmo, bool, bInfiniteAmmo);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateGainComboPoint, int32, GainedPoint);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateFuryLock, bool, bIsLocked);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateCurrentWeapon, AAWeapon*, NewWeapon);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateConsumeComboPoint, int32, ConsumeAmount);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateBeingResurected, bool, bNewResurectState, float, Duration);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateAutoResurrectTime, float, CurrentAutoResurrectTime);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateApplyElementalState, EElement, Element, bool, bIsApply);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateAddFury, int32, AddedFury);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLoadFromSaved;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAPlayerController* PlayerController;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateTutoTextAppear DelegateTutoTextAppear;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnSkillNotify DelegateOnSkillNotify;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnNotifyIsActivate, meta=(AllowPrivateAccess=true))
    bool bIsActivate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* InteractErrorSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* InteractErrorSoundHaptic;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnFocusInteractible DelegateOnFocusInteractible;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnInteractError DelegateOnInteractError;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnChannelInteract DelegateOnChannelInteract;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnInteract DelegateOnInteract;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnChannelInteractCancel DelegateOnChannelInteractCancel;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateInputAction DelegateInputAction;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateAction DelegateAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* ReloadAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* ReloadVibrationAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EAction> recordActions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 CameraPitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText className;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPerkCompendiumCategory PerkCompendiumCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraComponent* firstPersonCameraComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpringArmComponent* cameraPivot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* FPSMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkillMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* BashMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkillMeshTPS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* BashMeshTPS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* MeleeWeaponMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* MeleeWeaponMeshTPS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* WeaponMeshTPS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InputScaleYaw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InputScalePitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsDestroyByClassSelector;
    
private:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSurfaceSoundAndFx SoundsAndFXBySurface[63];
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsFalling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isOnAir;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateIsOnAir DelegateIsOnAir;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* LandSounds[4];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* MegaLandSound;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* LandHaptics[4];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* MegaLandHaptic;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAnimationIntensityLoaded LandAnimations[5];
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAnimationIntensityByDirectionLoaded HitAnimations[5];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* FootstepSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* FootstepCrouchSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* FootstepSprintSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* FootstepScuffSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveFloat* FootstepCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveFloat* FootstepSoundCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* FootstepHaptic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* FootstepCrouchHaptic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* FootstepSprintHaptic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* FootstepScuffHaptic;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnTurboBumpad DelegateOnTurboBumpad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* FeetCollision;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateJumpOnTarget DelegateJumpOnTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* BootsBounceSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* BootsDamagedSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* BootsBounceHapticSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* BootsDamagedHapticSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ChainHeadbonkAmount;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModifier_Stat* JumpadSpeedModifier;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnTakeJumpad DelegateOnTakeJumpad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWaitForEndJumpad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RocketJumpImpulseRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle TimerRocketJump;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveRocketJumpImpulse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveRocketJumpImpulseRatioByDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* JetpackAudioComponent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateJetpackFuelRatio DelegateJetpackFuelRatio;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateJetpack DelegateJetpack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* JetpackHapticComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveJetpackGravity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bJetpackState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanUseJetpack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UParticleSystem> JetpackFXSoftPtr;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundCue> StartJetpackSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundCue> StopJetpackSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundCue> LoopJetpackSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundCue> LoopJetpackSoundHaptic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* StartJetpackSoundLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* StopJetpackSoundLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* LoopJetpackSoundLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* LoopJetpackSoundHapticLoaded;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGraple;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateCancelGrapple DelegateCancelGrapple;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveBumpSplineSlow[7];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RidingZOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RidingProtectionDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRidingSplineInversed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentRidingDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* RideSoundVolumeCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RideSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LerpRideSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RideSpeedMultiplierRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* RideAudioComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* RideHapticComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* StartRideSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* StopRideSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* LoopRideSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* LoopRideSoundHaptic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* StartRideSoundHaptic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* StopRideSoundHaptic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AASpline* CurrentRidingSpline;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnRidingSpline DelegateOnRidingSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> ClassIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTexture* TextureFPV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTexture* TextureTPV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor ClassColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText ClassPassiveName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText ClassPassiveDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AAWeapon>> BaseWeaponClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> CustomFloatProperties;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UUserWidget> ClassWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UUserWidget> SubCrosshairWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UUserWidget> IconWidget;
    
    UPROPERTY(BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnUnlockClass DelegateOnUnlockClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCenterCrosshair;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateEndSavedRunInitialization DelegateEndSavedRunInitialization;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UClass*> LoadedSaveItemClasses;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystem* LevelUpFXTPS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystem* LevelUpFXFPS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* LevelUpSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* LevelUpHapticSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UModifier_Stat_Scale*> LevelModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UModifier_Stat_Scale_Level* BaseScaleDamageModifier;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthMaxByLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AddHealthMaxByLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShieldByLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamagePercentByLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BashDamagePercentByLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SkillDamagePercentByLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScaleDamagePercentByLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TicketOnLevelUp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpreadModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AAWeapon>> ExcludedWeaponClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AAWeapon>> FavoriteWeaponClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeaponBaseAffixLevelModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeaponMaxAffixLevelModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeaponSpecialAffixLevelModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeaponMerchantAffixLevelModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeaponAffixEliteLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 WeaponUpgradeLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 MaxWeaponUpgradeLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 SpecialWeaponUpgradeLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WeaponLevelUpLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeaponMaxAffixLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WeaponBaseAffixLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoolingConsumeRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=UpdateCurrentWeapon, meta=(AllowPrivateAccess=true))
    AAWeapon* currentWeapon;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAWeapon* LastCurrentWeapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FEquippedWeapon> EquippedWeapons;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AAWeapon*> weaponsList;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateUpdateWeaponList DelegateUpdateWeaponList;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateCurrentWeapon DelegateCurrentWeapon;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAWeapon*> InitialWeaponsRegistered;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnLanded DelegateOnLanded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScopeSensitivityRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GamepadScopeSensitivityRatio;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateClassSkillEnability DelegateClassSkillEnability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bClassSkillEnabled;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateRegisterSkill DelegateRegisterSkill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PocketReloadSpeedMultipier;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnReload DelegateOnReload;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateInfiniteAmmo DelegateInfiniteAmmo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInfiniteAmmo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InfiniteAmmoCounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsSprinting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDash;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveDashSpeedByDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DashStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentDashStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DashStackCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentDashStackCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EndDashInvulnerability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle TimerEndDashInvulnerability;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DashRange;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnEndDash DelegateOnEndDash;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnEndDash DelegateOnLocalEndDash;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnStartDash DelegateOnLocalStartDash;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsDashing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle TimerDashParticle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DashFovEffectDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DashFovEffectResetDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DashFovEffectEndDiff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveFloat* DashFovEffectCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsCrouchToggle;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateCrouchPressed DelegateCrouchPressed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnNotifyIsPressedCrouched, meta=(AllowPrivateAccess=true))
    bool isCrouchedPressed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool isCrouched;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* CrouchSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* UncrouchSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* CrouchSoundHaptic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* UncrouchSoundHaptic;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegatePowerSlide DelegatePowerSlide;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* PowerSlideStartSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* PowerSlideStartSoundHaptic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurvePowerSlide;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PowerSlideRate;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimMontage* SwitchAnimations[5];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* SwitchSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* SwitchSoundHaptic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* InteractActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ResurrectTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AutoResurrectTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanAutoResurect;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateAutoResurrectTime DelegateAutoResurrectTime;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateBeingResurected DelegateBeingResurected;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UMapWidget> MapWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UMapWidget> MiniMapWidget;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* FocusedActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BaseFirstJumpVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FirstJumpVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveJumpMultiplierBySpeedBonus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 JumpAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 JumpNumber;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* BaseJumpSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* JumpSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* DoubleJumpSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* TripleJumpSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* BaseJumpSoundHaptic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* JumpSoundHaptic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* DoubleJumpSoundHaptic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* TripleJumpSoundHaptic;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimMontage* JumpAnimations[5];
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimMontage* JumpAnimationsTPV[5];
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimMontage* DoubleJumpAnimationsTPV[5];
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FAnimationIntensityLoaded LandAnimationsTPV[5];
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAnimInstance> AnimInstanceFPSLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAnimInstance> AnimInstanceTPSLoaded;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCameraShake;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LastSkillAnimationGameplayTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CenterCrosshairOnomatopeiaOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AnimIdle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimCameraYawDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimCameraPitchDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimStrafeDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimMeshDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimMeshYawRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimMeshYawAIM;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimRunPlayrate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimSprintPlayrate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimCrouchPlayrate;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystem* OnomatopoeiaParticle;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLinearColor OnomatopoeiaColor[10];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, FOnomatopoeia> OnomatopoeiaData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UParticleSystemComponent*> OnomatopoeiaRefs;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* MPC_FOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UHUDIngameWidget> HUDIngameWidgetClass;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UPerkFeedbackWidget> PerkFeedbackMainWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UPerkFeedbackWidget> PerkFeedbackSubWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UPerkIconWidget> PerkIconWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemIconWidget> ItemIconWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UItemIconWidget*> ItemIconWidgets;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInterface* TemporaryMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> BaseCharacterFPSMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> BaseCharacterTPSMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> BaseWeaponMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> BaseSkillMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> BaseBashMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> BaseTPSSkillMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> BaseTPSBashMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> BaseMeleeWeaponMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> BaseTPSMeleeWeaponMaterials;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnUpdateDamageCounter DelegateOnUpdateDamageCounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShieldRegenerationValueByPickup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthRegenerationValueByPickup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthRegenerationValueByPickupWhenScratchbar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PermanentDamagePercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BossPermanentDamagePercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PermanentDamageBarFreezeTimeOnTakeDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PermanentDamageBarFreezeTimeOnTakePowerCell;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* PermanentDamageDecreaseSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamageBarRegenerationSpeed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnUpdateDamageBar DelegateOnUpdateDamageBar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentDamageBarValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanCritical;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnemyStatusDurationRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldApplyDotShockDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ExtraLife;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRepairSratchBarOnLevelUp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthPercentByLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MetaHealthPercentByLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* SpawnAnimationSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* SpawnAnimationHaptic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* SpawnAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* WeaponSpawnAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* IntroIrisAnimation;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimMontage* DeathAnimations[5];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* DeathSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* DeathCinematicSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSkipNextDeathVideoSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* TakeDamageSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* KillSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* KillPitchCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* KillVolumeCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* TakeDamageHapticSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* DeathHapticSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* DeathCinematicHapticSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* ReviveSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* ReviveSoundHaptic;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnResurect DelegateOnResurect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacter_Player* DeathPlayerToResurect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AddedInvulnerabilityDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OnDeathDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASummonStaticMesh* SummonStaticMeshRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DamagePower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpeedPower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MoveSpeedPower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ResistanceFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MoveSpeedFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UModifier_Stat*> SummonStatModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UModifier_Damage*> SummonDamageModifiers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SummonLifetimeMultiplier;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UVerticalBox* HUDVBoxSummonBarRef;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnPickItem DelegateOnPickItem;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnApplyItem DelegateOnApplyItem;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnGrantItemPoint DelegateOnGrantItemPoint;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnRollPickableItem DelegateOnRollPickableItem;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnRollPickableLinkedItem DelegateOnRollPickableLinkedItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> StoredPickableLinkedItemRows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxUpgradeLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> PerkLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> InfinitePerkLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ItemRerollPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ItemDiscoverAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EItemPointType> ItemPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EItemPointType> StartingItemPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BaseItemRowName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FItemBundle> ItemBundles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ItemRowNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> SubItemRowNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> CommonItemRowNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> InfiniteItemRowNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ClassItemRowNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FName> SubItemRowLink;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> PickedItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UAItem>> ItemClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAItem*> ItemRefs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> StoredPickableItemRows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, int32> PerkSparkAmounts;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_Artefacts;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAArtefact*> CurrentArtefacts;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateUnlockArtefact DelegateUnlockArtefact;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> UnlockedArtefacts;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnPickArtefact DelegateOnPickArtefact;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnRemoveArtefact DelegateOnRemoveArtefact;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* ShieldMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModifier_Stat* SlowModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<EPermanentReward> PermanentRewards;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnUnlockPermanentReward DelegateOnUnlockPermanentReward;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* UnlockSecretSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* UnlockSecretHaptic;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_PlayerClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_Collectables;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, bool> CrystalsFound;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnUnlockCrystal DelegateOnUnlockCrystal;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnActivateCrystal DelegateOnActivateCrystal;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FName> AlreadySeenCinematics;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnEndDialog DelegateOnEndDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthPickupValueModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHavePickupSpeedModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UModifier_Stat* PickupSpeedModifier;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    float PickupValueModifier[11];
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnGrantPickup DelegateOnGrantPickup;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnGrantPickup DelegatePostGrantPickup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RunWrenchAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USoundCue*> PickupSoundQueue;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnTakeHealbot DelegateOnTakeHealbot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HealbotLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealbotRecoverHealthModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTakingHealbot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsReadyToStartSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInSpecialTile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UATrigger*> Triggers;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateSkillUsed DelegateSkillUsed;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveFovCorrection;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GamepadMagnetismRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GamepadAccelerationRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GamepadSlowSensitivityRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, int32> DoorCodeByLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCodeDoorUnlocked;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAInteractiveSecretRuins*> InteractiveSecretRuins;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsReady;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsReadyToStartGame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsReadyToStartInfiniteGame;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnPlayersReady DelegateOnPlayersReady;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AADoor*> OneWayDoorsCrossed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_MetaRewards;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_Loot;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxChestAddWeaponAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxChestTicketAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxChestRandomTicketLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxChestItemAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxChestRareItemLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxChestLegendaryItemLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpecialChestAddWeaponAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpecialChestTicketAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpecialChestRandomTicketLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpecialChestItemAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpecialChestRareItemLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpecialChestLegendaryItemLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpecialChestCorruptedItemAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHealthPickupInSpecial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMerchantItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMerchantWeapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMerchantUpgradeWeapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMerchantUpgradeAffix;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MerchantPriceModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MerchantSpawnModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLootRowHandle> SpecificMerchantsAvailable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 WeaponMerchantAddLootAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 WeaponMerchantAffixLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 WeaponSpecialAffixLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UpgradeMerchantCanRerollAffix;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCookingGlove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RerollAffixPriceReduction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpgradeMerchantDoubleUpgradeLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 ItemMerchantAddLootAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 ItemMerchantLuckLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 ItemMerchantCorruptedLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, int32> BazarBlueprintUnlocked;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnBuyBazarBlueprint DelegateOnBuyBazarBlueprint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 CasinoLevel;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateSpendTicket DelegateSpendTicket;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateUpdateTicketAmount DelegateUpdateTicketAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentTicket;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateUpdateCustomCurrency DelegateUpdateCustomCurrency;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGambleGarryUnlocked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GambleGarryUseAmount;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ACharacter_Enemy*> LeashingEnemies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ACharacter_Enemy*> HookingEnemies;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOpenTutorialPanel DelegateOpenTutorialPanel;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_DamageFeedback;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ComboPointOnDash;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxComboPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentComboPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ComboPointOnKill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UModifier_Stat* SlashBonusDamageModifier;
    
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateUpdateComboPoint DelegateUpdateComboPoint;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateConsumeComboPoint DelegateConsumeComboPoint;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateUpdateMaxComboPoint DelegateUpdateMaxComboPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* MaxComboSound;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTrigger_Weapon* TriggerPassiveGuardian;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTrigger_Weapon* TriggerPassiveGuardianCooling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTrigger_Weapon* TriggerPassiveGuardianAmmo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UModifier_Stat* PassiveDamageModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UModifier_Stat* PassiveAmmoModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UModifier_Stat* PassiveCoolingModifier;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* AddStackSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* MaxStackSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* ResetStackSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UModifier_Stat* AutoCriticalModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UModifier_Stat* ReloadModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UModifier_Stat* FirerateModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UModifier_Stat* MovespeedModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UModifier_Stat* TriggerWeapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UModifier_Stat* SkillDurationModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UModifier_Stat* SkillFirerateModifier;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxFury;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReloadSpeedModifierValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AutoCriticalModifierValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FirerateModifierValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SkillAttackSpeedModifierValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MovespeedModifierValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FuryLockDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FuryLockDelayOnBoss;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FuryDecreaseSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FuryUpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IncrementFuryValueOnShortyBoss;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IncrementFuryValueOnRocketBoss;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IncrementFuryValueOnKill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLockFury;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentFury;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLooseFuryOnTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentFuryLockDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FuryDecreaseSpeedRatio;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateUpdateFury DelegateUpdateFury;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateAddFury DelegateAddFury;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ScrapByHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ScrapByKill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentElementDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MagusPassiveDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    EElement CurrentElement;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateUpdateElementDurationRatio DelegateUpdateElementDurationRatio;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateUpdateElement DelegateUpdateElement;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateApplyElementalState DelegateApplyElementalState;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateUpdateMagusPassiveDamage DelegateUpdateMagusPassiveDamage;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* StartMoveSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* StopMoveSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* LoopMoveSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* MoveSoundAudioComponent;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnSuperbotEatWeapon DelegateOnSuperbotEatWeapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EatWeaponRestoreHealthPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnergizeDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* EatWeaponSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* EatLegendaryWeaponSound;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnUpdateStaticCharge DelegateOnUpdateStaticCharge;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnUpdateMaxStaticCharge DelegateOnUpdateMaxStaticCharge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxStaticCharge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentStaticCharge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModifier_Stat* SentinelCriticalDamageModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModifier_Stat* SentinelAutoCriticalModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UModifier_Damage* SentinelBashDamageModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StaticChargeGenerationSpeedRatio;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AALightSelector* LightSelectorRef;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateInitializeClassKeywordData DelegateInitializeClassKeywordData;
    
    ACharacter_Player(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool WasCrystalFound(const FName& LevelName) const;
    
    UFUNCTION(BlueprintCallable)
    void ValidateSecretRuins(uint8 ID);
    
    UFUNCTION(BlueprintCallable)
    void UpdateSentinelAutoCriticalModifier(float NewValue);
    
    UFUNCTION(BlueprintCallable)
    void UpdatePowerSlideTimeline(float Value);
    
    UFUNCTION(BlueprintCallable)
    void UpdatePlayerClass(FName NewClass);
    
    UFUNCTION(BlueprintCallable)
    void UpdateMaxFury(int32 AddMaxFury);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateMagusPassiveDamage(float AddPassiveDamage);
    
    UFUNCTION(BlueprintCallable)
    void UpdateHeightRatio(float NewHeightRatio);
    
    UFUNCTION(BlueprintCallable)
    void UpdateFury(float NewFury);
    
    UFUNCTION(BlueprintCallable)
    void UpdateFOV(int32 NewFOV, bool bIsDash);
    
    UFUNCTION(BlueprintCallable)
    void UpdateElementDurationRatio(EElement Element, float AddRatio);
    
    UFUNCTION(BlueprintCallable)
    void UpdateCurrentWeapon();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateCenterCrosshair(bool bNewCenter);
    
    UFUNCTION(BlueprintCallable)
    void UpdateCameraShake(bool bNewValue);
    
    UFUNCTION(BlueprintCallable)
    void UpdateBumpSplineSlowTimeline(float Value);
    
    UFUNCTION(BlueprintCallable)
    void UnlockPermanentRewardAndCollectable(EPermanentReward InPermanentReward, const FName& CollectableRowName);
    
    UFUNCTION(BlueprintCallable)
    void UnlockPermanentReward(EPermanentReward InPermanentReward);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UnlockNewArtefact(const FName& ArtefactRowName, bool bInstantEquip, bool bIsInitialization);
    
    UFUNCTION(BlueprintCallable)
    void UnlockCommonUpgrade();
    
    UFUNCTION(BlueprintCallable)
    void UnlockAllPerkForClasse(const FName& RowName);
    
    UFUNCTION(BlueprintCallable)
    void TryStopRecordAction(EAction Action);
    
    UFUNCTION(BlueprintCallable)
    void TryStartRecordAction(EAction Action);
    
    UFUNCTION(BlueprintCallable)
    bool TryStartAction(EAction Action);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TriggerDeathWithVideo(FName CinematicRowName);
    
    UFUNCTION(BlueprintCallable)
    void SwitchToTPV();
    
    UFUNCTION(BlueprintCallable)
    void SwitchToFPV();
    
    UFUNCTION(BlueprintCallable)
    void StopRecordAction(EAction Action);
    
    UFUNCTION(BlueprintCallable)
    void StopJetpack(const FString& Context);
    
    UFUNCTION(BlueprintCallable)
    void StartWeaponMaterialProcEffect(EWeaponProcType Type);
    
    UFUNCTION(BlueprintCallable)
    void StartRecordAction(EAction Action);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SpendWrench(int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    void SpawnWeaponOnWeaponSpawner(AAInteractive_WeaponSpawner* WeaponSpawnerRef, const TSoftClassPtr<AAWeapon>& WeaponClass);
    
    UFUNCTION(BlueprintCallable)
    void SpawnBaseWeapon();
    
    UFUNCTION(BlueprintCallable)
    void SimulateCrash();
    
    UFUNCTION(BlueprintCallable)
    void SetTemporaryMaterial(UMaterialInterface* InMaterial);
    
    UFUNCTION(BlueprintCallable)
    void SetMeleeWeaponVisibility(bool bNewVisibility, EAnimationType AnimType, bool bWeapon);
    
    UFUNCTION(BlueprintCallable)
    void SetLooseStaticChargeOnHit(int32 NewLooseStaticChargeOnHit);
    
    UFUNCTION(BlueprintCallable)
    void SetLeashed(bool bIsLeashed, ACharacter_Enemy* LeashInstigator);
    
    UFUNCTION(BlueprintCallable)
    void SetJetpackActivate(bool bIsActive);
    
    UFUNCTION(BlueprintCallable)
    void SetIsReady();
    
    UFUNCTION(BlueprintCallable)
    void SetIsInfiniteAmmo(bool bNewInfiniteAmmo);
    
    UFUNCTION(BlueprintCallable)
    void SetInputEnabled(bool bIsEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetHooked(bool bIsHooked, ACharacter_Enemy* HookInstigator);
    
    UFUNCTION(BlueprintCallable)
    void SetGlobalGravity(float NewGravity);
    
    UFUNCTION(BlueprintCallable)
    void SetFuryLock(bool bNewLockState);
    
    UFUNCTION(BlueprintCallable)
    void SetCodeDoorUnlocked();
    
    UFUNCTION(BlueprintCallable)
    void SetClassSkillEnabled(bool bNewEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetActivateCrystal(const FName& CrystalRowName, bool bActivate);
    
    UFUNCTION(BlueprintCallable)
    void RestoreMaxHealth(float Amount);
    
    UFUNCTION(BlueprintCallable)
    float RestoreDamageBarPercent(float HealthPercent);
    
    UFUNCTION(BlueprintCallable)
    void ResetMaterials();
    
    UFUNCTION(BlueprintCallable)
    void ResetJump();
    
    UFUNCTION(BlueprintCallable)
    void ResetFury();
    
private:
    UFUNCTION(BlueprintCallable)
    void ResetComboPoint();
    
public:
    UFUNCTION(BlueprintCallable)
    void RerollPickableItems();
    
    UFUNCTION(BlueprintCallable)
    void RemoveTriggerWeapon(UTrigger_Weapon* Trigger);
    
    UFUNCTION(BlueprintCallable)
    void RemoveTriggerSkill(UTrigger_Skill* Trigger);
    
    UFUNCTION(BlueprintCallable)
    void RemoveTicket(int32 RemoveTicketAmount);
    
    UFUNCTION(BlueprintCallable)
    void RemoveResistanceFeedback();
    
    UFUNCTION(BlueprintCallable)
    void RemoveMoveSpeedFeedback();
    
    UFUNCTION(BlueprintCallable)
    void RemoveMetaRewardLoot(const FName& RowName, EMetaRewardLootType RewardType);
    
private:
    UFUNCTION(BlueprintCallable)
    void RemoveMaxComboPoint(int32 RemoveAmount);
    
public:
    UFUNCTION(BlueprintCallable)
    void RemoveGlobalSummonStatModifier(UModifier_Stat* StatModifier);
    
    UFUNCTION(BlueprintCallable)
    void RemoveGlobalSummonDamageModifier(UModifier_Damage* DamageModifier);
    
    UFUNCTION(BlueprintCallable)
    void RemoveGlobalSpeedPower();
    
    UFUNCTION(BlueprintCallable)
    void RemoveGlobalMoveSpeedPower();
    
    UFUNCTION(BlueprintCallable)
    void RemoveGlobalDamagePower();
    
    UFUNCTION(BlueprintCallable)
    void RemoveFury(float Amount);
    
    UFUNCTION(BlueprintCallable)
    void RemoveForbiddenAction(EAction Action);
    
    UFUNCTION(BlueprintCallable)
    void RemoveCustomCurrency(ECustomCost Type, int32 RemoveValue);
    
    UFUNCTION(BlueprintCallable)
    void RemoveCancelAction(EAction TargetAction, EAction OldCancelAction);
    
    UFUNCTION(BlueprintCallable)
    void RemoveBlockedAction(EAction TargetAction, EAction OldBlockedAction);
    
    UFUNCTION(BlueprintCallable)
    void RemoveArtefact(int32 RemovedIndex);
    
    UFUNCTION(BlueprintCallable)
    void ReleasedCrouch();
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ReceiptServerInteractValidation(AActor* InInteractActor, bool bResult);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ReceiptServerCancelInteractValidation(AActor* InInteractActor, float InteractTime, bool bResult);
    
    UFUNCTION(BlueprintCallable)
    void PlayHaptic(EIntensity Intensity);
    
    UFUNCTION(BlueprintCallable)
    void OnUpdateLightScenario(bool bActivateFlashLight);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnUpdateComboPoint();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnTriggerWeapon(UTrigger_Weapon* Trigger, AAWeapon* Weapon, bool bIsTrigger);
    
    UFUNCTION(BlueprintCallable)
    void OnTriggerSkill(UTrigger_Skill* Trigger, UASkill* Skill, bool bIsTrigger);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnTriggerResurrect(ACharacter_Player* Resurrector);
    
    UFUNCTION(BlueprintCallable)
    void OnTriggerLevelUp();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTriggerAutoResurrect();
    
    UFUNCTION(BlueprintCallable)
    void OnTrigger(UATriggerMultiple* Trigger, bool bIsTrigger);
    
    UFUNCTION(BlueprintCallable)
    void OnThrowWeapon(AAWeapon* Weapon, bool bForceThrow, bool bSpawnPickup);
    
    UFUNCTION(BlueprintCallable)
    void OnTakeJumpad(bool bDeactivateInput);
    
    UFUNCTION(BlueprintCallable)
    void OnTakeHealbot();
    
    UFUNCTION(BlueprintCallable)
    void OnStopGrapple();
    
    UFUNCTION(BlueprintCallable)
    void OnStartReplicatedItemEffect(FName ItemRowName);
    
    UFUNCTION(BlueprintCallable)
    void OnStartReplicatedArtefactEffectWithBoolean(TSubclassOf<UAArtefact> ArtefactClass, bool bState);
    
    UFUNCTION(BlueprintCallable)
    void OnStartReplicatedArtefactEffectOnTwoLocations(TSubclassOf<UAArtefact> ArtefactClass, FVector_NetQuantize BaseLocation, FVector_NetQuantize Location);
    
    UFUNCTION(BlueprintCallable)
    void OnStartReplicatedArtefactEffectOnLocation(TSubclassOf<UAArtefact> ArtefactClass, FVector_NetQuantize Location);
    
    UFUNCTION(BlueprintCallable)
    void OnStartReplicatedArtefactEffectOnActorAndLocation(TSubclassOf<UAArtefact> ArtefactClass, AActor* Actor, FVector_NetQuantize Location);
    
    UFUNCTION(BlueprintCallable)
    void OnStartReplicatedArtefactEffectOnActor(TSubclassOf<UAArtefact> ArtefactClass, AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void OnStartReplicatedArtefactEffect(TSubclassOf<UAArtefact> ArtefactClass);
    
    UFUNCTION(BlueprintCallable)
    void OnStartGrapple(AActor* GrappedActor, FVector GrappedLocation);
    
    UFUNCTION(BlueprintCallable)
    void OnStartDialog(FName RowName, bool bEraseQueue);
    
    UFUNCTION(BlueprintCallable)
    void OnStartDash(FVector InDashLocation);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSetStealthState();
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerValidateSecretRuins(uint8 ID);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerUpdatePlayerClass(FName NewClass);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerUnlockPermanentReward(EPermanentReward InPermanentReward);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerThrowWeapon(AAWeapon* Weapon, bool bForceThrow, bool bSpawnPickup);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerTakeJumpad(const FVector& JumpadLocation);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerTakeHealbot();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerSwitch(AAWeapon* Weapon);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerStopJetpack();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerStartRidingSpline(const FVector& SplineLocation, float CurrentDistance, bool bInversed);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerStartResurect(ACharacter_Player* TargetPlayer, float InResurrectTime);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerStartReplicatedItemEffect(FName ItemRowName);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerStartReplicatedArtefactEffectWithBoolean(TSubclassOf<UAArtefact> ArtefactClass, bool bState);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerStartReplicatedArtefactEffectOnTwoLocations(TSubclassOf<UAArtefact> ArtefactClass, FVector_NetQuantize BaseLocation, FVector_NetQuantize Location);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerStartReplicatedArtefactEffectOnLocation(TSubclassOf<UAArtefact> ArtefactClass, FVector_NetQuantize Location);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerStartReplicatedArtefactEffectOnActorAndLocation(TSubclassOf<UAArtefact> ArtefactClass, AActor* Actor, FVector_NetQuantize Location);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerStartReplicatedArtefactEffectOnActor(TSubclassOf<UAArtefact> ArtefactClass, AActor* Actor);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerStartReplicatedArtefactEffect(TSubclassOf<UAArtefact> ArtefactClass);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerStartJetpack();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerStartDash(FVector InDashLocation);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerStartAction(EAction Action);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerSplineEvent(const FVector& ForwardVector, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerSpawnWeaponOnWeaponSpawner(AAInteractive_WeaponSpawner* WeaponSpawnerRef, const TSoftClassPtr<AAWeapon>& WeaponClass);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerSkillAskFromStopReplicateRandomSeed(UASkill* Skill);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerSetScopeState(bool bNewState);
    
private:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerSetReadyToStartSequence();
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerSetMaxAcceleration(float NewValue);
    
private:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerSetIsReady();
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerSetFocusActor(AActor* NewActor);
    
private:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerSetCurrentElement(EElement NewElement);
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerSetCrouchPressed(bool NewValue);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerSetCodeDoorUnlocked();
    
    UFUNCTION(BlueprintCallable, Server, Unreliable, WithValidation)
    void OnServerSetCameraPitch(uint8 NewPitch);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerSendLocalKillTarget(FVector_NetQuantize TargetLocation);
    
private:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerSendLocalData(const FLocalPlayerData& Data);
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerSendItemRandomSeed(FName ItemRowName, int32 RandomSeed);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerResurrectPlayer(ACharacter_Player* Resurrector);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerRestoreShield(float Value);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerRestoreMaxHealth(float Amount);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerRestoreHealth(float Value);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerRestoredHealth(float HealthPercent);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerRemoveRewardFromGarryPool(EGarryReward Reward, ERandomLuck Pool);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerRemoveArtefact(int32 RemovedIndex);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerPickItem(FName ItemRowName, int32 RandomSeed, bool bFromPerkSelector);
    
private:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerNotifyLevelGenerationFinished();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerLevelUpWeapon(AAWeapon* Weapon, int32 NewLevel);
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerJumpOnTarget(AActor* TargetRef);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerInteractWithShootingRangeButton(FVector ButtonLocation);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerInteractDiggingHole(const FVector& Location);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerInteract(AActor* TargetActor);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerHasValidatedSpecialTile();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerHasValidatedArena();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerGrantPickup(EPickup PickupType, float Value, UClass* Source);
    
private:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerEquipWeaponFromSpecificPool(const FName& WeaponRowName, int32 WeaponLevel);
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerEndAction(EAction Action);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void OnServerCreateMetaReward(const FName& RowName, bool bJustBought);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerCancelResurect(ACharacter_Player* TargetPlayer);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerCancelInteractChannel(AActor* InInteractActor, float CurrentTime, bool bResult);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerCancelAction(EAction Action);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerAskLocalDataForPlayer(ACharacter_Player* Player);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void OnServerAddArtefact(const FName& RowName, int32 RandomSeed);
    
    UFUNCTION(BlueprintCallable)
    void OnSaveItemLoaded(TSoftClassPtr<UAItem> ItemPtr);
    
    UFUNCTION(BlueprintCallable)
    void OnRestoredHealth(float HealthPercent, bool bAlreadyNetworked);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerDeath(ACharacter_Player* DeathPlayer);
    
    UFUNCTION(BlueprintCallable)
    void OnPickItem(FName ItemRowName, int32 RandomSeed, bool bFromPerkSelector, bool bFromRunSave);
    
    UFUNCTION(BlueprintCallable)
    void OnPickArtefact(const FName& RowName, int32 RandomSeed);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnOnomatopoeiaDeath(UParticleSystemComponent* PSystem);
    
    UFUNCTION(BlueprintCallable)
    void OnOnomatopoeiaDataTableLoaded();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnOneWayDoorDestroyed(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void OnNotifySkillUsed(UASkill* Skill, bool bIsUsed);
    
    UFUNCTION(BlueprintCallable)
    void OnNotifySkillStackUpdate(EAction TargetAction, int32 CurrentStack);
    
    UFUNCTION(BlueprintCallable)
    void OnNotifySkillNoCost(EAction TargetAction);
    
    UFUNCTION(BlueprintCallable)
    void OnNotifySkillCancel(EAction TargetAction);
    
    UFUNCTION(BlueprintCallable)
    void OnNotifySkillAvailable(EAction TargetAction);
    
    UFUNCTION(BlueprintCallable)
    void OnNotifyIsPressedCrouched();
    
    UFUNCTION(BlueprintCallable)
    void OnNotifyIsActivate();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnNewCharacterActivated(AACharacter* ActivateCharacter, ETeam Team, bool bIsActivated);
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastValidateSecretRuins(uint8 ID);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastUnlockPermanentReward(EPermanentReward InPermanentReward);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastThrowWeapon(AAWeapon* Weapon, bool bForceThrow, bool bSpawnPickup);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastTakeJumpad(const FVector& JumpadLocation);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastTakeHealbot();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastStopJetpack();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastStartRidingSpline(const FVector& SplineLocation, float CurrentDistance, bool bInversed);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastStartResurect(ACharacter_Player* TargetPlayer, float InResurrectTime);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastStartReplicatedItemEffect(FName ItemRowName);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastStartReplicatedArtefactEffectWithBoolean(TSubclassOf<UAArtefact> ArtefactClass, bool bState);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastStartReplicatedArtefactEffectOnTwoLocations(TSubclassOf<UAArtefact> ArtefactClass, FVector_NetQuantize BaseLocation, FVector_NetQuantize Location);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastStartReplicatedArtefactEffectOnLocation(TSubclassOf<UAArtefact> ArtefactClass, FVector_NetQuantize Location);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastStartReplicatedArtefactEffectOnActorAndLocation(TSubclassOf<UAArtefact> ArtefactClass, AActor* Actor, FVector_NetQuantize Location);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastStartReplicatedArtefactEffectOnActor(TSubclassOf<UAArtefact> ArtefactClass, AActor* Actor);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastStartReplicatedArtefactEffect(TSubclassOf<UAArtefact> ArtefactClass);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastStartJetpack();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastStartDash(FVector InDashLocation);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastStartAction(EAction Action);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastSplineEvent(const FVector& ForwardVector, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastSetScopeState(bool bNewState);
    
private:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastSetReadyToStartSequence();
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastSetOasisCorruptedDoorBehavior(float ServerGameTime);
    
private:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastSetIsReady();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastSetCurrentElement(EElement NewElement);
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastSetCodeDoorUnlocked();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastSendLocalKillTarget(FVector_NetQuantize TargetLocation);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastSendItemRandomSeed(FName ItemRowName, int32 RandomSeed);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastResurrectPlayer(ACharacter_Player* Resurrector);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastRestoreShield(float Value);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastRestoreMaxHealth(float Amount);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastRestoreHealth(float Value);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastRestoredHealth(float HealthPercent);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastRemoveRewardFromGarryPool(EGarryReward Reward, ERandomLuck Pool);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastRemoveArtefact(int32 RemovedIndex);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastPickItem(FName ItemRowName, int32 RandomSeed, bool bFromPerkSelector);
    
private:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastLevelUpWeapon(AAWeapon* Weapon, int32 NewLevel);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastLevelGenerationFinished(uint8 PlayerReadyCount);
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastJumpOnTarget(AActor* TargetRef);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastInteractWithShootingRangeButton(FVector ButtonLocation);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastInteractDiggingHole(const FVector& Location);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastHasValidatedSpecialTile();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastHasValidatedArena();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastGrantPickup(EPickup PickupType, float Value, UClass* Source);
    
private:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastEquipWeaponFromSpecificPool(const FName& WeaponRowName, int32 WeaponLevel);
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastEndAction(EAction Action);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastCreateMetaReward(const FName& RowName, bool bJustBought);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastCancelResurect(ACharacter_Player* TargetPlayer);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastCancelAction(EAction Action);
    
private:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastAllQuestGoalsCompleted();
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastAddArtefact(const FName& RowName, int32 RandomSeed);
    
    UFUNCTION(BlueprintCallable)
    void OnLevelUpWeapon(AAWeapon* Weapon, int32 NewLevel);
    
    UFUNCTION(BlueprintCallable)
    void OnLevelUp(int32 NewLevel);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnLeashingEnemyDestroyed(AActor* LeashingEnemy);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnJumpMouseWheelEndDelay();
    
    UFUNCTION(BlueprintCallable)
    void OnJump();
    
    UFUNCTION(BlueprintCallable)
    void OnItemLoaded(TSoftClassPtr<UAItem> ItemPtr, FName ItemRowName, FName InBaseItemRowName, EItemType ItemType, int32 RandomSeed, bool bFromRunSave);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnInteractiveSecretRuinsDestroyed(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void OnHookingEnemyDestroyed(AActor* HookingEnemy);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnGrantWrench(int32 Amount, bool bShouldSave);
    
    UFUNCTION(BlueprintCallable)
    void OnGrantReplicatedPickup(EPickup PickupType, float Value, UClass* Source);
    
    UFUNCTION(BlueprintCallable)
    void OnGrantPowerCell(float Amount);
    
    UFUNCTION(BlueprintCallable)
    void OnGrantItemPoint(EItemPointType Type);
    
    UFUNCTION(BlueprintCallable)
    void OnFeetCollisionBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void OnEquipWeaponFromSpecificPool(const FName& WeaponRowName, int32 WeaponLevel);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnEquippedInteractiveWeaponDestroyed(AActor* InteractiveWeaponActor);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnEndTimerMultiShieldRegen();
    
    UFUNCTION(BlueprintCallable)
    void OnEndTimerMultiHealthRegen();
    
    UFUNCTION(BlueprintCallable)
    void OnEndTimerHealthPickupOnMeleeHitBoss();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnEndTimerGrantComboPointOnKill();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnEndStopRidingSplineDelay();
    
    UFUNCTION(BlueprintCallable)
    void OnEndStealthInvulnerability();
    
    UFUNCTION(BlueprintCallable)
    void OnEndRocketJumpDelay();
    
    UFUNCTION(BlueprintCallable)
    void OnEndRocketJumpCooldown();
    
    UFUNCTION(BlueprintCallable)
    void OnEndPowerSlide();
    
    UFUNCTION(BlueprintCallable)
    void OnEndPickupSpeed();
    
    UFUNCTION(BlueprintCallable)
    void OnEndInitializeLocalData(const FLocalPlayerData& LocalData);
    
    UFUNCTION(BlueprintCallable)
    void OnEndDialog(FName RowName, bool bCancelled);
    
    UFUNCTION(BlueprintCallable)
    void OnEndDashParticle();
    
    UFUNCTION(BlueprintCallable)
    void OnEndDashInvulnerability();
    
    UFUNCTION(BlueprintCallable)
    void OnEndBumpSplineSlow();
    
    UFUNCTION(BlueprintCallable)
    void OnEndBumpInvulnerability();
    
    UFUNCTION(BlueprintCallable)
    void OnEndBumpCooldown();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnCrossedSpecialDoor(bool bIsEntering);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnCommonPlayerDataAssetLoaded();
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void OnClientReceivePlayerReadyCount(uint8 PlayerReadyCount, bool bPostOrderableActorsInit);
    
public:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void OnClientPressedReload();
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void OnClientInitialization();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnBuyBazarBlueprint(FName Name);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintValidateQuestGoal(uint8 ID, bool bIsLast);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintUseSkill(UASkill* Skill, bool bIsUsed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintUpdateCrosshairOpacitySetting(float InOpacity);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintUpdateCrosshairModeSetting(ECrosshairMode Mode);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintUpdateCrosshairDynamicSetting(bool bDynamic);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintUpdateCrosshairColorSetting(ECrosshairColor Color);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintUnsetCurrentAction(EAction Action);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintUnlockClass(const FName& RowName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintStartTutorial();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintStartPing();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintStartIris2BossFight();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintStartDeathAnimationWidget();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintShowPerkIcons(bool bShow);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintShowItemIcons(bool bShow);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintShowGadgetIcons(bool bShow);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintShowDiscoveryText();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintShowDamageCounter(bool bShow);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintShowCrosshairSecondaryStackCounterSetting(bool bShow);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintShowCrosshairAmmoCounterSetting(bool bShow);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintShowCompass(bool bShow);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetWeaponListVisibility(ESlateVisibility InVisibility);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetTooltipCurrentWeaponVisibility(bool bNewVisibility);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetNewLevelOnHUD(const FText& LevelName, int32 RandomSeed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetNewInteractiveText(const FText& NewText);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetLeashed(bool bIsLeashed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetHUDElementVisible(bool bVisible);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetHooked(bool bIsHooked);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetCurrentAction(EAction Action);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetCrosshairContainerVisibility(bool bVisible);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSendLocalData();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintRemoveInteractiveText();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintPingOnCooldown();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintOpenTutorialPannel(ETutoPanel TutoPannel);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintLanded(FHitResult HitResult, float FallDuration);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintIsActivate(bool bActivate);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintInteractError(AActor* Interractible, const FText& Reason);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintInitializeMetaRewards();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintHideQuestGoalsBar();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    UBossHealthBarWidget* OnBlueprintGetUnlockTextWidget();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    UWeaponTooltipWidget* OnBlueprintGetTooltipCurrentWeapon();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    UOverlay* OnBlueprintGetOverlaySkillIcon();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    UOverlay* OnBlueprintGetOverlayMiniMapContainer();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    UOverlay* OnBlueprintGetOverlayMapContainer();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    UOverlay* OnBlueprintGetOverlayCompassContainer();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    UOverlay* OnBlueprintGetOverlayClassSubCrosshair();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    UOverlay* OnBlueprintGetOverlayClass();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    UPanelWidget* OnBlueprintGetMainHUDPanel();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    UBossHealthBarWidget* OnBlueprintGetBossHealthBar();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintFalling();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintEndDeathAnimationWidget();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintDash(FVector InDashLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintClientInitialization();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintAddNewQuestGoal(uint8 ID, const TSoftObjectPtr<UTexture2D>& IconOn, const TSoftObjectPtr<UTexture2D>& IconOff);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintAddCompassWidgetToHUD(UCompassWidget* CompassWidget);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void NotifyServerPreviousLevelUnloaded();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void NotifyServerEncountersAreInitialized(const TArray<uint8>& EncounterIDs);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void NotifyServerAllPlayersAreInitialized();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void NotifyServerAllDoorsAreRegistered(const FVector_NetQuantize& TileLocation);
    
private:
    UFUNCTION(BlueprintCallable)
    void MaximiseComboPoint();
    
    UFUNCTION(BlueprintCallable)
    void LoadLocomotionFXAndSounds();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSuperBot() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsShooting() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSentinel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSecondPlayer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRecon() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayerOfMultiLoot(EMultiplayerLoot MultiplayerLoot) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool IsMouseWheelKey();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMagus() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInputEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsGuardian() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFullWeapon() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEngineer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCurrentArtefact(const FName& RowName, int32& Index) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCurrentAction(EAction Action) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCrystalActivated(const FName& CrystalRowName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCommando() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActionPressed(EAction Action);
    
    UFUNCTION(BlueprintCallable)
    void InitMeleeWeaponMeshModule(USkeletalMesh* InMesh, TSubclassOf<UAnimInstance> AnimBP);
    
    UFUNCTION(BlueprintCallable)
    void InitializeClassKeywordData();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HavePermanentReward(EPermanentReward InPermanentReward);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HavePerksOrUpgrades();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasCompletedAllQuestGoals() const;
    
    UFUNCTION(BlueprintCallable)
    void HandlePause(bool bIsPaused);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    int32 GetWrenchAmount();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetWeaponsRowName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USkeletalMeshComponent* GetWeaponMesh();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetWeaponListString();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetVelocityLength() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AAWeapon*> GetValidWeaponList() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetUpgradeListString();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FAnimation GetSwitchAnimation(EAnimPose animPose);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UParticleSystemComponent* GetSuperbotMoveParticle();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ESprintMode GetSprintMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FSurfaceSoundAndFx GetSoundsAndFXBySurface(TEnumAsByte<EPhysicalSurface> SurfaceType) const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    TSubclassOf<UModifier_Damage> GetSentinelBashDamageModifierClass();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UParticleSystemComponent* GetRidingParticleSystem();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FRequest_Game_Weapon> GetRequestWeaponData();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<EAction> GetRecordActions();
    
    UFUNCTION(BlueprintCallable)
    EGarryReward GetRandomGambleGarryReward(int32 CurrentUse);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetQuestGoalCount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPlayerOrModSkillRowFromSoftClass(const TSoftClassPtr<UASkill>& SkillClass, FPlayerSkillRow& OutPlayerSkill) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPlayerOrModSkillRowFromRowName(const FName& RowName, FPlayerSkillRow& OutPlayerSkill) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPlayerOrModSkillRowFromClass(const TSubclassOf<UASkill>& SkillClass, FPlayerSkillRow& OutPlayerSkill) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FPlayerClassRow GetPlayerClassRow(const FName& RowName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetPlayerClassName();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPing(bool bRoundTrip, bool bInSeconds) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetPickupSpawnLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    TArray<FName> GetPickableTutoItemRows();
    
    UFUNCTION(BlueprintCallable)
    FPerkStatModifier GetPerkModifiedValue(EStat Stat, int32 GameplayTags);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetPerkListString();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACharacter_Player* GetOtherPlayerRef();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FLootRowHandle> GetMetaRewardLoot(EMetaRewardLootType Type) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetMetaRewardDataFromRowName(const FName& RowName, FMetaReward& OutMetaRewardRow, bool bThrowError);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMaxStaticChargeDuration();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AALightSelector* GetLightSelectorRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EIntensity GetLandIntensity();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAnimMontage* GetLandAnimation(EIntensity Intensity);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UParticleSystemComponent* GetJetpackParticleSystem();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EItemType GetItemType(FName ItemRowName);
    
    UFUNCTION(BlueprintCallable)
    UAItem* GetItemRefByRowName(const FName& RowName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetItemListString();
    
    UFUNCTION(BlueprintCallable)
    FItemBundle GetItemBundleFromRowName(FName ItemRowName);
    
    UFUNCTION(BlueprintCallable)
    AAInteractiveSecretRuins* GetInteractiveSecretRuins(uint8 ID);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UVerticalBox* GetHUDVBoxSummonBarBP();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UVerticalBox* GetHUDVBoxSummonBar();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UHUDIngameWidget* GetHUDIngameWidget();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAnimMontage* GetHitAnimation(EIntensity Intensity, EDirection Direction);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void GetHealthValues(float& OutCurrent, float& OutMax) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHealbotRecoverHealth() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetGrappleHitResult(float GrappleMinDistance, float EnemyMinDistance, float MaxDistance, FHitResult& OutHitResult);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFOVCorrection() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    USpotLightComponent* GetFlashLight() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetElementDurationRatio(EElement Element);
    
    UFUNCTION(BlueprintCallable)
    int32 GetDoorCodeDigitByLevel(const FName& LevelName, int32 Digit);
    
    UFUNCTION(BlueprintCallable)
    int32 GetDoorCodeByLevel(const FName& LevelName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDetectionDistance() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDetectionConeAngle(ETargetDetectionCircle Circle) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ETargetDetectionCircle> GetDetectionCirclesOrderedByAngle() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLinearColor GetDetectionCircleColor(ETargetDetectionCircle Circle) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FHitResult> GetDetectedHitResults(ETargetDetectionCircle Circle) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UParticleSystemComponent* GetDashParticle();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FDamageFeedbackRow GetDamageFeedbackData(const FRQDamageInfo& DamageInfo) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDamageBarPercent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCustomFloatProperty(FName PropertyName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCustomCurrencyAmount(ECustomCost Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<EAction> GetCurrentActions();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FHitResult GetCrosshairRaycast() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCrosshairInfo(FVector& StartTrace, FVector& ForwardVector) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FCollectableRowBase GetCollectableRow(const FName& RowName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetBazarItemList() const;
    
    UFUNCTION(BlueprintCallable)
    FName GetBaseItemRowName(FName InRowName, bool bReturnFirst);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FArtefactRow GetArtefactRow(const FName& RowName, bool& bFind) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAArtefact* GetArtefactByClass(TSubclassOf<UAArtefact> ArtefactClass) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAPlayerAnimInstance* GetAnimInstanceByType(EAnimationType Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FPlayerClassRow> GetAllPlayerClassDatas() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetAllPlayerClassDataRowNames() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FArtefactDataWithRowName> GetAllArtefactDataWithRowName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FArtefactRow> GetAllArtefactData() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FHitResult GetAimedActor() const;
    
    UFUNCTION(BlueprintCallable)
    void ForceGarbageCollection(bool bForcePurge);
    
    UFUNCTION(BlueprintCallable)
    void ExtractDatatable(UAStatManager* PlayerStatManager);
    
    UFUNCTION(BlueprintCallable)
    void EquipWeapon(AAWeapon* Weapon, AAInteractiveWeapon* InteractiveWeapon, bool bSwitchOn, bool bEraseCurrentWeapon);
    
    UFUNCTION(BlueprintCallable)
    void EndAction(EAction Action, bool bIsCancel);
    
    UFUNCTION(BlueprintCallable)
    void DelayedOnTriggerKill();
    
    UFUNCTION(BlueprintCallable)
    void DelayedOnTakeHealbot();
    
    UFUNCTION(BlueprintCallable)
    void CreateWidgetPerkIcon(const TSoftObjectPtr<UTexture2D>& Icon, const FLinearColor& Color, const FName& RowName);
    
    UFUNCTION(BlueprintCallable)
    UPerkFeedbackWidget* CreateWidgetPerkFeedback(bool bIsBaseActive, const FItem& PerkData);
    
    UFUNCTION(BlueprintCallable)
    void CreateWidgetItemIcon(const TSoftObjectPtr<UTexture2D>& Icon);
    
    UFUNCTION(BlueprintCallable)
    void CreateMetaReward(const FName& RowName, bool bJustBought);
    
    UFUNCTION(BlueprintCallable)
    void ConsumePingStack();
    
    UFUNCTION(BlueprintCallable)
    bool CheckRecordAction(EAction Action);
    
    UFUNCTION(BlueprintCallable)
    bool CanUseAction(EAction Action);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanThrow() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanRestoreMaxHealth() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanPickWeapon(AAWeapon* Weapon) const;
    
    UFUNCTION(BlueprintCallable)
    void CancelAllActions();
    
    UFUNCTION(BlueprintCallable)
    void CancelActionsAndSetInputEnabled(bool bIsEnabled);
    
    UFUNCTION(BlueprintCallable)
    void CancelAction(EAction Action);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool CanAttackWhileInStealth();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void AskServerForLevelInitData();
    
private:
    UFUNCTION(BlueprintCallable)
    void AskServerAgainForPlayerReadyCount(bool bPostOrderableActorsInit);
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void AskForServerInteractValidation(AActor* InInteractActor);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void AskForServerCancelInteractValidation(AActor* InInteractActor, float InteractTime);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void AskForPlayerReadyCount(bool bPostOrderableActorsInit);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AlreadyHaveWeapon(AActor* Weapon) const;
    
    UFUNCTION(BlueprintCallable)
    void AddTriggerWeapon(UTrigger_Weapon* Trigger);
    
    UFUNCTION(BlueprintCallable)
    void AddTriggerSkill(UTrigger_Skill* Trigger);
    
    UFUNCTION(BlueprintCallable)
    void AddTrigger(UATriggerMultiple* Trigger);
    
    UFUNCTION(BlueprintCallable)
    void AddTicket(int32 AddTicketAmount, bool bStarting);
    
    UFUNCTION(BlueprintCallable)
    void AddSummonThreatModifier(float AddedSummonThreat);
    
    UFUNCTION(BlueprintCallable)
    void AddSummonLifetimeMultiplier(float AddValue);
    
    UFUNCTION(BlueprintCallable)
    void AddStaticCharges(int32 AddAmount);
    
    UFUNCTION(BlueprintCallable)
    void AddStaticCharge();
    
    UFUNCTION(BlueprintCallable)
    void AddStartingTicket(int32 AddTicketAmount);
    
    UFUNCTION(BlueprintCallable)
    void AddResistanceFeedback();
    
    UFUNCTION(BlueprintCallable)
    void AddPickupValueModifier(EPickup Type, float AddValue);
    
    UFUNCTION(BlueprintCallable)
    void AddNewCancelAction(EAction TargetAction, EAction NewCancelAction);
    
    UFUNCTION(BlueprintCallable)
    void AddNewBlockedAction(EAction TargetAction, EAction NewBlockedAction);
    
    UFUNCTION(BlueprintCallable)
    void AddMoveSpeedFeedback();
    
    UFUNCTION(BlueprintCallable)
    void AddMetaRewardLoot(const FName& RowName, EMetaRewardLootType RewardType);
    
    UFUNCTION(BlueprintCallable)
    void AddMaxStaticCharge(int32 AddAmount);
    
    UFUNCTION(BlueprintCallable)
    void AddJetpackFuel(float AddFuel);
    
    UFUNCTION(BlueprintCallable)
    void AddGlobalSummonStatModifier(UModifier_Stat* StatModifier);
    
    UFUNCTION(BlueprintCallable)
    void AddGlobalSummonDamageModifier(UModifier_Damage* DamageModifier);
    
    UFUNCTION(BlueprintCallable)
    void AddGlobalSpeedPower();
    
    UFUNCTION(BlueprintCallable)
    void AddGlobalMoveSpeedPower();
    
    UFUNCTION(BlueprintCallable)
    void AddGlobalDamagePower();
    
    UFUNCTION(BlueprintCallable)
    void AddFury(float Amount, bool bFromBoss);
    
    UFUNCTION(BlueprintCallable)
    void AddForbiddenAction(EAction Action, bool bCancel);
    
    UFUNCTION(BlueprintCallable)
    void AddExtraLife();
    
    UFUNCTION(BlueprintCallable)
    void AddDamageBarRegenerationByFury(float NewValue);
    
    UFUNCTION(BlueprintCallable)
    void AddDamageBarAmount(float AddAmount);
    
    UFUNCTION(BlueprintCallable)
    void AddCustomCurrency(ECustomCost Type, int32 AddValue);
    
    UFUNCTION(BlueprintCallable)
    void AddCrystalFound(const FName& LevelName);
    
private:
    UFUNCTION(BlueprintCallable)
    void AddComboPoint(int32 AddAmount);
    
public:
    UFUNCTION(BlueprintCallable)
    void AddBaseMoveSpeedModifier(float NewMoveSpeedModifier);
    
    UFUNCTION(BlueprintCallable)
    void AddArtefact(const FName& RowName, int32 RandomSeed);
    

    // Fix for true pure virtual functions not being implemented
};

