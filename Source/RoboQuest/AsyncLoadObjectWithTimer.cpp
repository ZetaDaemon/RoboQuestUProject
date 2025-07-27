#include "AsyncLoadObjectWithTimer.h"

UAsyncLoadObjectWithTimer::UAsyncLoadObjectWithTimer() {
    this->WorldContextObject = NULL;
}

void UAsyncLoadObjectWithTimer::OnObjectLoaded() {
}

UAsyncLoadObjectWithTimer* UAsyncLoadObjectWithTimer::AsyncLoadObjectWithTimer(UObject* NewWorldContextObject, TSoftObjectPtr<UObject> ObjectPtr, int32 AsyncLoadPriority) {
    return NULL;
}


