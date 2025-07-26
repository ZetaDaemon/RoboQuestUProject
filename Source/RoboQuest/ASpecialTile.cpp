#include "ASpecialTile.h"
#include "ETileType.h"
#include "Templates/SubclassOf.h"

AASpecialTile::AASpecialTile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Type = ETileType::Special;
    this->InteriorClassToSpawn = NULL;
    this->InteriorTileRef = NULL;
    this->bAllowInteriorMirrored = true;
    this->bInteriorMirrored = false;
    this->NavMeshSizeY = 0.00f;
}

void AASpecialTile::RegisterChest(AAChest* Chest) {
}

void AASpecialTile::OpenNextChest() {
}

void AASpecialTile::OnSpecialDoorOpenedAfterValidated(AADoor* Door, EDoorState NewState) {
}

void AASpecialTile::OnSpecialDoorOpened(AADoor* Door, EDoorState NewState) {
}

void AASpecialTile::OnSpecialDoorCrossedByPlayer(AADoor* Door, ACharacter_Player* Player, const FVector& ExitingForward) {
}

void AASpecialTile::OnSpecialDoorClosed(AADoor* Door, EDoorState NewState) {
}

void AASpecialTile::OnSpawnedEnemyDeath(AASpecialSpawner* SpecialSpawner, int32 DeadWaveID) {
}

void AASpecialTile::OnPlayerDisconnected(ACharacter_Player* DisconnectedPlayer) {
}

void AASpecialTile::OnPlayerDied(const FRQDamageInfo& DamageInfo) {
}

void AASpecialTile::OnEnterExitingJumpad() {
}

void AASpecialTile::OnEndTriggerOverlap(UPrimitiveComponent* OverlappedComp, AActor* OverlappedActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}



void AASpecialTile::OnBeginTriggerOverlap(UPrimitiveComponent* OverlappedComp, AActor* OverlappingActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

AActor* AASpecialTile::GetInteriorTile() const {
    return NULL;
}

void AASpecialTile::GetAllChildActorsFromInteriorTile(TSubclassOf<AActor> ActorClass, TArray<AActor*>& OutActors) const {
}


