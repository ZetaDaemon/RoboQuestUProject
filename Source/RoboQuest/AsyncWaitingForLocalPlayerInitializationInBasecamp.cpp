#include "AsyncWaitingForLocalPlayerInitializationInBasecamp.h"

UAsyncWaitingForLocalPlayerInitializationInBasecamp::UAsyncWaitingForLocalPlayerInitializationInBasecamp() {
    this->WorldContextObject = NULL;
    this->GameStateRef = NULL;
}

void UAsyncWaitingForLocalPlayerInitializationInBasecamp::OnLocalPlayerInitializationInBasecamp() {
}

UAsyncWaitingForLocalPlayerInitializationInBasecamp* UAsyncWaitingForLocalPlayerInitializationInBasecamp::AsyncWaitingForLocalPlayerInitializationInBasecamp(UObject* NewWorldContextObject, AAGameState* GameState) {
    return NULL;
}


