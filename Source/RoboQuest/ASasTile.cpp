#include "ASasTile.h"
#include "ETileType.h"

AASasTile::AASasTile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Type = ETileType::Sas;
    this->ElementalSwitcherRef = NULL;
}

void AASasTile::OnSwitchElement(EElement NewElement) {
}

void AASasTile::OnPlayerStartEnteringSafeZoneDoor(AADoor* Door, ACharacter_Player* Player) {
}

void AASasTile::OnExitingSafeZoneDoorToMainOrSidePathOpened(AADoor* Door, EDoorState NewState) {
}

void AASasTile::OnExitingSafeZoneDoorToMainOrSidePathClosed(AADoor* Door, EDoorState NewState) {
}

void AASasTile::OnEnteringSafeZoneDoorStateChanged(AADoor* Door, EDoorState NewState) {
}

void AASasTile::DelayedNotifySasDoorIsClosed(AADoor* ClosedDoor) {
}


