#include "LevelGeneratorMutatorRow.h"

FLevelGeneratorMutatorRow::FLevelGeneratorMutatorRow() {
    this->Type = EMutatorType::Main;
    this->bIsActive = false;
    this->bScalableDescription = false;
    this->bStartActive = false;
    this->bStartActiveWithAllLinked = false;
    this->bStartActiveInBuild = false;
}

