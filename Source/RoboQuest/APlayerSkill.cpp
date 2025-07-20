#include "APlayerSkill.h"

UAPlayerSkill::UAPlayerSkill(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RaycastTrailEmiterBeamIndex.AddDefaulted(1);
    this->bOnlySecondaryDescription = false;
    this->bPlayerSkill = false;
    this->bWarmup = false;
    this->bBurstFire = false;
    this->bChargedFire = false;
    this->bOverheat = false;
    this->bBashSkill = false;
    this->bCustomNetworkReplication = false;
    this->bDualFire = false;
    this->bClassSkill = false;
    this->bScope = false;
    this->bCooling = false;
    this->PlayerOwner = NULL;
    this->WeaponOwner = NULL;
    this->bInfiniteCooldownWhenTimePaused = false;
    this->bGameTimePaused = false;
    this->CurrentStack = 0;
    this->BaseCooldown = 0.00f;
    this->BaseStackAmount = 0;
    this->StackAmount = 0;
    this->bNoCostForNextShot = false;
    this->CoolingPerShot = 0.00f;
    this->CoolingPerShotModifier = 0.00f;
    this->ClassSkillModuleUseAnmation = NULL;
    this->ClassSkillModuleMesh = NULL;
    this->ClassSkillModuleAnimBlueprint = NULL;
    this->bAimAssist = false;
    this->FirstHitAmount = 1;
    this->AddHitAmount = 1;
    this->MaxHitAmount = 1;
    this->CriticalHitAmount = 1;
    this->bCanCritical = false;
    this->bAutomaticFireRecover = false;
    this->LateralRecoilPerShot = 0.00f;
    this->RecoilUpSpeed = 0.00f;
    this->RecoilUpMultiplierPerSecond = 0.00f;
    this->LateralRecoilSpeed = 0.00f;
    this->MinRecoilUpRatio = 0.00f;
    this->ChargeLoopSoundComponent = NULL;
    this->ChargeStartSound = NULL;
    this->ChargeLoopSound = NULL;
    this->bStopChargeLoopWhenMax = false;
    this->MaxChargeSound = NULL;
    this->ChargeDuration = 0.00f;
    this->bAutoReleaseOnMaxCharge = false;
    this->bIsChargeUp = false;
    this->CurrentCharge = 0.00f;
    this->MinDamageRatio = 1.00f;
    this->MinImpactRatio = 1.00f;
    this->WarmupFirerateModifier = NULL;
    this->ChargeType = EChargeType::Warmup;
    this->OverheatPerShot = 0.00f;
    this->AutomaticFire_Shake = NULL;
    this->CharacterChargedBlendSpace = NULL;
    this->WeaponChargedBlendSpace = NULL;
    this->bUseAnimNotify = false;
    this->bWaitForNotify = false;
    this->ChargeFX = NULL;
    this->SmokeFX = NULL;
    this->BaseMuzzleInstantFX = NULL;
    this->MuzzleInstantFX = NULL;
    this->MuzzleInstantFXScale = 1.00f;
    this->CastSound = NULL;
    this->HapticCastSound = NULL;
    this->HapticUseSound = NULL;
}

void UAPlayerSkill::UpdateStackAmount(int32 NewAddStack) {
}

void UAPlayerSkill::StoreSkillRow(FPlayerSkillRow& SkillRow, bool bIsInit) {
}

bool UAPlayerSkill::ShouldUseAnimationNotify_Implementation() {
    return false;
}

void UAPlayerSkill::SetUseSoundParameter_Implementation(UAudioComponent* InSound) {
}

void UAPlayerSkill::SetCastSoundParameter_Implementation(UAudioComponent* InSound) {
}

void UAPlayerSkill::SecurityAnimNotify() {
}

void UAPlayerSkill::RemoveWarmupState() {
}

void UAPlayerSkill::RemoveStack() {
}

void UAPlayerSkill::RemoveCustomStack() {
}

void UAPlayerSkill::OnUseSkill(const FNetworkSkillInfo& NetworkInfo) {
}

void UAPlayerSkill::OnServerUseSkill_Implementation(const FNetworkSkillInfo& NetworkInfo) {
}
bool UAPlayerSkill::OnServerUseSkill_Validate(const FNetworkSkillInfo& NetworkInfo) {
    return true;
}

void UAPlayerSkill::OnServerSetCalculateCharge_Implementation(bool bIsUp) {
}
bool UAPlayerSkill::OnServerSetCalculateCharge_Validate(bool bIsUp) {
    return true;
}

void UAPlayerSkill::OnServerPlayAnimNotify_Implementation() {
}
bool UAPlayerSkill::OnServerPlayAnimNotify_Validate() {
    return true;
}

void UAPlayerSkill::OnReceptAnimNotify() {
}


void UAPlayerSkill::OnMulticastUseSkill_Implementation(const FNetworkSkillInfo& NetworkInfo) {
}

void UAPlayerSkill::OnMulticastSetCalculateCharge_Implementation(bool bIsUp) {
}

void UAPlayerSkill::OnMulticastPlayAnimNotify_Implementation() {
}

void UAPlayerSkill::OnGameTimePaused_Implementation(bool bNewPaused) {
}

void UAPlayerSkill::OnCommonPlayerSkillDataAssetLoaded() {
}



void UAPlayerSkill::MaximiseStack() {
}

void UAPlayerSkill::InitWarmupState(float WarmupDuration, UCurveFloat* WarmupCurve, bool bModifyPitch) {
}

void UAPlayerSkill::InitializeGameTimePausedDelegate() {
}

void UAPlayerSkill::InitializeCustomStack(int32 Amount, float Cooldown) {
}

bool UAPlayerSkill::HaveCost() {
    return false;
}

bool UAPlayerSkill::HaveChargeDuration() const {
    return false;
}

AAWeapon* UAPlayerSkill::GetWeapon() const {
    return NULL;
}

FAnimation UAPlayerSkill::GetSkillAnimation_Implementation() {
    return FAnimation{};
}

float UAPlayerSkill::GetProjectileCustomArc_Implementation() const {
    return 0.0f;
}

ACharacter_Player* UAPlayerSkill::GetPlayer() const {
    return NULL;
}

UParticleSystem* UAPlayerSkill::GetElementalParticle(UParticleSystem* BaseParticle, const TArray<EElement>& ElementOrder, AAProjectile* Projectile) const {
    return NULL;
}

float UAPlayerSkill::GetChargeRatio() {
    return 0.0f;
}

float UAPlayerSkill::GetChargeDuration() const {
    return 0.0f;
}

float UAPlayerSkill::GetBaseChargeDuration() {
    return 0.0f;
}

float UAPlayerSkill::GetAnimationPlayrate_Implementation() {
    return 0.0f;
}

void UAPlayerSkill::ConsumeStack() {
}

void UAPlayerSkill::AddStack() {
}


