#include "AsyncLoadObjectsWithTimer.h"

UAsyncLoadObjectsWithTimer::UAsyncLoadObjectsWithTimer() {
    this->WorldContextObject = NULL;
}

void UAsyncLoadObjectsWithTimer::OnObjectsLoaded() {
}

UAsyncLoadObjectsWithTimer* UAsyncLoadObjectsWithTimer::AsyncLoadObjectsWithTimer(UObject* NewWorldContextObject, const TArray<TSoftObjectPtr<UObject>>& ObjectsPtrArray, int32 AsyncLoadPriority) {
    return NULL;
}


