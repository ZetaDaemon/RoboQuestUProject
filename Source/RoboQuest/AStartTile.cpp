#include "AStartTile.h"
#include "ETileType.h"

AAStartTile::AAStartTile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Type = ETileType::Start;
    this->CorruptedLavaTrap = NULL;
}

void AAStartTile::OnStartDoorStateChanged(AADoor* Door, EDoorState NewState) {
}

void AAStartTile::OnChestHasRegisteredAllLoot() {
}

void AAStartTile::OnChestDestroyed(AActor* Actor) {
}

void AAStartTile::DelayedNotifyStartDoorIsClosed(AADoor* ClosedDoor) {
}


