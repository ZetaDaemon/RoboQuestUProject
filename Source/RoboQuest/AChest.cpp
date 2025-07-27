#include "AChest.h"
#include "Net/UnrealNetwork.h"

AAChest::AAChest(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bLootFromQueue = true;
}

void AAChest::UnregisterLoot(AActor* Loot) {
}

void AAChest::RegisterLoot(AActor* Loot) {
}

void AAChest::OpenChest() {
}

void AAChest::OnRepReplicatedLoot() {
}




TArray<AActor*> AAChest::GetLoots_Implementation(EMultiplayerLoot MultiplayerLoot) {
    return TArray<AActor*>();
}

uint8 AAChest::GetLootAmount_Implementation(EMultiplayerLoot MultiplayerLoot) {
    return 0;
}

TArray<AActor*> AAChest::GetLocallyRegisteredLoots() {
    return TArray<AActor*>();
}

uint8 AAChest::GetAllLootAmount_Implementation() {
    return 0;
}

void AAChest::FakeRegisterLoot() {
}

void AAChest::DelayedActivateLootCollision() {
}

void AAChest::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAChest, ReplicatedLoot);
}


