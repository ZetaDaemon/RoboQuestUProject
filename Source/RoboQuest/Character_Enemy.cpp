#include "Character_Enemy.h"
#include "Net/UnrealNetwork.h"

ACharacter_Enemy::ACharacter_Enemy(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void ACharacter_Enemy::UnregisterHitDecalComponent(UHitDecalComponent* DecalComp) {
}


void ACharacter_Enemy::TryFindAllyToShield() {
}

void ACharacter_Enemy::StopHookPlayer() {
}

void ACharacter_Enemy::StopBeProjectile() {
}

bool ACharacter_Enemy::ShouldExplodeOnDeath() const {
    return false;
}

void ACharacter_Enemy::SetSlowState(bool bNewState) {
}

void ACharacter_Enemy::SetHealthBarVisibility(bool bVisible) {
}

void ACharacter_Enemy::SetFrozenState(bool bNewState) {
}

void ACharacter_Enemy::SetEnergizeState(bool bNewState) {
}


void ACharacter_Enemy::ResetDeathSFX() {
}

void ACharacter_Enemy::RemoveHeadbonkProtection_Implementation() {
}

void ACharacter_Enemy::RemoveEyeProtection_Implementation() {
}

void ACharacter_Enemy::RemoveElementalResistance() {
}

void ACharacter_Enemy::PlayDeathSFX(EDamageType DeathDamageType) {
}



void ACharacter_Enemy::OverrideDeathsFX(USoundCue* NewSound, UParticleSystem* NewFX) {
}

void ACharacter_Enemy::OnRepBuffedAllyInternal(ACharacter_Enemy* BuffedAlly) {
}

void ACharacter_Enemy::OnMulticastBoneDestroyed_Implementation(FName BoneName) {
}

void ACharacter_Enemy::OnEndHookPlayer_Implementation(bool bError) {
}

void ACharacter_Enemy::OnDetachPlayer_Implementation() {
}

void ACharacter_Enemy::OnCommonEnemyDataAssetLoaded() {
}

void ACharacter_Enemy::OnBuffedAllyDeath(const FRQDamageInfo& DamageInfo) {
}










void ACharacter_Enemy::OnAttachPlayer_Implementation(ACharacter_Player* InPlayer) {
}

void ACharacter_Enemy::OnAlerted(AActor* TargetActor) {
}

void ACharacter_Enemy::MulticastStartStateStun_Implementation(AACharacter* StunInstigator) {
}

void ACharacter_Enemy::MulticastStartStateStagger_Implementation(float NewApplyImpactForce, AACharacter* DamageInstigator) {
}

void ACharacter_Enemy::MulticastStartStateIce_Implementation(AACharacter* IceInstigator) {
}

void ACharacter_Enemy::MulticastStartHookPlayer_Implementation(ACharacter_Player* InPlayer) {
}

void ACharacter_Enemy::MulticastShieldAlly_Implementation(ACharacter_Enemy* NewShieldedAlly) {
}

void ACharacter_Enemy::MulticastSetMoveToAlly_Implementation(ACharacter_Enemy* NewAlly) {
}

void ACharacter_Enemy::MulticastEndBecameProjectile_Implementation() {
}

void ACharacter_Enemy::MulticastDetachPlayer_Implementation() {
}

void ACharacter_Enemy::MulticastBecameProjectile_Implementation() {
}

void ACharacter_Enemy::MulticastAttachPlayer_Implementation(ACharacter_Player* InPlayer) {
}

void ACharacter_Enemy::LootMaxHealthPickup(int32 Amount, bool bAutoGather) {
}

void ACharacter_Enemy::LootHealthPickup(int32 Amount, bool bAutoGather) {
}

void ACharacter_Enemy::LoopShieldDistance() {
}

void ACharacter_Enemy::LoadDashVFX(bool bPlayEventAfterLoading, float DashDuration) {
}

void ACharacter_Enemy::LoadDashSFX(bool bPlayEventAfterLoading) {
}

bool ACharacter_Enemy::IsValidAllyToBuff_Implementation(ACharacter_Enemy* EnemyRef) const {
    return false;
}

bool ACharacter_Enemy::IsTurretEmpowered() const {
    return false;
}

bool ACharacter_Enemy::IsElite() const {
    return false;
}

bool ACharacter_Enemy::IsAlwaysShielded() const {
    return false;
}

bool ACharacter_Enemy::HasHeadbonkBubble() const {
    return false;
}

bool ACharacter_Enemy::HasEyeProtection() const {
    return false;
}

bool ACharacter_Enemy::GrantXP() const {
    return false;
}

UAnimMontage* ACharacter_Enemy::GetStunAnimation_Implementation() const {
    return NULL;
}

UAnimMontage* ACharacter_Enemy::GetStaggerAnimation_Implementation(FRQDamageInfo DamageInfo) {
    return NULL;
}

UAnimMontage* ACharacter_Enemy::GetPatternDeathAnimation(const FName& Pattern) {
    return NULL;
}

int32 ACharacter_Enemy::GetLevel() const {
    return 0;
}

float ACharacter_Enemy::GetImpactResistanceMultiplayerScale_Implementation() {
    return 0.0f;
}

float ACharacter_Enemy::GetHealthMultiplayerScale_Implementation() {
    return 0.0f;
}

float ACharacter_Enemy::GetFocusDistance_Implementation() const {
    return 0.0f;
}

float ACharacter_Enemy::GetEnemyBaseTimeDilatation() {
    return 0.0f;
}

uint8 ACharacter_Enemy::GetEncounterID() const {
    return 0;
}

TArray<ACharacter_Enemy*> ACharacter_Enemy::GetCharactersInSquad() {
    return TArray<ACharacter_Enemy*>();
}


uint8 ACharacter_Enemy::GetAreaID() const {
    return 0;
}

bool ACharacter_Enemy::ContainBones(const TArray<FRQHitResult>& Results, const FName& BoneName) const {
    return false;
}

void ACharacter_Enemy::ClearLoots() {
}

bool ACharacter_Enemy::CanTriggerFocus() {
    return false;
}

bool ACharacter_Enemy::CanLoot() const {
    return false;
}

bool ACharacter_Enemy::CanBeJumped_Implementation() {
    return false;
}


void ACharacter_Enemy::ApplyStunImpact(float ImpactForce, AACharacter* DamageInstigator) {
}

void ACharacter_Enemy::ApplyImpactForce(float ImpactForce, AACharacter* DamageInstigator) {
}

void ACharacter_Enemy::ApplyIceImpact(float ImpactForce, AACharacter* DamageInstigator) {
}

void ACharacter_Enemy::ApplyFocusCooldown() {
}

void ACharacter_Enemy::ApplyDestructibleBoneDamage(FName BoneName, float DamageAmount) {
}

void ACharacter_Enemy::AddNewLoot(AActor* Loot) {
}

void ACharacter_Enemy::AddHeadbonkProtection_Implementation() {
}

void ACharacter_Enemy::AddEyeProtection_Implementation() {
}

void ACharacter_Enemy::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
}


