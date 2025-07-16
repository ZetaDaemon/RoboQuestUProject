#include "Character_Player.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=AudioComponent -FallbackName=AudioComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=CameraComponent -FallbackName=CameraComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SkeletalMeshComponent -FallbackName=SkeletalMeshComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SpringArmComponent -FallbackName=SpringArmComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Net/UnrealNetwork.h"
#include "RoboquestMovementComponent.h"
#include "Templates/SubclassOf.h"

ACharacter_Player::ACharacter_Player(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<URoboquestMovementComponent>(TEXT("CharMoveComp"))) {
    this->bLoadFromSaved = false;
    this->PlayerController = NULL;
    this->bIsActivate = false;
    this->InteractErrorSound = NULL;
    this->InteractErrorSoundHaptic = NULL;
    this->ReloadAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("ReloadAudioComponent"));
    this->ReloadVibrationAudioComponent = NULL;
    this->CameraPitch = 0;
    this->PerkCompendiumCategory = EPerkCompendiumCategory::Common;
    this->firstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("firstPersonCamera"));
    this->cameraPivot = CreateDefaultSubobject<USpringArmComponent>(TEXT("cameraPivot"));
    this->FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FPSMesh"));
    this->SkillMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkillMesh"));
    this->BashMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BashMesh"));
    this->SkillMeshTPS = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkillMeshTPS"));
    this->BashMeshTPS = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BashMeshTPS"));
    this->MeleeWeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeleeWeaponMesh"));
    this->MeleeWeaponMeshTPS = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeleeWeaponMeshTPS"));
    this->WeaponMeshTPS = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMeshTPS"));
    const FProperty* p_Mesh_Parent = GetClass()->FindPropertyByName("Mesh");
    this->InputScaleYaw = 0.00f;
    this->InputScalePitch = 0.00f;
    this->bIsDestroyByClassSelector = false;
    this->bIsFalling = false;
    this->isOnAir = false;
    this->LandSounds[0] = NULL;
    this->LandSounds[1] = NULL;
    this->LandSounds[2] = NULL;
    this->LandSounds[3] = NULL;
    this->MegaLandSound = NULL;
    this->LandHaptics[0] = NULL;
    this->LandHaptics[1] = NULL;
    this->LandHaptics[2] = NULL;
    this->LandHaptics[3] = NULL;
    this->MegaLandHaptic = NULL;
    this->FootstepSound = NULL;
    this->FootstepCrouchSound = NULL;
    this->FootstepSprintSound = NULL;
    this->FootstepScuffSound = NULL;
    this->FootstepCurve = NULL;
    this->FootstepSoundCurve = NULL;
    this->FootstepHaptic = NULL;
    this->FootstepCrouchHaptic = NULL;
    this->FootstepSprintHaptic = NULL;
    this->FootstepScuffHaptic = NULL;
    this->FeetCollision = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FeetCollision"));
    this->BootsBounceSound = NULL;
    this->BootsDamagedSound = NULL;
    this->BootsBounceHapticSound = NULL;
    this->BootsDamagedHapticSound = NULL;
    this->ChainHeadbonkAmount = 0;
    this->JumpadSpeedModifier = NULL;
    this->bWaitForEndJumpad = false;
    this->RocketJumpImpulseRatio = 1.00f;
    this->CurveRocketJumpImpulse = NULL;
    this->CurveRocketJumpImpulseRatioByDistance = NULL;
    this->JetpackAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("JetpackAudioComponent"));
    this->JetpackHapticComponent = NULL;
    this->CurveJetpackGravity = NULL;
    this->bJetpackState = false;
    this->bCanUseJetpack = true;
    this->StartJetpackSoundLoaded = NULL;
    this->StopJetpackSoundLoaded = NULL;
    this->LoopJetpackSoundLoaded = NULL;
    this->LoopJetpackSoundHapticLoaded = NULL;
    this->bGraple = false;
    this->CurveBumpSplineSlow[0] = NULL;
    this->CurveBumpSplineSlow[1] = NULL;
    this->CurveBumpSplineSlow[2] = NULL;
    this->CurveBumpSplineSlow[3] = NULL;
    this->CurveBumpSplineSlow[4] = NULL;
    this->CurveBumpSplineSlow[5] = NULL;
    this->CurveBumpSplineSlow[6] = NULL;
    this->RidingZOffset = 0.00f;
    this->RidingProtectionDelay = 0.20f;
    this->bRidingSplineInversed = false;
    this->CurrentRidingDistance = 0.00f;
    this->RideSoundVolumeCurve = NULL;
    this->RideSpeed = 0.00f;
    this->LerpRideSpeed = 0.00f;
    this->RideSpeedMultiplierRatio = 1.00f;
    this->RideAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("RideAudioComponent"));
    this->RideHapticComponent = NULL;
    this->StartRideSound = NULL;
    this->StopRideSound = NULL;
    this->LoopRideSound = NULL;
    this->LoopRideSoundHaptic = NULL;
    this->StartRideSoundHaptic = NULL;
    this->StopRideSoundHaptic = NULL;
    this->CurrentRidingSpline = NULL;
    this->TextureFPV = NULL;
    this->TextureTPV = NULL;
    this->ClassWidget = NULL;
    this->SubCrosshairWidget = NULL;
    this->IconWidget = NULL;
    this->bCenterCrosshair = false;
    this->LevelUpFXTPS = NULL;
    this->LevelUpFXFPS = NULL;
    this->LevelUpSound = NULL;
    this->LevelUpHapticSound = NULL;
    this->BaseScaleDamageModifier = NULL;
    this->HealthMaxByLevel = 0.00f;
    this->AddHealthMaxByLevel = 0.00f;
    this->ShieldByLevel = 0.00f;
    this->DamagePercentByLevel = 0.00f;
    this->BashDamagePercentByLevel = 0.00f;
    this->SkillDamagePercentByLevel = 0.00f;
    this->ScaleDamagePercentByLevel = 0.00f;
    this->TicketOnLevelUp = 0;
    this->SpreadModifier = 1.00f;
    this->WeaponBaseAffixLevelModifier = 0.00f;
    this->WeaponMaxAffixLevelModifier = 0.00f;
    this->WeaponSpecialAffixLevelModifier = 0.00f;
    this->WeaponMerchantAffixLevelModifier = 0.00f;
    this->WeaponAffixEliteLevel = 0.00f;
    this->WeaponUpgradeLevel = 0;
    this->MaxWeaponUpgradeLevel = 0;
    this->SpecialWeaponUpgradeLevel = 0;
    this->WeaponLevelUpLevel = 0;
    this->WeaponMaxAffixLevel = 0.00f;
    this->WeaponBaseAffixLevel = 0.00f;
    this->CoolingConsumeRatio = 1.00f;
    this->currentWeapon = NULL;
    this->LastCurrentWeapon = NULL;
    this->ScopeSensitivityRatio = 1.00f;
    this->GamepadScopeSensitivityRatio = 1.00f;
    this->bClassSkillEnabled = true;
    this->PocketReloadSpeedMultipier = 0.00f;
    this->bInfiniteAmmo = false;
    this->InfiniteAmmoCounter = 0;
    this->bIsSprinting = false;
    this->bDash = false;
    this->CurveDashSpeedByDistance = NULL;
    this->DashStack = 0;
    this->CurrentDashStack = 0;
    this->DashStackCooldown = 0.00f;
    this->CurrentDashStackCooldown = 0.00f;
    this->EndDashInvulnerability = 0.00f;
    this->DashRange = 0.00f;
    this->bIsDashing = false;
    this->DashFovEffectDuration = 0.50f;
    this->DashFovEffectResetDuration = 0.10f;
    this->DashFovEffectEndDiff = 0.00f;
    this->DashFovEffectCurve = NULL;
    this->bIsCrouchToggle = false;
    this->isCrouchedPressed = false;
    this->isCrouched = false;
    this->CrouchSound = NULL;
    this->UncrouchSound = NULL;
    this->CrouchSoundHaptic = NULL;
    this->UncrouchSoundHaptic = NULL;
    this->PowerSlideStartSound = NULL;
    this->PowerSlideStartSoundHaptic = NULL;
    this->CurvePowerSlide = NULL;
    this->PowerSlideRate = 0.00f;
    this->SwitchAnimations[0] = NULL;
    this->SwitchAnimations[1] = NULL;
    this->SwitchAnimations[2] = NULL;
    this->SwitchAnimations[3] = NULL;
    this->SwitchAnimations[4] = NULL;
    this->SwitchSound = NULL;
    this->SwitchSoundHaptic = NULL;
    this->InteractActor = NULL;
    this->ResurrectTime = 0.00f;
    this->AutoResurrectTime = 0.00f;
    this->bCanAutoResurect = false;
    this->MapWidget = NULL;
    this->MiniMapWidget = NULL;
    this->FocusedActor = NULL;
    this->BaseFirstJumpVelocity = 0.00f;
    this->FirstJumpVelocity = 0.00f;
    this->CurveJumpMultiplierBySpeedBonus = NULL;
    this->JumpAmount = 2;
    this->JumpNumber = 0;
    this->BaseJumpSound = NULL;
    this->JumpSound = NULL;
    this->DoubleJumpSound = NULL;
    this->TripleJumpSound = NULL;
    this->BaseJumpSoundHaptic = NULL;
    this->JumpSoundHaptic = NULL;
    this->DoubleJumpSoundHaptic = NULL;
    this->TripleJumpSoundHaptic = NULL;
    this->JumpAnimations[0] = NULL;
    this->JumpAnimations[1] = NULL;
    this->JumpAnimations[2] = NULL;
    this->JumpAnimations[3] = NULL;
    this->JumpAnimations[4] = NULL;
    this->JumpAnimationsTPV[0] = NULL;
    this->JumpAnimationsTPV[1] = NULL;
    this->JumpAnimationsTPV[2] = NULL;
    this->JumpAnimationsTPV[3] = NULL;
    this->JumpAnimationsTPV[4] = NULL;
    this->DoubleJumpAnimationsTPV[0] = NULL;
    this->DoubleJumpAnimationsTPV[1] = NULL;
    this->DoubleJumpAnimationsTPV[2] = NULL;
    this->DoubleJumpAnimationsTPV[3] = NULL;
    this->DoubleJumpAnimationsTPV[4] = NULL;
    this->AnimInstanceFPSLoaded = NULL;
    this->AnimInstanceTPSLoaded = NULL;
    this->bCameraShake = false;
    this->LastSkillAnimationGameplayTags = 0;
    this->CenterCrosshairOnomatopeiaOffset = 15.00f;
    this->AnimIdle = false;
    this->AnimCameraYawDirection = 0.00f;
    this->AnimCameraPitchDirection = 0.00f;
    this->AnimStrafeDirection = 0.00f;
    this->AnimDirection = 0.00f;
    this->AnimSpeed = 0.00f;
    this->AnimMeshDirection = 0.00f;
    this->AnimMeshYawRotation = 0.00f;
    this->AnimMeshYawAIM = 0.00f;
    this->AnimRunPlayrate = 0.00f;
    this->AnimSprintPlayrate = 0.00f;
    this->AnimCrouchPlayrate = 0.00f;
    this->OnomatopoeiaParticle = NULL;
    this->MPC_FOV = NULL;
    this->FOV = 110;
    this->PerkFeedbackMainWidgetClass = NULL;
    this->PerkFeedbackSubWidgetClass = NULL;
    this->PerkIconWidgetClass = NULL;
    this->ItemIconWidgetClass = NULL;
    this->TemporaryMaterial = NULL;
    this->ShieldRegenerationValueByPickup = 0.00f;
    this->HealthRegenerationValueByPickup = 0.00f;
    this->HealthRegenerationValueByPickupWhenScratchbar = 0.00f;
    this->PermanentDamagePercent = 0.00f;
    this->BossPermanentDamagePercent = 0.00f;
    this->PermanentDamageBarFreezeTimeOnTakeDamage = 0.00f;
    this->PermanentDamageBarFreezeTimeOnTakePowerCell = 0.00f;
    this->PermanentDamageDecreaseSpeed = NULL;
    this->DamageBarRegenerationSpeed = 0.00f;
    this->CurrentDamageBarValue = 0.00f;
    this->bCanCritical = true;
    this->EnemyStatusDurationRatio = 1.00f;
    this->bShouldApplyDotShockDamage = false;
    this->ExtraLife = 0;
    this->bRepairSratchBarOnLevelUp = false;
    this->HealthPercentByLevel = 0.00f;
    this->MetaHealthPercentByLevel = 0.00f;
    this->SpawnAnimationSound = NULL;
    this->SpawnAnimationHaptic = NULL;
    this->SpawnAnimation = NULL;
    this->WeaponSpawnAnimation = NULL;
    this->IntroIrisAnimation = NULL;
    this->DeathAnimations[0] = NULL;
    this->DeathAnimations[1] = NULL;
    this->DeathAnimations[2] = NULL;
    this->DeathAnimations[3] = NULL;
    this->DeathAnimations[4] = NULL;
    this->DeathSound = NULL;
    this->DeathCinematicSound = NULL;
    this->bSkipNextDeathVideoSound = false;
    this->TakeDamageSound = NULL;
    this->KillSound = NULL;
    this->KillPitchCurve = NULL;
    this->KillVolumeCurve = NULL;
    this->TakeDamageHapticSound = NULL;
    this->DeathHapticSound = NULL;
    this->DeathCinematicHapticSound = NULL;
    this->ReviveSound = NULL;
    this->ReviveSoundHaptic = NULL;
    this->DeathPlayerToResurect = NULL;
    this->AddedInvulnerabilityDuration = 0.00f;
    this->OnDeathDelay = 1.00f;
    this->SummonStaticMeshRef = NULL;
    this->DamagePower = 0;
    this->SpeedPower = 0;
    this->MoveSpeedPower = 0;
    this->ResistanceFeedback = 0;
    this->MoveSpeedFeedback = 0;
    this->SummonLifetimeMultiplier = 1.00f;
    this->HUDVBoxSummonBarRef = NULL;
    this->MaxUpgradeLevel = 0;
    this->ItemRerollPoint = 0;
    this->ItemDiscoverAmount = 2;
    this->DT_Artefacts = NULL;
    this->ShieldMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShieldMesh"));
    this->SlowModifier = NULL;
    this->UnlockSecretSound = NULL;
    this->UnlockSecretHaptic = NULL;
    this->DT_PlayerClasses = NULL;
    this->DT_Collectables = NULL;
    this->HealthPickupValueModifier = 0.00f;
    this->bHavePickupSpeedModifier = false;
    this->PickupSpeedModifier = NULL;
    this->PickupValueModifier[0] = 0.00f;
    this->PickupValueModifier[1] = 0.00f;
    this->PickupValueModifier[2] = 0.00f;
    this->PickupValueModifier[3] = 0.00f;
    this->PickupValueModifier[4] = 0.00f;
    this->PickupValueModifier[5] = 0.00f;
    this->PickupValueModifier[6] = 0.00f;
    this->PickupValueModifier[7] = 0.00f;
    this->PickupValueModifier[8] = 0.00f;
    this->PickupValueModifier[9] = 0.00f;
    this->PickupValueModifier[10] = 0.00f;
    this->RunWrenchAmount = 0;
    this->HealbotLevel = 0;
    this->HealbotRecoverHealthModifier = 0.00f;
    this->bTakingHealbot = false;
    this->bIsReadyToStartSequence = false;
    this->bInSpecialTile = false;
    this->CurveFovCorrection = NULL;
    this->GamepadMagnetismRatio = 1.00f;
    this->GamepadAccelerationRatio = 1.00f;
    this->GamepadSlowSensitivityRatio = 1.00f;
    this->bCodeDoorUnlocked = false;
    this->bIsReady = false;
    this->bIsReadyToStartGame = false;
    this->bIsReadyToStartInfiniteGame = false;
    this->DT_MetaRewards = NULL;
    this->DT_Loot = NULL;
    this->MaxChestAddWeaponAmount = 0;
    this->MaxChestTicketAmount = 0;
    this->MaxChestRandomTicketLuck = 0.00f;
    this->MaxChestItemAmount = 0;
    this->MaxChestRareItemLuck = 0;
    this->MaxChestLegendaryItemLuck = 0;
    this->SpecialChestAddWeaponAmount = 0;
    this->SpecialChestTicketAmount = 1;
    this->SpecialChestRandomTicketLuck = 0.00f;
    this->SpecialChestItemAmount = 0;
    this->SpecialChestRareItemLuck = 0;
    this->SpecialChestLegendaryItemLuck = 0;
    this->SpecialChestCorruptedItemAmount = 0;
    this->bHealthPickupInSpecial = false;
    this->bMerchantItem = false;
    this->bMerchantWeapon = false;
    this->bMerchantUpgradeWeapon = false;
    this->bMerchantUpgradeAffix = false;
    this->MerchantPriceModifier = 0;
    this->MerchantSpawnModifier = 0.00f;
    this->WeaponMerchantAddLootAmount = 0;
    this->WeaponMerchantAffixLevel = 0;
    this->WeaponSpecialAffixLevel = 0;
    this->UpgradeMerchantCanRerollAffix = false;
    this->bCookingGlove = false;
    this->RerollAffixPriceReduction = 0;
    this->UpgradeMerchantDoubleUpgradeLuck = 0.00f;
    this->ItemMerchantAddLootAmount = 0;
    this->ItemMerchantLuckLevel = 0;
    this->ItemMerchantCorruptedLuck = 0;
    this->CasinoLevel = 0;
    this->CurrentTicket = 0;
    this->bGambleGarryUnlocked = false;
    this->GambleGarryUseAmount = 0;
    this->DT_DamageFeedback = NULL;
    this->ComboPointOnDash = 0;
    this->MaxComboPoint = 0;
    this->CurrentComboPoint = 0;
    this->ComboPointOnKill = 0;
    this->SlashBonusDamageModifier = NULL;
    this->MaxComboSound = NULL;
    this->TriggerPassiveGuardian = NULL;
    this->TriggerPassiveGuardianCooling = NULL;
    this->TriggerPassiveGuardianAmmo = NULL;
    this->PassiveDamageModifier = NULL;
    this->PassiveAmmoModifier = NULL;
    this->PassiveCoolingModifier = NULL;
    this->AddStackSound = NULL;
    this->MaxStackSound = NULL;
    this->ResetStackSound = NULL;
    this->AutoCriticalModifier = NULL;
    this->ReloadModifier = NULL;
    this->FirerateModifier = NULL;
    this->MovespeedModifier = NULL;
    this->TriggerWeapon = NULL;
    this->SkillDurationModifier = NULL;
    this->SkillFirerateModifier = NULL;
    this->MaxFury = 0;
    this->ReloadSpeedModifierValue = 0.00f;
    this->AutoCriticalModifierValue = 0.00f;
    this->FirerateModifierValue = 0.00f;
    this->SkillAttackSpeedModifierValue = 0.00f;
    this->MovespeedModifierValue = 0.00f;
    this->FuryLockDelay = 0.00f;
    this->FuryLockDelayOnBoss = 0.00f;
    this->FuryDecreaseSpeed = 0.00f;
    this->FuryUpSpeed = 0.00f;
    this->IncrementFuryValueOnShortyBoss = 0.00f;
    this->IncrementFuryValueOnRocketBoss = 0.00f;
    this->IncrementFuryValueOnKill = 0.00f;
    this->bLockFury = false;
    this->CurrentFury = 0.00f;
    this->bLooseFuryOnTime = true;
    this->CurrentFuryLockDelay = 0.00f;
    this->FuryDecreaseSpeedRatio = 1.00f;
    this->ScrapByHit = 0;
    this->ScrapByKill = 0;
    this->CurrentElementDuration = 0.00f;
    this->MagusPassiveDamage = 0.00f;
    this->CurrentElement = EElement::LastIndex;
    this->StartMoveSound = NULL;
    this->StopMoveSound = NULL;
    this->LoopMoveSound = NULL;
    this->MoveSoundAudioComponent = NULL;
    this->EatWeaponRestoreHealthPercent = 0.00f;
    this->EnergizeDuration = 0.00f;
    this->EatWeaponSound = NULL;
    this->EatLegendaryWeaponSound = NULL;
    this->MaxStaticCharge = 0;
    this->CurrentStaticCharge = 0.00f;
    this->SentinelCriticalDamageModifier = NULL;
    this->SentinelAutoCriticalModifier = NULL;
    this->SentinelBashDamageModifier = NULL;
    this->StaticChargeGenerationSpeedRatio = 1.00f;
    this->LightSelectorRef = NULL;
    this->ShieldMesh->SetupAttachment(RootComponent);
    this->RideAudioComponent->SetupAttachment(RootComponent);
    this->FeetCollision->SetupAttachment(RootComponent);
    this->JetpackAudioComponent->SetupAttachment(RootComponent);
    this->ReloadAudioComponent->SetupAttachment(RootComponent);
    this->cameraPivot->SetupAttachment(RootComponent);
    this->FPSMesh->SetupAttachment(cameraPivot);
    this->SkillMesh->SetupAttachment(RootComponent);
    this->BashMesh->SetupAttachment(RootComponent);
    this->SkillMeshTPS->SetupAttachment(RootComponent);
    this->BashMeshTPS->SetupAttachment(RootComponent);
    this->MeleeWeaponMesh->SetupAttachment(RootComponent);
    this->MeleeWeaponMeshTPS->SetupAttachment(RootComponent);
    this->WeaponMeshTPS->SetupAttachment(p_Mesh_Parent->ContainerPtrToValuePtr<USkeletalMeshComponent>(this));
}

bool ACharacter_Player::WasCrystalFound(const FName& LevelName) const {
    return false;
}

void ACharacter_Player::ValidateSecretRuins(uint8 ID) {
}

void ACharacter_Player::UpdateSentinelAutoCriticalModifier(float NewValue) {
}

void ACharacter_Player::UpdatePowerSlideTimeline(float Value) {
}

void ACharacter_Player::UpdatePlayerClass(FName NewClass) {
}

void ACharacter_Player::UpdateMaxFury(int32 AddMaxFury) {
}

void ACharacter_Player::UpdateMagusPassiveDamage_Implementation(float AddPassiveDamage) {
}

void ACharacter_Player::UpdateHeightRatio(float NewHeightRatio) {
}

void ACharacter_Player::UpdateFury(float NewFury) {
}

void ACharacter_Player::UpdateFOV(int32 NewFOV, bool bIsDash) {
}

void ACharacter_Player::UpdateElementDurationRatio(EElement Element, float AddRatio) {
}

void ACharacter_Player::UpdateCurrentWeapon() {
}

void ACharacter_Player::UpdateCenterCrosshair_Implementation(bool bNewCenter) {
}

void ACharacter_Player::UpdateCameraShake(bool bNewValue) {
}

void ACharacter_Player::UpdateBumpSplineSlowTimeline(float Value) {
}

void ACharacter_Player::UnlockPermanentRewardAndCollectable(EPermanentReward InPermanentReward, const FName& CollectableRowName) {
}

void ACharacter_Player::UnlockPermanentReward(EPermanentReward InPermanentReward) {
}

void ACharacter_Player::UnlockNewArtefact_Implementation(const FName& ArtefactRowName, bool bInstantEquip, bool bIsInitialization) {
}

void ACharacter_Player::UnlockCommonUpgrade() {
}

void ACharacter_Player::UnlockAllPerkForClasse(const FName& RowName) {
}

void ACharacter_Player::TryStopRecordAction(EAction Action) {
}

void ACharacter_Player::TryStartRecordAction(EAction Action) {
}

bool ACharacter_Player::TryStartAction(EAction Action) {
    return false;
}


void ACharacter_Player::SwitchToTPV() {
}

void ACharacter_Player::SwitchToFPV() {
}

void ACharacter_Player::StopRecordAction(EAction Action) {
}

void ACharacter_Player::StopJetpack(const FString& Context) {
}

void ACharacter_Player::StartWeaponMaterialProcEffect(EWeaponProcType Type) {
}

void ACharacter_Player::StartRecordAction(EAction Action) {
}


void ACharacter_Player::SpawnWeaponOnWeaponSpawner(AAInteractive_WeaponSpawner* WeaponSpawnerRef, const TSoftClassPtr<AAWeapon>& WeaponClass) {
}

void ACharacter_Player::SpawnBaseWeapon() {
}

void ACharacter_Player::SimulateCrash() {
}

void ACharacter_Player::SetTemporaryMaterial(UMaterialInterface* InMaterial) {
}

void ACharacter_Player::SetMeleeWeaponVisibility(bool bNewVisibility, EAnimationType AnimType, bool bWeapon) {
}

void ACharacter_Player::SetLooseStaticChargeOnHit(int32 NewLooseStaticChargeOnHit) {
}

void ACharacter_Player::SetLeashed(bool bIsLeashed, ACharacter_Enemy* LeashInstigator) {
}

void ACharacter_Player::SetJetpackActivate(bool bIsActive) {
}

void ACharacter_Player::SetIsReady() {
}

void ACharacter_Player::SetIsInfiniteAmmo(bool bNewInfiniteAmmo) {
}

void ACharacter_Player::SetInputEnabled(bool bIsEnabled) {
}

void ACharacter_Player::SetHooked(bool bIsHooked, ACharacter_Enemy* HookInstigator) {
}

void ACharacter_Player::SetGlobalGravity(float NewGravity) {
}

void ACharacter_Player::SetFuryLock(bool bNewLockState) {
}

void ACharacter_Player::SetCodeDoorUnlocked() {
}

void ACharacter_Player::SetClassSkillEnabled(bool bNewEnabled) {
}

void ACharacter_Player::SetActivateCrystal(const FName& CrystalRowName, bool bActivate) {
}

void ACharacter_Player::RestoreMaxHealth(float Amount) {
}

float ACharacter_Player::RestoreDamageBarPercent(float HealthPercent) {
    return 0.0f;
}

void ACharacter_Player::ResetMaterials() {
}

void ACharacter_Player::ResetJump() {
}

void ACharacter_Player::ResetFury() {
}

void ACharacter_Player::ResetComboPoint() {
}

void ACharacter_Player::RerollPickableItems() {
}

void ACharacter_Player::RemoveTriggerWeapon(UTrigger_Weapon* Trigger) {
}

void ACharacter_Player::RemoveTriggerSkill(UTrigger_Skill* Trigger) {
}

void ACharacter_Player::RemoveTicket(int32 RemoveTicketAmount) {
}

void ACharacter_Player::RemoveResistanceFeedback() {
}

void ACharacter_Player::RemoveMoveSpeedFeedback() {
}

void ACharacter_Player::RemoveMetaRewardLoot(const FName& RowName, EMetaRewardLootType RewardType) {
}

void ACharacter_Player::RemoveMaxComboPoint(int32 RemoveAmount) {
}

void ACharacter_Player::RemoveGlobalSummonStatModifier(UModifier_Stat* StatModifier) {
}

void ACharacter_Player::RemoveGlobalSummonDamageModifier(UModifier_Damage* DamageModifier) {
}

void ACharacter_Player::RemoveGlobalSpeedPower() {
}

void ACharacter_Player::RemoveGlobalMoveSpeedPower() {
}

void ACharacter_Player::RemoveGlobalDamagePower() {
}

void ACharacter_Player::RemoveFury(float Amount) {
}

void ACharacter_Player::RemoveForbiddenAction(EAction Action) {
}

void ACharacter_Player::RemoveCustomCurrency(ECustomCost Type, int32 RemoveValue) {
}

void ACharacter_Player::RemoveCancelAction(EAction TargetAction, EAction OldCancelAction) {
}

void ACharacter_Player::RemoveBlockedAction(EAction TargetAction, EAction OldBlockedAction) {
}

void ACharacter_Player::RemoveArtefact(int32 RemovedIndex) {
}

void ACharacter_Player::ReleasedCrouch() {
}

void ACharacter_Player::ReceiptServerInteractValidation_Implementation(AActor* InInteractActor, bool bResult) {
}

void ACharacter_Player::ReceiptServerCancelInteractValidation_Implementation(AActor* InInteractActor, float InteractTime, bool bResult) {
}

void ACharacter_Player::PlayHaptic(EIntensity Intensity) {
}

void ACharacter_Player::OnUpdateLightScenario(bool bActivateFlashLight) {
}

void ACharacter_Player::OnUpdateComboPoint() {
}

void ACharacter_Player::OnTriggerWeapon(UTrigger_Weapon* Trigger, AAWeapon* Weapon, bool bIsTrigger) {
}

void ACharacter_Player::OnTriggerSkill(UTrigger_Skill* Trigger, UASkill* Skill, bool bIsTrigger) {
}

void ACharacter_Player::OnTriggerResurrect_Implementation(ACharacter_Player* Resurrector) {
}

void ACharacter_Player::OnTriggerLevelUp() {
}


void ACharacter_Player::OnTrigger(UATriggerMultiple* Trigger, bool bIsTrigger) {
}

void ACharacter_Player::OnThrowWeapon(AAWeapon* Weapon, bool bForceThrow, bool bSpawnPickup) {
}

void ACharacter_Player::OnTakeJumpad(bool bDeactivateInput) {
}

void ACharacter_Player::OnTakeHealbot() {
}

void ACharacter_Player::OnStopGrapple() {
}

void ACharacter_Player::OnStartReplicatedItemEffect(FName ItemRowName) {
}

void ACharacter_Player::OnStartReplicatedArtefactEffectWithBoolean(TSubclassOf<UAArtefact> ArtefactClass, bool bState) {
}

void ACharacter_Player::OnStartReplicatedArtefactEffectOnTwoLocations(TSubclassOf<UAArtefact> ArtefactClass, FVector_NetQuantize BaseLocation, FVector_NetQuantize Location) {
}

void ACharacter_Player::OnStartReplicatedArtefactEffectOnLocation(TSubclassOf<UAArtefact> ArtefactClass, FVector_NetQuantize Location) {
}

void ACharacter_Player::OnStartReplicatedArtefactEffectOnActorAndLocation(TSubclassOf<UAArtefact> ArtefactClass, AActor* Actor, FVector_NetQuantize Location) {
}

void ACharacter_Player::OnStartReplicatedArtefactEffectOnActor(TSubclassOf<UAArtefact> ArtefactClass, AActor* Actor) {
}

void ACharacter_Player::OnStartReplicatedArtefactEffect(TSubclassOf<UAArtefact> ArtefactClass) {
}

void ACharacter_Player::OnStartGrapple(AActor* GrappedActor, FVector GrappedLocation) {
}

void ACharacter_Player::OnStartDialog(FName RowName, bool bEraseQueue) {
}

void ACharacter_Player::OnStartDash(FVector InDashLocation) {
}

void ACharacter_Player::OnSetStealthState() {
}

void ACharacter_Player::OnServerValidateSecretRuins_Implementation(uint8 ID) {
}
bool ACharacter_Player::OnServerValidateSecretRuins_Validate(uint8 ID) {
    return true;
}

void ACharacter_Player::OnServerUpdatePlayerClass_Implementation(FName NewClass) {
}
bool ACharacter_Player::OnServerUpdatePlayerClass_Validate(FName NewClass) {
    return true;
}

void ACharacter_Player::OnServerUnlockPermanentReward_Implementation(EPermanentReward InPermanentReward) {
}
bool ACharacter_Player::OnServerUnlockPermanentReward_Validate(EPermanentReward InPermanentReward) {
    return true;
}

void ACharacter_Player::OnServerThrowWeapon_Implementation(AAWeapon* Weapon, bool bForceThrow, bool bSpawnPickup) {
}
bool ACharacter_Player::OnServerThrowWeapon_Validate(AAWeapon* Weapon, bool bForceThrow, bool bSpawnPickup) {
    return true;
}

void ACharacter_Player::OnServerTakeJumpad_Implementation(const FVector& JumpadLocation) {
}
bool ACharacter_Player::OnServerTakeJumpad_Validate(const FVector& JumpadLocation) {
    return true;
}

void ACharacter_Player::OnServerTakeHealbot_Implementation() {
}
bool ACharacter_Player::OnServerTakeHealbot_Validate() {
    return true;
}

void ACharacter_Player::OnServerSwitch_Implementation(AAWeapon* Weapon) {
}
bool ACharacter_Player::OnServerSwitch_Validate(AAWeapon* Weapon) {
    return true;
}

void ACharacter_Player::OnServerStopJetpack_Implementation() {
}
bool ACharacter_Player::OnServerStopJetpack_Validate() {
    return true;
}

void ACharacter_Player::OnServerStartRidingSpline_Implementation(const FVector& SplineLocation, float CurrentDistance, bool bInversed) {
}
bool ACharacter_Player::OnServerStartRidingSpline_Validate(const FVector& SplineLocation, float CurrentDistance, bool bInversed) {
    return true;
}

void ACharacter_Player::OnServerStartResurect_Implementation(ACharacter_Player* TargetPlayer, float InResurrectTime) {
}
bool ACharacter_Player::OnServerStartResurect_Validate(ACharacter_Player* TargetPlayer, float InResurrectTime) {
    return true;
}

void ACharacter_Player::OnServerStartReplicatedItemEffect_Implementation(FName ItemRowName) {
}
bool ACharacter_Player::OnServerStartReplicatedItemEffect_Validate(FName ItemRowName) {
    return true;
}

void ACharacter_Player::OnServerStartReplicatedArtefactEffectWithBoolean_Implementation(TSubclassOf<UAArtefact> ArtefactClass, bool bState) {
}
bool ACharacter_Player::OnServerStartReplicatedArtefactEffectWithBoolean_Validate(TSubclassOf<UAArtefact> ArtefactClass, bool bState) {
    return true;
}

void ACharacter_Player::OnServerStartReplicatedArtefactEffectOnTwoLocations_Implementation(TSubclassOf<UAArtefact> ArtefactClass, FVector_NetQuantize BaseLocation, FVector_NetQuantize Location) {
}
bool ACharacter_Player::OnServerStartReplicatedArtefactEffectOnTwoLocations_Validate(TSubclassOf<UAArtefact> ArtefactClass, FVector_NetQuantize BaseLocation, FVector_NetQuantize Location) {
    return true;
}

void ACharacter_Player::OnServerStartReplicatedArtefactEffectOnLocation_Implementation(TSubclassOf<UAArtefact> ArtefactClass, FVector_NetQuantize Location) {
}
bool ACharacter_Player::OnServerStartReplicatedArtefactEffectOnLocation_Validate(TSubclassOf<UAArtefact> ArtefactClass, FVector_NetQuantize Location) {
    return true;
}

void ACharacter_Player::OnServerStartReplicatedArtefactEffectOnActorAndLocation_Implementation(TSubclassOf<UAArtefact> ArtefactClass, AActor* Actor, FVector_NetQuantize Location) {
}
bool ACharacter_Player::OnServerStartReplicatedArtefactEffectOnActorAndLocation_Validate(TSubclassOf<UAArtefact> ArtefactClass, AActor* Actor, FVector_NetQuantize Location) {
    return true;
}

void ACharacter_Player::OnServerStartReplicatedArtefactEffectOnActor_Implementation(TSubclassOf<UAArtefact> ArtefactClass, AActor* Actor) {
}
bool ACharacter_Player::OnServerStartReplicatedArtefactEffectOnActor_Validate(TSubclassOf<UAArtefact> ArtefactClass, AActor* Actor) {
    return true;
}

void ACharacter_Player::OnServerStartReplicatedArtefactEffect_Implementation(TSubclassOf<UAArtefact> ArtefactClass) {
}
bool ACharacter_Player::OnServerStartReplicatedArtefactEffect_Validate(TSubclassOf<UAArtefact> ArtefactClass) {
    return true;
}

void ACharacter_Player::OnServerStartJetpack_Implementation() {
}
bool ACharacter_Player::OnServerStartJetpack_Validate() {
    return true;
}

void ACharacter_Player::OnServerStartDash_Implementation(FVector InDashLocation) {
}
bool ACharacter_Player::OnServerStartDash_Validate(FVector InDashLocation) {
    return true;
}

void ACharacter_Player::OnServerStartAction_Implementation(EAction Action) {
}
bool ACharacter_Player::OnServerStartAction_Validate(EAction Action) {
    return true;
}

void ACharacter_Player::OnServerSplineEvent_Implementation(const FVector& ForwardVector, const FHitResult& SweepResult) {
}
bool ACharacter_Player::OnServerSplineEvent_Validate(const FVector& ForwardVector, const FHitResult& SweepResult) {
    return true;
}

void ACharacter_Player::OnServerSpawnWeaponOnWeaponSpawner_Implementation(AAInteractive_WeaponSpawner* WeaponSpawnerRef, const TSoftClassPtr<AAWeapon>& WeaponClass) {
}
bool ACharacter_Player::OnServerSpawnWeaponOnWeaponSpawner_Validate(AAInteractive_WeaponSpawner* WeaponSpawnerRef, const TSoftClassPtr<AAWeapon>& WeaponClass) {
    return true;
}

void ACharacter_Player::OnServerSkillAskFromStopReplicateRandomSeed_Implementation(UASkill* Skill) {
}
bool ACharacter_Player::OnServerSkillAskFromStopReplicateRandomSeed_Validate(UASkill* Skill) {
    return true;
}

void ACharacter_Player::OnServerSetScopeState_Implementation(bool bNewState) {
}
bool ACharacter_Player::OnServerSetScopeState_Validate(bool bNewState) {
    return true;
}

void ACharacter_Player::OnServerSetReadyToStartSequence_Implementation() {
}
bool ACharacter_Player::OnServerSetReadyToStartSequence_Validate() {
    return true;
}

void ACharacter_Player::OnServerSetMaxAcceleration_Implementation(float NewValue) {
}
bool ACharacter_Player::OnServerSetMaxAcceleration_Validate(float NewValue) {
    return true;
}

void ACharacter_Player::OnServerSetIsReady_Implementation() {
}
bool ACharacter_Player::OnServerSetIsReady_Validate() {
    return true;
}

void ACharacter_Player::OnServerSetFocusActor_Implementation(AActor* NewActor) {
}
bool ACharacter_Player::OnServerSetFocusActor_Validate(AActor* NewActor) {
    return true;
}

void ACharacter_Player::OnServerSetCurrentElement_Implementation(EElement NewElement) {
}
bool ACharacter_Player::OnServerSetCurrentElement_Validate(EElement NewElement) {
    return true;
}

void ACharacter_Player::OnServerSetCrouchPressed_Implementation(bool NewValue) {
}
bool ACharacter_Player::OnServerSetCrouchPressed_Validate(bool NewValue) {
    return true;
}

void ACharacter_Player::OnServerSetCodeDoorUnlocked_Implementation() {
}
bool ACharacter_Player::OnServerSetCodeDoorUnlocked_Validate() {
    return true;
}

void ACharacter_Player::OnServerSetCameraPitch_Implementation(uint8 NewPitch) {
}
bool ACharacter_Player::OnServerSetCameraPitch_Validate(uint8 NewPitch) {
    return true;
}

void ACharacter_Player::OnServerSendLocalKillTarget_Implementation(FVector_NetQuantize TargetLocation) {
}
bool ACharacter_Player::OnServerSendLocalKillTarget_Validate(FVector_NetQuantize TargetLocation) {
    return true;
}

void ACharacter_Player::OnServerSendLocalData_Implementation(const FLocalPlayerData& Data) {
}
bool ACharacter_Player::OnServerSendLocalData_Validate(const FLocalPlayerData& Data) {
    return true;
}

void ACharacter_Player::OnServerSendItemRandomSeed_Implementation(FName ItemRowName, int32 RandomSeed) {
}
bool ACharacter_Player::OnServerSendItemRandomSeed_Validate(FName ItemRowName, int32 RandomSeed) {
    return true;
}

void ACharacter_Player::OnServerResurrectPlayer_Implementation(ACharacter_Player* Resurrector) {
}
bool ACharacter_Player::OnServerResurrectPlayer_Validate(ACharacter_Player* Resurrector) {
    return true;
}

void ACharacter_Player::OnServerRestoreShield_Implementation(float Value) {
}
bool ACharacter_Player::OnServerRestoreShield_Validate(float Value) {
    return true;
}

void ACharacter_Player::OnServerRestoreMaxHealth_Implementation(float Amount) {
}
bool ACharacter_Player::OnServerRestoreMaxHealth_Validate(float Amount) {
    return true;
}

void ACharacter_Player::OnServerRestoreHealth_Implementation(float Value) {
}
bool ACharacter_Player::OnServerRestoreHealth_Validate(float Value) {
    return true;
}

void ACharacter_Player::OnServerRestoredHealth_Implementation(float HealthPercent) {
}
bool ACharacter_Player::OnServerRestoredHealth_Validate(float HealthPercent) {
    return true;
}

void ACharacter_Player::OnServerRemoveRewardFromGarryPool_Implementation(EGarryReward Reward, ERandomLuck Pool) {
}
bool ACharacter_Player::OnServerRemoveRewardFromGarryPool_Validate(EGarryReward Reward, ERandomLuck Pool) {
    return true;
}

void ACharacter_Player::OnServerRemoveArtefact_Implementation(int32 RemovedIndex) {
}
bool ACharacter_Player::OnServerRemoveArtefact_Validate(int32 RemovedIndex) {
    return true;
}

void ACharacter_Player::OnServerPickItem_Implementation(FName ItemRowName, int32 RandomSeed, bool bFromPerkSelector) {
}
bool ACharacter_Player::OnServerPickItem_Validate(FName ItemRowName, int32 RandomSeed, bool bFromPerkSelector) {
    return true;
}

void ACharacter_Player::OnServerNotifyLevelGenerationFinished_Implementation() {
}
bool ACharacter_Player::OnServerNotifyLevelGenerationFinished_Validate() {
    return true;
}

void ACharacter_Player::OnServerLevelUpWeapon_Implementation(AAWeapon* Weapon, int32 NewLevel) {
}
bool ACharacter_Player::OnServerLevelUpWeapon_Validate(AAWeapon* Weapon, int32 NewLevel) {
    return true;
}

void ACharacter_Player::OnServerJumpOnTarget_Implementation(AActor* TargetRef) {
}
bool ACharacter_Player::OnServerJumpOnTarget_Validate(AActor* TargetRef) {
    return true;
}

void ACharacter_Player::OnServerInteractWithShootingRangeButton_Implementation(FVector ButtonLocation) {
}
bool ACharacter_Player::OnServerInteractWithShootingRangeButton_Validate(FVector ButtonLocation) {
    return true;
}

void ACharacter_Player::OnServerInteractDiggingHole_Implementation(const FVector& Location) {
}
bool ACharacter_Player::OnServerInteractDiggingHole_Validate(const FVector& Location) {
    return true;
}

void ACharacter_Player::OnServerInteract_Implementation(AActor* TargetActor) {
}
bool ACharacter_Player::OnServerInteract_Validate(AActor* TargetActor) {
    return true;
}

void ACharacter_Player::OnServerHasValidatedSpecialTile_Implementation() {
}
bool ACharacter_Player::OnServerHasValidatedSpecialTile_Validate() {
    return true;
}

void ACharacter_Player::OnServerHasValidatedArena_Implementation() {
}
bool ACharacter_Player::OnServerHasValidatedArena_Validate() {
    return true;
}

void ACharacter_Player::OnServerGrantPickup_Implementation(EPickup PickupType, float Value, UClass* Source) {
}
bool ACharacter_Player::OnServerGrantPickup_Validate(EPickup PickupType, float Value, UClass* Source) {
    return true;
}

void ACharacter_Player::OnServerEquipWeaponFromSpecificPool_Implementation(const FName& WeaponRowName, int32 WeaponLevel) {
}
bool ACharacter_Player::OnServerEquipWeaponFromSpecificPool_Validate(const FName& WeaponRowName, int32 WeaponLevel) {
    return true;
}

void ACharacter_Player::OnServerEndAction_Implementation(EAction Action) {
}
bool ACharacter_Player::OnServerEndAction_Validate(EAction Action) {
    return true;
}

void ACharacter_Player::OnServerCreateMetaReward_Implementation(const FName& RowName, bool bJustBought) {
}

void ACharacter_Player::OnServerCancelResurect_Implementation(ACharacter_Player* TargetPlayer) {
}
bool ACharacter_Player::OnServerCancelResurect_Validate(ACharacter_Player* TargetPlayer) {
    return true;
}

void ACharacter_Player::OnServerCancelInteractChannel_Implementation(AActor* InInteractActor, float CurrentTime, bool bResult) {
}
bool ACharacter_Player::OnServerCancelInteractChannel_Validate(AActor* InInteractActor, float CurrentTime, bool bResult) {
    return true;
}

void ACharacter_Player::OnServerCancelAction_Implementation(EAction Action) {
}
bool ACharacter_Player::OnServerCancelAction_Validate(EAction Action) {
    return true;
}

void ACharacter_Player::OnServerAskLocalDataForPlayer_Implementation(ACharacter_Player* Player) {
}
bool ACharacter_Player::OnServerAskLocalDataForPlayer_Validate(ACharacter_Player* Player) {
    return true;
}

void ACharacter_Player::OnServerAddArtefact_Implementation(const FName& RowName, int32 RandomSeed) {
}
bool ACharacter_Player::OnServerAddArtefact_Validate(const FName& RowName, int32 RandomSeed) {
    return true;
}

void ACharacter_Player::OnSaveItemLoaded(TSoftClassPtr<UAItem> ItemPtr) {
}

void ACharacter_Player::OnRestoredHealth(float HealthPercent, bool bAlreadyNetworked) {
}

void ACharacter_Player::OnPlayerDeath(ACharacter_Player* DeathPlayer) {
}

void ACharacter_Player::OnPickItem(FName ItemRowName, int32 RandomSeed, bool bFromPerkSelector, bool bFromRunSave) {
}

void ACharacter_Player::OnPickArtefact(const FName& RowName, int32 RandomSeed) {
}

void ACharacter_Player::OnOnomatopoeiaDeath(UParticleSystemComponent* PSystem) {
}

void ACharacter_Player::OnOnomatopoeiaDataTableLoaded() {
}

void ACharacter_Player::OnOneWayDoorDestroyed(AActor* Actor) {
}

void ACharacter_Player::OnNotifySkillUsed(UASkill* Skill, bool bIsUsed) {
}

void ACharacter_Player::OnNotifySkillStackUpdate(EAction TargetAction, int32 CurrentStack) {
}

void ACharacter_Player::OnNotifySkillNoCost(EAction TargetAction) {
}

void ACharacter_Player::OnNotifySkillCancel(EAction TargetAction) {
}

void ACharacter_Player::OnNotifySkillAvailable(EAction TargetAction) {
}

void ACharacter_Player::OnNotifyIsPressedCrouched() {
}

void ACharacter_Player::OnNotifyIsActivate() {
}

void ACharacter_Player::OnNewCharacterActivated(AACharacter* ActivateCharacter, ETeam Team, bool bIsActivated) {
}

void ACharacter_Player::OnMulticastValidateSecretRuins_Implementation(uint8 ID) {
}

void ACharacter_Player::OnMulticastUnlockPermanentReward_Implementation(EPermanentReward InPermanentReward) {
}

void ACharacter_Player::OnMulticastThrowWeapon_Implementation(AAWeapon* Weapon, bool bForceThrow, bool bSpawnPickup) {
}

void ACharacter_Player::OnMulticastTakeJumpad_Implementation(const FVector& JumpadLocation) {
}

void ACharacter_Player::OnMulticastTakeHealbot_Implementation() {
}

void ACharacter_Player::OnMulticastStopJetpack_Implementation() {
}

void ACharacter_Player::OnMulticastStartRidingSpline_Implementation(const FVector& SplineLocation, float CurrentDistance, bool bInversed) {
}

void ACharacter_Player::OnMulticastStartResurect_Implementation(ACharacter_Player* TargetPlayer, float InResurrectTime) {
}

void ACharacter_Player::OnMulticastStartReplicatedItemEffect_Implementation(FName ItemRowName) {
}

void ACharacter_Player::OnMulticastStartReplicatedArtefactEffectWithBoolean_Implementation(TSubclassOf<UAArtefact> ArtefactClass, bool bState) {
}

void ACharacter_Player::OnMulticastStartReplicatedArtefactEffectOnTwoLocations_Implementation(TSubclassOf<UAArtefact> ArtefactClass, FVector_NetQuantize BaseLocation, FVector_NetQuantize Location) {
}

void ACharacter_Player::OnMulticastStartReplicatedArtefactEffectOnLocation_Implementation(TSubclassOf<UAArtefact> ArtefactClass, FVector_NetQuantize Location) {
}

void ACharacter_Player::OnMulticastStartReplicatedArtefactEffectOnActorAndLocation_Implementation(TSubclassOf<UAArtefact> ArtefactClass, AActor* Actor, FVector_NetQuantize Location) {
}

void ACharacter_Player::OnMulticastStartReplicatedArtefactEffectOnActor_Implementation(TSubclassOf<UAArtefact> ArtefactClass, AActor* Actor) {
}

void ACharacter_Player::OnMulticastStartReplicatedArtefactEffect_Implementation(TSubclassOf<UAArtefact> ArtefactClass) {
}

void ACharacter_Player::OnMulticastStartJetpack_Implementation() {
}

void ACharacter_Player::OnMulticastStartDash_Implementation(FVector InDashLocation) {
}

void ACharacter_Player::OnMulticastStartAction_Implementation(EAction Action) {
}

void ACharacter_Player::OnMulticastSplineEvent_Implementation(const FVector& ForwardVector, const FHitResult& SweepResult) {
}

void ACharacter_Player::OnMulticastSetScopeState_Implementation(bool bNewState) {
}

void ACharacter_Player::OnMulticastSetReadyToStartSequence_Implementation() {
}

void ACharacter_Player::OnMulticastSetOasisCorruptedDoorBehavior_Implementation(float ServerGameTime) {
}

void ACharacter_Player::OnMulticastSetIsReady_Implementation() {
}

void ACharacter_Player::OnMulticastSetCurrentElement_Implementation(EElement NewElement) {
}

void ACharacter_Player::OnMulticastSetCodeDoorUnlocked_Implementation() {
}

void ACharacter_Player::OnMulticastSendLocalKillTarget_Implementation(FVector_NetQuantize TargetLocation) {
}

void ACharacter_Player::OnMulticastSendItemRandomSeed_Implementation(FName ItemRowName, int32 RandomSeed) {
}

void ACharacter_Player::OnMulticastResurrectPlayer_Implementation(ACharacter_Player* Resurrector) {
}

void ACharacter_Player::OnMulticastRestoreShield_Implementation(float Value) {
}

void ACharacter_Player::OnMulticastRestoreMaxHealth_Implementation(float Amount) {
}

void ACharacter_Player::OnMulticastRestoreHealth_Implementation(float Value) {
}

void ACharacter_Player::OnMulticastRestoredHealth_Implementation(float HealthPercent) {
}

void ACharacter_Player::OnMulticastRemoveRewardFromGarryPool_Implementation(EGarryReward Reward, ERandomLuck Pool) {
}

void ACharacter_Player::OnMulticastRemoveArtefact_Implementation(int32 RemovedIndex) {
}

void ACharacter_Player::OnMulticastPickItem_Implementation(FName ItemRowName, int32 RandomSeed, bool bFromPerkSelector) {
}

void ACharacter_Player::OnMulticastLevelUpWeapon_Implementation(AAWeapon* Weapon, int32 NewLevel) {
}

void ACharacter_Player::OnMulticastLevelGenerationFinished_Implementation(uint8 PlayerReadyCount) {
}

void ACharacter_Player::OnMulticastJumpOnTarget_Implementation(AActor* TargetRef) {
}

void ACharacter_Player::OnMulticastInteractWithShootingRangeButton_Implementation(FVector ButtonLocation) {
}

void ACharacter_Player::OnMulticastInteractDiggingHole_Implementation(const FVector& Location) {
}

void ACharacter_Player::OnMulticastHasValidatedSpecialTile_Implementation() {
}

void ACharacter_Player::OnMulticastHasValidatedArena_Implementation() {
}

void ACharacter_Player::OnMulticastGrantPickup_Implementation(EPickup PickupType, float Value, UClass* Source) {
}

void ACharacter_Player::OnMulticastEquipWeaponFromSpecificPool_Implementation(const FName& WeaponRowName, int32 WeaponLevel) {
}

void ACharacter_Player::OnMulticastEndAction_Implementation(EAction Action) {
}

void ACharacter_Player::OnMulticastCreateMetaReward_Implementation(const FName& RowName, bool bJustBought) {
}

void ACharacter_Player::OnMulticastCancelResurect_Implementation(ACharacter_Player* TargetPlayer) {
}

void ACharacter_Player::OnMulticastCancelAction_Implementation(EAction Action) {
}

void ACharacter_Player::OnMulticastAllQuestGoalsCompleted_Implementation() {
}

void ACharacter_Player::OnMulticastAddArtefact_Implementation(const FName& RowName, int32 RandomSeed) {
}

void ACharacter_Player::OnLevelUpWeapon(AAWeapon* Weapon, int32 NewLevel) {
}

void ACharacter_Player::OnLevelUp(int32 NewLevel) {
}

void ACharacter_Player::OnLeashingEnemyDestroyed(AActor* LeashingEnemy) {
}

void ACharacter_Player::OnJumpMouseWheelEndDelay() {
}

void ACharacter_Player::OnJump() {
}

void ACharacter_Player::OnItemLoaded(TSoftClassPtr<UAItem> ItemPtr, FName ItemRowName, FName InBaseItemRowName, EItemType ItemType, int32 RandomSeed, bool bFromRunSave) {
}

void ACharacter_Player::OnInteractiveSecretRuinsDestroyed(AActor* Actor) {
}

void ACharacter_Player::OnHookingEnemyDestroyed(AActor* HookingEnemy) {
}

void ACharacter_Player::OnGrantWrench(int32 Amount, bool bShouldSave) {
}

void ACharacter_Player::OnGrantReplicatedPickup(EPickup PickupType, float Value, UClass* Source) {
}

void ACharacter_Player::OnGrantPowerCell(float Amount) {
}

void ACharacter_Player::OnGrantItemPoint(EItemPointType Type) {
}

void ACharacter_Player::OnFeetCollisionBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ACharacter_Player::OnEquipWeaponFromSpecificPool(const FName& WeaponRowName, int32 WeaponLevel) {
}

void ACharacter_Player::OnEquippedInteractiveWeaponDestroyed(AActor* InteractiveWeaponActor) {
}

void ACharacter_Player::OnEndTimerMultiShieldRegen() {
}

void ACharacter_Player::OnEndTimerMultiHealthRegen() {
}

void ACharacter_Player::OnEndTimerHealthPickupOnMeleeHitBoss() {
}

void ACharacter_Player::OnEndTimerGrantComboPointOnKill() {
}

void ACharacter_Player::OnEndStopRidingSplineDelay() {
}

void ACharacter_Player::OnEndStealthInvulnerability() {
}

void ACharacter_Player::OnEndRocketJumpDelay() {
}

void ACharacter_Player::OnEndRocketJumpCooldown() {
}

void ACharacter_Player::OnEndPowerSlide() {
}

void ACharacter_Player::OnEndPickupSpeed() {
}

void ACharacter_Player::OnEndInitializeLocalData(const FLocalPlayerData& LocalData) {
}

void ACharacter_Player::OnEndDialog(FName RowName, bool bCancelled) {
}

void ACharacter_Player::OnEndDashParticle() {
}

void ACharacter_Player::OnEndDashInvulnerability() {
}

void ACharacter_Player::OnEndBumpSplineSlow() {
}

void ACharacter_Player::OnEndBumpInvulnerability() {
}

void ACharacter_Player::OnEndBumpCooldown() {
}

void ACharacter_Player::OnCrossedSpecialDoor_Implementation(bool bIsEntering) {
}

void ACharacter_Player::OnCommonPlayerDataAssetLoaded() {
}

void ACharacter_Player::OnClientReceivePlayerReadyCount_Implementation(uint8 PlayerReadyCount, bool bPostOrderableActorsInit) {
}

void ACharacter_Player::OnClientPressedReload_Implementation() {
}

void ACharacter_Player::OnClientInitialization_Implementation() {
}

void ACharacter_Player::OnBuyBazarBlueprint_Implementation(FName Name) {
}























































void ACharacter_Player::NotifyServerPreviousLevelUnloaded_Implementation() {
}
bool ACharacter_Player::NotifyServerPreviousLevelUnloaded_Validate() {
    return true;
}

void ACharacter_Player::NotifyServerEncountersAreInitialized_Implementation(const TArray<uint8>& EncounterIDs) {
}
bool ACharacter_Player::NotifyServerEncountersAreInitialized_Validate(const TArray<uint8>& EncounterIDs) {
    return true;
}

void ACharacter_Player::NotifyServerAllPlayersAreInitialized_Implementation() {
}
bool ACharacter_Player::NotifyServerAllPlayersAreInitialized_Validate() {
    return true;
}

void ACharacter_Player::NotifyServerAllDoorsAreRegistered_Implementation(const FVector_NetQuantize& TileLocation) {
}
bool ACharacter_Player::NotifyServerAllDoorsAreRegistered_Validate(const FVector_NetQuantize& TileLocation) {
    return true;
}

void ACharacter_Player::MaximiseComboPoint() {
}

void ACharacter_Player::LoadLocomotionFXAndSounds() {
}

bool ACharacter_Player::IsSuperBot() const {
    return false;
}

bool ACharacter_Player::IsShooting() const {
    return false;
}

bool ACharacter_Player::IsSentinel() const {
    return false;
}

bool ACharacter_Player::IsSecondPlayer() const {
    return false;
}

bool ACharacter_Player::IsRecon() const {
    return false;
}

bool ACharacter_Player::IsPlayerOfMultiLoot(EMultiplayerLoot MultiplayerLoot) const {
    return false;
}


bool ACharacter_Player::IsMagus() const {
    return false;
}

bool ACharacter_Player::IsInputEnabled() const {
    return false;
}

bool ACharacter_Player::IsGuardian() const {
    return false;
}

bool ACharacter_Player::IsFullWeapon() const {
    return false;
}

bool ACharacter_Player::IsEngineer() const {
    return false;
}

bool ACharacter_Player::IsCurrentArtefact(const FName& RowName, int32& Index) const {
    return false;
}

bool ACharacter_Player::IsCurrentAction(EAction Action) const {
    return false;
}

bool ACharacter_Player::IsCrystalActivated(const FName& CrystalRowName) const {
    return false;
}

bool ACharacter_Player::IsCommando() const {
    return false;
}

bool ACharacter_Player::IsActionPressed(EAction Action) {
    return false;
}

void ACharacter_Player::InitMeleeWeaponMeshModule(USkeletalMesh* InMesh, TSubclassOf<UAnimInstance> AnimBP) {
}

void ACharacter_Player::InitializeClassKeywordData() {
}

bool ACharacter_Player::HavePermanentReward(EPermanentReward InPermanentReward) {
    return false;
}

bool ACharacter_Player::HavePerksOrUpgrades() {
    return false;
}

bool ACharacter_Player::HasCompletedAllQuestGoals() const {
    return false;
}

void ACharacter_Player::HandlePause(bool bIsPaused) {
}


TArray<FName> ACharacter_Player::GetWeaponsRowName() const {
    return TArray<FName>();
}

USkeletalMeshComponent* ACharacter_Player::GetWeaponMesh() {
    return NULL;
}

FString ACharacter_Player::GetWeaponListString() {
    return TEXT("");
}

float ACharacter_Player::GetVelocityLength() const {
    return 0.0f;
}

TArray<AAWeapon*> ACharacter_Player::GetValidWeaponList() const {
    return TArray<AAWeapon*>();
}

FString ACharacter_Player::GetUpgradeListString() {
    return TEXT("");
}

FAnimation ACharacter_Player::GetSwitchAnimation(EAnimPose animPose) {
    return FAnimation{};
}


ESprintMode ACharacter_Player::GetSprintMode() const {
    return ESprintMode::Toggle;
}

FSurfaceSoundAndFx ACharacter_Player::GetSoundsAndFXBySurface(TEnumAsByte<EPhysicalSurface> SurfaceType) const {
    return FSurfaceSoundAndFx{};
}



TArray<FRequest_Game_Weapon> ACharacter_Player::GetRequestWeaponData() {
    return TArray<FRequest_Game_Weapon>();
}

TArray<EAction> ACharacter_Player::GetRecordActions() {
    return TArray<EAction>();
}

EGarryReward ACharacter_Player::GetRandomGambleGarryReward(int32 CurrentUse) {
    return EGarryReward::Nothing;
}

int32 ACharacter_Player::GetQuestGoalCount() const {
    return 0;
}

bool ACharacter_Player::GetPlayerOrModSkillRowFromSoftClass(const TSoftClassPtr<UASkill>& SkillClass, FPlayerSkillRow& OutPlayerSkill) const {
    return false;
}

bool ACharacter_Player::GetPlayerOrModSkillRowFromRowName(const FName& RowName, FPlayerSkillRow& OutPlayerSkill) const {
    return false;
}

bool ACharacter_Player::GetPlayerOrModSkillRowFromClass(const TSubclassOf<UASkill>& SkillClass, FPlayerSkillRow& OutPlayerSkill) const {
    return false;
}

FPlayerClassRow ACharacter_Player::GetPlayerClassRow(const FName& RowName) const {
    return FPlayerClassRow{};
}

FName ACharacter_Player::GetPlayerClassName() {
    return NAME_None;
}

float ACharacter_Player::GetPing(bool bRoundTrip, bool bInSeconds) const {
    return 0.0f;
}

FVector ACharacter_Player::GetPickupSpawnLocation() const {
    return FVector{};
}


FPerkStatModifier ACharacter_Player::GetPerkModifiedValue(EStat Stat, int32 GameplayTags) {
    return FPerkStatModifier{};
}

FString ACharacter_Player::GetPerkListString() {
    return TEXT("");
}

ACharacter_Player* ACharacter_Player::GetOtherPlayerRef() {
    return NULL;
}

TArray<FLootRowHandle> ACharacter_Player::GetMetaRewardLoot(EMetaRewardLootType Type) const {
    return TArray<FLootRowHandle>();
}

bool ACharacter_Player::GetMetaRewardDataFromRowName(const FName& RowName, FMetaReward& OutMetaRewardRow, bool bThrowError) {
    return false;
}

float ACharacter_Player::GetMaxStaticChargeDuration() {
    return 0.0f;
}

AALightSelector* ACharacter_Player::GetLightSelectorRef() const {
    return NULL;
}

EIntensity ACharacter_Player::GetLandIntensity() {
    return EIntensity::None;
}

UAnimMontage* ACharacter_Player::GetLandAnimation(EIntensity Intensity) {
    return NULL;
}


EItemType ACharacter_Player::GetItemType(FName ItemRowName) {
    return EItemType::Perk;
}

UAItem* ACharacter_Player::GetItemRefByRowName(const FName& RowName) {
    return NULL;
}

FString ACharacter_Player::GetItemListString() {
    return TEXT("");
}

FItemBundle ACharacter_Player::GetItemBundleFromRowName(FName ItemRowName) {
    return FItemBundle{};
}

AAInteractiveSecretRuins* ACharacter_Player::GetInteractiveSecretRuins(uint8 ID) {
    return NULL;
}


UVerticalBox* ACharacter_Player::GetHUDVBoxSummonBar() {
    return NULL;
}

UHUDIngameWidget* ACharacter_Player::GetHUDIngameWidget() {
    return NULL;
}

UAnimMontage* ACharacter_Player::GetHitAnimation(EIntensity Intensity, EDirection Direction) {
    return NULL;
}

void ACharacter_Player::GetHealthValues(float& OutCurrent, float& OutMax) const {
}

float ACharacter_Player::GetHealbotRecoverHealth() const {
    return 0.0f;
}

bool ACharacter_Player::GetGrappleHitResult(float GrappleMinDistance, float EnemyMinDistance, float MaxDistance, FHitResult& OutHitResult) {
    return false;
}

float ACharacter_Player::GetFOVCorrection() const {
    return 0.0f;
}


float ACharacter_Player::GetElementDurationRatio(EElement Element) {
    return 0.0f;
}

int32 ACharacter_Player::GetDoorCodeDigitByLevel(const FName& LevelName, int32 Digit) {
    return 0;
}

int32 ACharacter_Player::GetDoorCodeByLevel(const FName& LevelName) {
    return 0;
}

float ACharacter_Player::GetDetectionDistance() const {
    return 0.0f;
}

float ACharacter_Player::GetDetectionConeAngle(ETargetDetectionCircle Circle) const {
    return 0.0f;
}

TArray<ETargetDetectionCircle> ACharacter_Player::GetDetectionCirclesOrderedByAngle() const {
    return TArray<ETargetDetectionCircle>();
}

FLinearColor ACharacter_Player::GetDetectionCircleColor(ETargetDetectionCircle Circle) const {
    return FLinearColor{};
}

TArray<FHitResult> ACharacter_Player::GetDetectedHitResults(ETargetDetectionCircle Circle) const {
    return TArray<FHitResult>();
}


FDamageFeedbackRow ACharacter_Player::GetDamageFeedbackData(const FRQDamageInfo& DamageInfo) const {
    return FDamageFeedbackRow{};
}

float ACharacter_Player::GetDamageBarPercent() const {
    return 0.0f;
}

float ACharacter_Player::GetCustomFloatProperty(FName PropertyName) const {
    return 0.0f;
}

int32 ACharacter_Player::GetCustomCurrencyAmount(ECustomCost Type) {
    return 0;
}

TArray<EAction> ACharacter_Player::GetCurrentActions() {
    return TArray<EAction>();
}

FHitResult ACharacter_Player::GetCrosshairRaycast() const {
    return FHitResult{};
}

bool ACharacter_Player::GetCrosshairInfo(FVector& StartTrace, FVector& ForwardVector) const {
    return false;
}

FCollectableRowBase ACharacter_Player::GetCollectableRow(const FName& RowName) const {
    return FCollectableRowBase{};
}

TArray<FName> ACharacter_Player::GetBazarItemList() const {
    return TArray<FName>();
}

FName ACharacter_Player::GetBaseItemRowName(FName InRowName, bool bReturnFirst) {
    return NAME_None;
}

FArtefactRow ACharacter_Player::GetArtefactRow(const FName& RowName, bool& bFind) const {
    return FArtefactRow{};
}

UAArtefact* ACharacter_Player::GetArtefactByClass(TSubclassOf<UAArtefact> ArtefactClass) const {
    return NULL;
}

UAPlayerAnimInstance* ACharacter_Player::GetAnimInstanceByType(EAnimationType Type) {
    return NULL;
}

TArray<FPlayerClassRow> ACharacter_Player::GetAllPlayerClassDatas() const {
    return TArray<FPlayerClassRow>();
}

TArray<FName> ACharacter_Player::GetAllPlayerClassDataRowNames() const {
    return TArray<FName>();
}

TArray<FArtefactDataWithRowName> ACharacter_Player::GetAllArtefactDataWithRowName() const {
    return TArray<FArtefactDataWithRowName>();
}

TArray<FArtefactRow> ACharacter_Player::GetAllArtefactData() const {
    return TArray<FArtefactRow>();
}

FHitResult ACharacter_Player::GetAimedActor() const {
    return FHitResult{};
}

void ACharacter_Player::ForceGarbageCollection(bool bForcePurge) {
}

void ACharacter_Player::ExtractDatatable(UAStatManager* PlayerStatManager) {
}

void ACharacter_Player::EquipWeapon(AAWeapon* Weapon, AAInteractiveWeapon* InteractiveWeapon, bool bSwitchOn, bool bEraseCurrentWeapon) {
}

void ACharacter_Player::EndAction(EAction Action, bool bIsCancel) {
}

void ACharacter_Player::DelayedOnTriggerKill() {
}

void ACharacter_Player::DelayedOnTakeHealbot() {
}

void ACharacter_Player::CreateWidgetPerkIcon(const TSoftObjectPtr<UTexture2D>& Icon, const FLinearColor& Color, const FName& RowName) {
}

UPerkFeedbackWidget* ACharacter_Player::CreateWidgetPerkFeedback(bool bIsBaseActive, const FItem& PerkData) {
    return NULL;
}

void ACharacter_Player::CreateWidgetItemIcon(const TSoftObjectPtr<UTexture2D>& Icon) {
}

void ACharacter_Player::CreateMetaReward(const FName& RowName, bool bJustBought) {
}

void ACharacter_Player::ConsumePingStack() {
}

bool ACharacter_Player::CheckRecordAction(EAction Action) {
    return false;
}

bool ACharacter_Player::CanUseAction(EAction Action) {
    return false;
}

bool ACharacter_Player::CanThrow() const {
    return false;
}

bool ACharacter_Player::CanRestoreMaxHealth() const {
    return false;
}

bool ACharacter_Player::CanPickWeapon(AAWeapon* Weapon) const {
    return false;
}

void ACharacter_Player::CancelAllActions() {
}

void ACharacter_Player::CancelActionsAndSetInputEnabled(bool bIsEnabled) {
}

void ACharacter_Player::CancelAction(EAction Action) {
}


void ACharacter_Player::AskServerForLevelInitData_Implementation() {
}
bool ACharacter_Player::AskServerForLevelInitData_Validate() {
    return true;
}

void ACharacter_Player::AskServerAgainForPlayerReadyCount(bool bPostOrderableActorsInit) {
}

void ACharacter_Player::AskForServerInteractValidation_Implementation(AActor* InInteractActor) {
}
bool ACharacter_Player::AskForServerInteractValidation_Validate(AActor* InInteractActor) {
    return true;
}

void ACharacter_Player::AskForServerCancelInteractValidation_Implementation(AActor* InInteractActor, float InteractTime) {
}
bool ACharacter_Player::AskForServerCancelInteractValidation_Validate(AActor* InInteractActor, float InteractTime) {
    return true;
}

void ACharacter_Player::AskForPlayerReadyCount_Implementation(bool bPostOrderableActorsInit) {
}
bool ACharacter_Player::AskForPlayerReadyCount_Validate(bool bPostOrderableActorsInit) {
    return true;
}

bool ACharacter_Player::AlreadyHaveWeapon(AActor* Weapon) const {
    return false;
}

void ACharacter_Player::AddTriggerWeapon(UTrigger_Weapon* Trigger) {
}

void ACharacter_Player::AddTriggerSkill(UTrigger_Skill* Trigger) {
}

void ACharacter_Player::AddTrigger(UATriggerMultiple* Trigger) {
}

void ACharacter_Player::AddTicket(int32 AddTicketAmount, bool bStarting) {
}

void ACharacter_Player::AddSummonThreatModifier(float AddedSummonThreat) {
}

void ACharacter_Player::AddSummonLifetimeMultiplier(float AddValue) {
}

void ACharacter_Player::AddStaticCharges(int32 AddAmount) {
}

void ACharacter_Player::AddStaticCharge() {
}

void ACharacter_Player::AddStartingTicket(int32 AddTicketAmount) {
}

void ACharacter_Player::AddResistanceFeedback() {
}

void ACharacter_Player::AddPickupValueModifier(EPickup Type, float AddValue) {
}

void ACharacter_Player::AddNewCancelAction(EAction TargetAction, EAction NewCancelAction) {
}

void ACharacter_Player::AddNewBlockedAction(EAction TargetAction, EAction NewBlockedAction) {
}

void ACharacter_Player::AddMoveSpeedFeedback() {
}

void ACharacter_Player::AddMetaRewardLoot(const FName& RowName, EMetaRewardLootType RewardType) {
}

void ACharacter_Player::AddMaxStaticCharge(int32 AddAmount) {
}

void ACharacter_Player::AddJetpackFuel(float AddFuel) {
}

void ACharacter_Player::AddGlobalSummonStatModifier(UModifier_Stat* StatModifier) {
}

void ACharacter_Player::AddGlobalSummonDamageModifier(UModifier_Damage* DamageModifier) {
}

void ACharacter_Player::AddGlobalSpeedPower() {
}

void ACharacter_Player::AddGlobalMoveSpeedPower() {
}

void ACharacter_Player::AddGlobalDamagePower() {
}

void ACharacter_Player::AddFury(float Amount, bool bFromBoss) {
}

void ACharacter_Player::AddForbiddenAction(EAction Action, bool bCancel) {
}

void ACharacter_Player::AddExtraLife() {
}

void ACharacter_Player::AddDamageBarRegenerationByFury(float NewValue) {
}

void ACharacter_Player::AddDamageBarAmount(float AddAmount) {
}

void ACharacter_Player::AddCustomCurrency(ECustomCost Type, int32 AddValue) {
}

void ACharacter_Player::AddCrystalFound(const FName& LevelName) {
}

void ACharacter_Player::AddComboPoint(int32 AddAmount) {
}

void ACharacter_Player::AddBaseMoveSpeedModifier(float NewMoveSpeedModifier) {
}

void ACharacter_Player::AddArtefact(const FName& RowName, int32 RandomSeed) {
}

void ACharacter_Player::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ACharacter_Player, bIsActivate);
    DOREPLIFETIME(ACharacter_Player, CameraPitch);
    DOREPLIFETIME(ACharacter_Player, currentWeapon);
    DOREPLIFETIME(ACharacter_Player, isCrouchedPressed);
    DOREPLIFETIME(ACharacter_Player, CurrentElement);
}


