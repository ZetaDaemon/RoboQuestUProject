#include "AsyncLoadPrimaryAssetWithTimer.h"

UAsyncLoadPrimaryAssetWithTimer::UAsyncLoadPrimaryAssetWithTimer() {
    this->WorldContextObject = NULL;
}

void UAsyncLoadPrimaryAssetWithTimer::OnDataAssetLoaded() {
}

UAsyncLoadPrimaryAssetWithTimer* UAsyncLoadPrimaryAssetWithTimer::AsyncLoadPrimaryAssetWithTimer(UObject* NewWorldContextObject, FPrimaryAssetId PrimaryAsset, const TArray<FName>& LoadBundles) {
    return NULL;
}


