#include "ACorruptedArenaTile.h"

AACorruptedArenaTile::AACorruptedArenaTile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LevelSequenceActor = NULL;
    this->InteractiveCrystalRef = NULL;
}

void AACorruptedArenaTile::StartSequence() {
}

void AACorruptedArenaTile::OnSequenceLoaded() {
}

void AACorruptedArenaTile::OnSequenceFinished() {
}

void AACorruptedArenaTile::OnSafeZoneDoorStateChanged(AADoor* Door, EDoorState NewState) {
}

void AACorruptedArenaTile::OnCorruptedArenaDoorOpened(AADoor* Door, EDoorState NewState) {
}


