#include "AMerchant_Loot.h"
#include "Net/UnrealNetwork.h"

AAMerchant_Loot::AAMerchant_Loot(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AAMerchant_Loot::UnregisterLoot(AActor* Loot) {
}

void AAMerchant_Loot::RegisterLoot(AActor* Loot) {
}

void AAMerchant_Loot::OnRepReplicatedLoot() {
}



TArray<AActor*> AAMerchant_Loot::GetLoots_Implementation(EMultiplayerLoot MultiplayerLoot) {
    return TArray<AActor*>();
}

uint8 AAMerchant_Loot::GetLootAmount_Implementation(EMultiplayerLoot MultiplayerLoot) {
    return 0;
}

uint8 AAMerchant_Loot::GetAllLootAmount_Implementation() {
    return 0;
}

void AAMerchant_Loot::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAMerchant_Loot, ReplicatedLoot);
}


