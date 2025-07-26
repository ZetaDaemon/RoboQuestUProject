#include "ACorruptedEndTile.h"

AACorruptedEndTile::AACorruptedEndTile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InteractiveBombRef = NULL;
    this->InteractiveCrystalRef = NULL;
}

void AACorruptedEndTile::SafetyForceOpenCrystalDoor(ACharacter_Player* Player) {
}

void AACorruptedEndTile::OnTimeElapsed() {
}

void AACorruptedEndTile::OnTileValidated() {
}

void AACorruptedEndTile::OnPlayerStartEnteringExitingDoor(AADoor* Door, ACharacter_Player* Player) {
}

void AACorruptedEndTile::OnExitingDoorCrossedByPlayer(AADoor* Door, ACharacter_Player* Player, const FVector& Forward) {
}

void AACorruptedEndTile::OnExitingDoorClosed(AADoor* Door, EDoorState NewState) {
}

void AACorruptedEndTile::OnEnteringDoorOpened(AADoor* Door, EDoorState NewState) {
}


