#include "AStoryTile.h"
#include "ETileType.h"

AAStoryTile::AAStoryTile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Type = ETileType::Story;
}

void AAStoryTile::OnSafeZoneDoorStateChanged(AADoor* Door, EDoorState NewState) {
}


