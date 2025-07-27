#include "APickupPoint.h"

AAPickupPoint::AAPickupPoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAutoDestroyOnClient = false;
    this->Location = EPickupLocation::Entering;
    this->GameStateRef = NULL;
}


