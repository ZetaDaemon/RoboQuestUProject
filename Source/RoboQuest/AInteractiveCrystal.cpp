#include "AInteractiveCrystal.h"

AAInteractiveCrystal::AAInteractiveCrystal(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bWasCrystalFound = false;
    this->bWasCrystalFoundByAllPlayers = false;
}


FName AAInteractiveCrystal::GetLevelName_Implementation() const {
    return NAME_None;
}

FCrystalRow AAInteractiveCrystal::GetCrystalDataFromLevel() {
    return FCrystalRow{};
}


