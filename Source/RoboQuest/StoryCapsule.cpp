#include "StoryCapsule.h"

FStoryCapsule::FStoryCapsule() {
    this->Date = 0;
    this->DateIndex = 0;
    this->Location = EStoryLocation::Anywhere;
    this->bSpawnOnAnotherSlot = false;
    this->bActive = false;
}

