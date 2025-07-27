#include "AsyncWaitingForLevelGeneratorInitialization.h"

UAsyncWaitingForLevelGeneratorInitialization::UAsyncWaitingForLevelGeneratorInitialization() {
    this->WorldContextObject = NULL;
    this->LevelGeneratorRef = NULL;
}

void UAsyncWaitingForLevelGeneratorInitialization::OnGeneratorDataAssetLoaded() {
}

UAsyncWaitingForLevelGeneratorInitialization* UAsyncWaitingForLevelGeneratorInitialization::AsyncWaitingForLevelGeneratorInitialization(UObject* NewWorldContextObject, AALevelGenerator* LevelGenerator) {
    return NULL;
}


