#include "AsyncLoadClassWithTimer.h"

UAsyncLoadClassWithTimer::UAsyncLoadClassWithTimer() {
    this->WorldContextObject = NULL;
}

void UAsyncLoadClassWithTimer::OnClassLoaded() {
}

UAsyncLoadClassWithTimer* UAsyncLoadClassWithTimer::AsyncLoadClassWithTimer(UObject* NewWorldContextObject, TSoftClassPtr<UObject> AssetClass, int32 AsyncLoadPriority) {
    return NULL;
}


