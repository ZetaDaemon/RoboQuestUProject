#include "AWallTile.h"
#include "ETileType.h"

AAWallTile::AAWallTile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Type = ETileType::Wall;
}

void AAWallTile::OnSafeZoneDoorStateChanged(AADoor* Door, EDoorState NewState) {
}

void AAWallTile::OnDoorCrossedByPlayer(AADoor* Door, ACharacter_Player* Player, const FVector& ExitingForward) {
}


