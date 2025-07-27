#include "AsyncWaitingForWeaponInitialization.h"

UAsyncWaitingForWeaponInitialization::UAsyncWaitingForWeaponInitialization() {
    this->WorldContextObject = NULL;
    this->WeaponRef = NULL;
}

void UAsyncWaitingForWeaponInitialization::OnWeaponInitialized(AAWeapon* Weapon) {
}

UAsyncWaitingForWeaponInitialization* UAsyncWaitingForWeaponInitialization::AsyncWaitingForWeaponInitialization(UObject* NewWorldContextObject, AAWeapon* Weapon) {
    return NULL;
}


