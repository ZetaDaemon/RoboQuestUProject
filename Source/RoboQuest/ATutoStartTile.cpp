#include "ATutoStartTile.h"

AATutoStartTile::AATutoStartTile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SpecialDoorClass = NULL;
    this->InteriorClassToSpawn = NULL;
    this->InteriorTileRef = NULL;
    this->TutoSpecialDoor = NULL;
}

void AATutoStartTile::RegisterChest(AAChest* Chest) {
}

void AATutoStartTile::OpenNextChest() {
}

void AATutoStartTile::OnSpecialDoorOpened(AADoor* Door, EDoorState NewState) {
}

void AATutoStartTile::OnSpecialDoorCrossedByPlayer(AADoor* Door, ACharacter_Player* Player, const FVector& ExitingForward) {
}

void AATutoStartTile::OnSpecialDoorClosed(AADoor* Door, EDoorState NewState) {
}



void AATutoStartTile::OnBeginTriggerOverlap(UPrimitiveComponent* OverlappedComp, AActor* OverlappingActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

AADoor* AATutoStartTile::GetTutoSpecialDoor() const {
    return NULL;
}

AActor* AATutoStartTile::GetInteriorTile() const {
    return NULL;
}


