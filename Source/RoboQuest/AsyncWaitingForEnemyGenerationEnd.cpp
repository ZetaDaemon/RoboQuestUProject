#include "AsyncWaitingForEnemyGenerationEnd.h"

UAsyncWaitingForEnemyGenerationEnd::UAsyncWaitingForEnemyGenerationEnd() {
    this->WorldContextObject = NULL;
    this->LevelGeneratorRef = NULL;
}

void UAsyncWaitingForEnemyGenerationEnd::OnEnemyGenerationEnd() {
}

UAsyncWaitingForEnemyGenerationEnd* UAsyncWaitingForEnemyGenerationEnd::AsyncWaitingForEnemyGenerationEnd(UObject* NewWorldContextObject, AALevelGenerator* LevelGenerator) {
    return NULL;
}


