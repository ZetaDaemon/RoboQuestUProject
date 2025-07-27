#include "AsyncWaitingForPlayerInitialization.h"

UAsyncWaitingForPlayerInitialization::UAsyncWaitingForPlayerInitialization() {
    this->WorldContextObject = NULL;
    this->PlayerControllerRef = NULL;
}

void UAsyncWaitingForPlayerInitialization::OnPlayerInitialized() {
}

void UAsyncWaitingForPlayerInitialization::OnPlayerAssigned() {
}

UAsyncWaitingForPlayerInitialization* UAsyncWaitingForPlayerInitialization::AsyncWaitingForPlayerInitialization(UObject* NewWorldContextObject, AAPlayerController* PlayerController) {
    return NULL;
}


