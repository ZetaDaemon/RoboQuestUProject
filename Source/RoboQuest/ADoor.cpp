#include "ADoor.h"
#include "Components/BoxComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SkeletalMeshComponent -FallbackName=SkeletalMeshComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"

AADoor::AADoor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AADoor::UpdateMapIcon() {
}

void AADoor::UpdateLightColor(const FLinearColor& Color) {
}

void AADoor::UpdateDoorOnPlayerDisconnected(AController* ExitingPlayer) {
}

void AADoor::UnlockSecretDoor_Implementation(ACharacter_Player* PlayerCharacter) {
}

void AADoor::TryingToOpenCodeDoor() {
}

bool AADoor::ShouldInitSecretDoorState_Implementation() const {
    return false;
}

void AADoor::SetUnderConstruction() {
}

void AADoor::SetDoorWayBehavior(EDoorWayBehaviour Behaviour, bool bIsEntering) {
}

void AADoor::SetDoorState(EDoorState NewState) {
}

void AADoor::SetDoorDestination(EDoorDestination Destination) {
}

void AADoor::SetDoorBehaviour(EDoorBehaviour NewBehaviour) {
}

void AADoor::SetActivateCompassIcon(bool bActivate) {
}

void AADoor::RemovePlayerDisconnected(ACharacter_Player* DisconnectedPlayer) {
}

void AADoor::OnRepRealInteractedPlayers() {
}

void AADoor::OnQuestGoalValidated() {
}

void AADoor::OnPressedResetButton(AAInteractiveCodeButton* Button) {
}

void AADoor::OnPressedDigitButton(AAInteractiveCodeButton* Button) {
}

void AADoor::OnNavModifierClassLoaded() {
}

void AADoor::OnEndTriggerBoxOverlap(UPrimitiveComponent* OverlappedComp, AActor* OverlappedActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}










void AADoor::OnBeginTriggerBoxOverlap(UPrimitiveComponent* OverlappedComp, AActor* OverlappedActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

bool AADoor::IsOpen() const {
    return false;
}

void AADoor::InitSecretDoorState() {
}

void AADoor::InitSecretDoorDisplay() {
}

bool AADoor::HasCrossedDoor(ACharacter_Player* Player) const {
    return false;
}

FLinearColor AADoor::GetLightColorByDestination(EDoorDestination Destination) const {
    return FLinearColor{};
}

FVector AADoor::GetForwardDirection() const {
    return FVector{};
}

EDoorState AADoor::GetDoorState() const {
    return EDoorState::Opened;
}

FName AADoor::GetDoorPathLevelRowName() const {
    return NAME_None;
}

float AADoor::GetCrossedTeleportDistance_Implementation() const {
    return 0.0f;
}



void AADoor::DelayedFailInteract() {
}

void AADoor::DelayedDisableCompassWidgetTick() {
}

void AADoor::DelayedCodeSuccessState() {
}

void AADoor::DelayedCodeErrorState() {
}

bool AADoor::CanUnlockSecretDoor_Implementation(ACharacter_Player* PlayerCharacter) {
    return false;
}

void AADoor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AADoor, RealInteractedPlayers);
}


