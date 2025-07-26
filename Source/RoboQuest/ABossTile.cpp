#include "ABossTile.h"
#include "ETileType.h"

AABossTile::AABossTile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Type = ETileType::Boss;
    this->BossLayer = NULL;
    this->BossClass = NULL;
    this->bIsBossCombatStarted = false;
    this->bInstantFadeToBlackOnBossDeath = false;
    this->LevelSequenceActor = NULL;
}

void AABossTile::TeleportPlayersToBossCombat() {
}

void AABossTile::StartSequence() {
}

void AABossTile::StartBossCombat() {
}

void AABossTile::ResurrectDeadPlayersOnBossDeath() {
}

void AABossTile::OnSkeletalMeshOwnerDestroyed(AActor* Actor) {
}

void AABossTile::OnSequenceFinished() {
}

void AABossTile::OnSafeZoneDoorStateChanged(AADoor* Door, EDoorState NewState) {
}

void AABossTile::OnBossStatChanged(EStat Stat, float currentValue, float Value) {
}

void AABossTile::OnBossDoorOpened(AADoor* Door, EDoorState NewState) {
}

void AABossTile::OnBossDeath(const FRQDamageInfo& DamageInfo) {
}


bool AABossTile::HasABoss() const {
    return false;
}

ACharacter_Enemy* AABossTile::GetFirstBossRef() const {
    return NULL;
}

float AABossTile::GetFadeToBlackDelayAfterBossDeath_Implementation() const {
    return 0.0f;
}

FName AABossTile::GetBossRowName() const {
    return NAME_None;
}

FName AABossTile::GetBossName() const {
    return NAME_None;
}

AActor* AABossTile::GetBossLayer() const {
    return NULL;
}

uint8 AABossTile::GetBossEncounterID() const {
    return 0;
}

void AABossTile::DisplayBossHealthBar() {
}

void AABossTile::DisablePlayersInputThenStartSequence(bool bStartSequence) {
}

void AABossTile::DelayedFadeToBlack() {
}

void AABossTile::DelayedBossAIActivation() {
}

void AABossTile::BindEventsAndDeactivateBoss(ACharacter_Enemy* Boss) {
}


