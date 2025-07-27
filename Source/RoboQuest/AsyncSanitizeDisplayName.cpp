#include "AsyncSanitizeDisplayName.h"

UAsyncSanitizeDisplayName::UAsyncSanitizeDisplayName() {
    this->WorldContextObject = NULL;
}

void UAsyncSanitizeDisplayName::OnNameSanitized(bool Success, const FString& SanitizedName) {
}

UAsyncSanitizeDisplayName* UAsyncSanitizeDisplayName::AsyncSanitizeDisplayName(UObject* NewWorldContextObject, const FString& DisplayName) {
    return NULL;
}


