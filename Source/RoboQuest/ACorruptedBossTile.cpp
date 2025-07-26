#include "ACorruptedBossTile.h"

AACorruptedBossTile::AACorruptedBossTile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InteractiveCrystalRef = NULL;
}

void AACorruptedBossTile::OnExitingDoorCrossedByPlayer(AADoor* Door, ACharacter_Player* Player, const FVector& Forward) {
}


