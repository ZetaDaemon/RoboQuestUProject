#include "LoadObjectForUIWithTimer.h"

ULoadObjectForUIWithTimer::ULoadObjectForUIWithTimer() {
    this->WorldContextObject = NULL;
}

void ULoadObjectForUIWithTimer::OnObjectLoaded() {
}

ULoadObjectForUIWithTimer* ULoadObjectForUIWithTimer::LoadObjectForUIWithTimer(UObject* NewWorldContextObject, TSoftObjectPtr<UObject> ObjectPtr, int32 AsyncLoadPriority) {
    return NULL;
}


