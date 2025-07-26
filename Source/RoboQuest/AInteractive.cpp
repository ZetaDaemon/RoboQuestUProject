#include "AInteractive.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BoxComponent -FallbackName=BoxComponent
#include "Net/UnrealNetwork.h"

AAInteractive::AAInteractive(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AAInteractive::UpdateHoverWidgetRotationAnim(const FVector& Rotation) {
}

void AAInteractive::UpdateHoverWidgetLocationAnim(const FVector& Location) {
}

void AAInteractive::UpdateHoverMeshRotationAnim(const FVector& Rotation) {
}

void AAInteractive::UpdateHoverMeshLocationAnim(const FVector& Location) {
}

bool AAInteractive::TryingToDestroy(bool bForceDestroy) {
    return false;
}

void AAInteractive::StopHoverAnim() {
}

void AAInteractive::StartHoverAnim() {
}

void AAInteractive::StartDiscoveryState_Implementation() {
}

void AAInteractive::SimulateOnPlayerInteract(ACharacter_Player* PlayerCharacter) {
}

void AAInteractive::SetTickEnabled_Implementation(bool bEnable) {
}


void AAInteractive::SetActiveReplicatedActorState() {
}

void AAInteractive::RemoveTicketCost() {
}

void AAInteractive::RemoveCustomCost() {
}

void AAInteractive::OnWidgetCompassLoaded(UUserWidget* NewWidget) {
}

void AAInteractive::OnUnloadPreviousLevel() {
}

void AAInteractive::OnTimerPingEnd() {
}

void AAInteractive::OnStartInteract_Implementation(ACharacter_Player* PlayerCharacter) {
}

void AAInteractive::OnPlayerDisconnected(ACharacter_Player* DisconnectedPlayer) {
}

void AAInteractive::OnMulticastStartInteract_Implementation(ACharacter_Player* PlayerCharacter) {
}

void AAInteractive::OnMulticastMultiplayerInteract_Implementation(ACharacter_Player* PlayerCharacter, bool bIsServerPlayer) {
}

void AAInteractive::OnMulticastDeactivateInteractive_Implementation(bool bHide) {
}

void AAInteractive::OnMulticastActivateInteractive_Implementation(bool bShow) {
}






bool AAInteractive::IsLocalInteraction() {
    return false;
}

void AAInteractive::InitTicketCost(int32 NewTicketCost) {
}

void AAInteractive::InitCustomCost(ECustomCost Type, int32 NewCustomCost) {
}

UPrimitiveComponent* AAInteractive::GetPrimitiveComponent_Implementation() {
    return NULL;
}

AATile* AAInteractive::GetParentTile() {
    return NULL;
}

UAMapLocator* AAInteractive::GetMapLocator_Implementation() const {
    return NULL;
}

ACharacter_Player* AAInteractive::GetLocalPlayerRef() const {
    return NULL;
}

AAPlayerController* AAInteractive::GetLocalPlayerControllerRef() const {
    return NULL;
}

AALevelGenerator* AAInteractive::GetLevelGeneratorRef() const {
    return NULL;
}

USoundCue* AAInteractive::GetInteractSound_Implementation(ACharacter_Player* PlayerCharacter) {
    return NULL;
}

USceneComponent* AAInteractive::GetHoveringWidgetComponent_Implementation() const {
    return NULL;
}

USceneComponent* AAInteractive::GetHoveringMeshComponent_Implementation() const {
    return NULL;
}

AAGameState* AAInteractive::GetGameStateRef() const {
    return NULL;
}



FString AAInteractive::GetDisplayName_Implementation() {
    return TEXT("");
}

void AAInteractive::DeactivateInteractive_Implementation(bool bHide) {
}

void AAInteractive::ActivateInteractive_Implementation(bool bShow) {
}

void AAInteractive::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAInteractive, bStartDeactivate);
}


