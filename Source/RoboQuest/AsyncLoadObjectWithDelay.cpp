#include "AsyncLoadObjectWithDelay.h"

UAsyncLoadObjectWithDelay::UAsyncLoadObjectWithDelay() {
    this->WorldContextObject = NULL;
}

void UAsyncLoadObjectWithDelay::OnObjectLoaded() {
}

void UAsyncLoadObjectWithDelay::CompleteLoading() {
}

UAsyncLoadObjectWithDelay* UAsyncLoadObjectWithDelay::AsyncLoadObjectWithDelay(UObject* NewWorldContextObject, TSoftObjectPtr<UObject> ObjectPtr, float DelayBeforeComplete, int32 AsyncLoadPriority) {
    return NULL;
}


