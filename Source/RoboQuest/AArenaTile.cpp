#include "AArenaTile.h"

AAArenaTile::AAArenaTile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bIsSecondArenaMoon = false;
}

void AAArenaTile::OnValidatedDoorCrossedByPlayer(AADoor* Door, ACharacter_Player* Player, const FVector& Forward) {
}

void AAArenaTile::OnInvulnerableEnemyDestroyed(AActor* Actor) {
}

void AAArenaTile::OnExitingArenaDoorStateChanged(AADoor* Door, EDoorState NewState) {
}

void AAArenaTile::OnEnteringArenaDoorOpened(AADoor* Door, EDoorState NewState) {
}

void AAArenaTile::OnEnteringArenaDoorClosed(AADoor* Door, EDoorState NewState) {
}

void AAArenaTile::OnEnemyStatChanged(EStat Stat, float currentValue, float Value) {
}

void AAArenaTile::OnEnemyDeath(const FRQDamageInfo& DamageInfo) {
}

void AAArenaTile::OnArenaSpawnerAvailabilityChanged(bool bIsAvailable, EArenaSpawnerType SpawnerType) {
}

void AAArenaTile::CheckArenaTimerValidation() {
}

void AAArenaTile::BindEventsOnEnemyEndInitialization(ACharacter_Enemy* Enemy) {
}

void AAArenaTile::ActivateReinforcementEnemy() {
}


