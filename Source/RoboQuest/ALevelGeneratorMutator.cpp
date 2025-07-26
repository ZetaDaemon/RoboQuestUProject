#include "ALevelGeneratorMutator.h"

UALevelGeneratorMutator::UALevelGeneratorMutator() {
    this->ParentMutator = NULL;
    this->bAlreadyApplied = false;
    this->LevelGeneratorRef = NULL;
    this->GameStateRef = NULL;
}

void UALevelGeneratorMutator::OnApply_Implementation() {
}

AALevelGenerator* UALevelGeneratorMutator::GetLevelGeneratorRef() const {
    return NULL;
}

AAGameState* UALevelGeneratorMutator::GetGameStateRef() const {
    return NULL;
}

float UALevelGeneratorMutator::GetCustomFloatValue(FName PropertyName) const {
    return 0.0f;
}


