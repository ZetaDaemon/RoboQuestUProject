#include "AMerchant.h"
#include "Components/BoxComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SkeletalMeshComponent -FallbackName=SkeletalMeshComponent

AAMerchant::AAMerchant(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AAMerchant::SetTickEnabled_Implementation(bool bEnable) {
}

void AAMerchant::OnUnloadPreviousLevel() {
}


bool AAMerchant::IsLocalInteraction() {
    return false;
}

ACharacter_Player* AAMerchant::GetLocalPlayerRef() const {
    return NULL;
}

AAPlayerController* AAMerchant::GetLocalPlayerControllerRef() const {
    return NULL;
}

AALevelGenerator* AAMerchant::GetLevelGeneratorRef() {
    return NULL;
}

AAGameState* AAMerchant::GetGameStateRef() {
    return NULL;
}

AAGameMode* AAMerchant::GetGameModeRef() {
    return NULL;
}

UAGameInstance* AAMerchant::GetGameInstanceRef() const {
    return NULL;
}

FString AAMerchant::GetDisplayName_Implementation() {
    return TEXT("");
}


