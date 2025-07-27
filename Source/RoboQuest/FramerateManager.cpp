#include "FramerateManager.h"

AFramerateManager::AFramerateManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FramesBeforePrint = 0;
    this->FramerateMinBeforeWarning = 0;
}

void AFramerateManager::ToggleFramerateCounter(bool bIsDisplay) {
}

void AFramerateManager::OnChangeTile(AATile* OldTile, AATile* NewTile) {
}


