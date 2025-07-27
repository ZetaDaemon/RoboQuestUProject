#include "APlayerState.h"
#include "Net/UnrealNetwork.h"

AAPlayerState::AAPlayerState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StorePlatform = EStorePlatform::MAX;
}

void AAPlayerState::OnRep_StorePlatform() {
}

void AAPlayerState::OnRep_PlayerNameSuffix() {
}

EStorePlatform AAPlayerState::GetStorePlatform() const {
    return EStorePlatform::Steam;
}

FString AAPlayerState::GetPlayerNameSuffix() const {
    return TEXT("");
}

void AAPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAPlayerState, NameSuffixPrivate);
    DOREPLIFETIME(AAPlayerState, StorePlatform);
}


