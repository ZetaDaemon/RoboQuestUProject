#include "ADoor.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BoxComponent -FallbackName=BoxComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SkeletalMeshComponent -FallbackName=SkeletalMeshComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Net/UnrealNetwork.h"

AADoor::AADoor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
    this->PathBlocker = CreateDefaultSubobject<UBoxComponent>(TEXT("PathBlocker"));
    this->TriggerBox1 = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox1"));
    this->TriggerBox2 = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox2"));
    this->OneWayCollision = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OneWayCollision"));
    this->HitBlocker = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HitBlocker"));
    this->HitBlockerBack = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HitBlockerBack"));
    this->UnderConstruction = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UnderConstruction"));
    this->UnderConstructionBack = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UnderConstructionBack"));
    this->StaticMeshBlocker = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshBlocker"));
    this->TutoBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TutoBox"));
    this->ConnectorDirection = EDirection::LastIndex;
    this->UnlockSound = NULL;
    this->UnlockAudioComponent = NULL;
    this->EnteringTriggerBox = NULL;
    this->bForceOpenBehavior = false;
    this->bForceCloseBehavior = false;
    this->DoorBehaviour = EDoorBehaviour::Normal;
    this->CurrentDestination = EDoorDestination::LastIndex;
    this->bIsUnderConstruction = false;
    this->bIsSpecialDoor = false;
    this->bIsSpecialDoorValidated = false;
    this->bIsBossDoor = false;
    this->bIsInfiniteInteriorBossDoor = false;
    this->bIsCodeDoor = false;
    this->DigitsCount = 3;
    this->Code = 0;
    this->CodeScreenRef = NULL;
    this->TutoDoorType = ETutoDoorType::NotInTuto;
    this->bWaitingMultiplayer = false;
    this->RegularDoorIcon = NULL;
    this->LockedDoorIcon = NULL;
    this->LockedBySecretDoorIcon = NULL;
    this->SpecialDoorIcon = NULL;
    this->SpecialDoorValidatedIcon = NULL;
    this->BossDoorIcon = NULL;
    this->UnderConstructionIcon = NULL;
    this->bSecretDoor = false;
    this->SecretUnlockMontage = NULL;
    this->SecretDoor = EPermanentReward::LastIndex;
    this->SecretKey = EPermanentReward::LastIndex;
    this->SecretIcon = NULL;
    this->SecretIconScale = 1.00f;
    this->bForceUnlockRewardForAllPlayers = false;
    this->bIsQuestGoalDoor = false;
    this->NavModifier = NULL;
    this->PathBlocker->SetupAttachment(RootComponent);
    this->TriggerBox1->SetupAttachment(RootComponent);
    this->TriggerBox2->SetupAttachment(RootComponent);
    this->OneWayCollision->SetupAttachment(RootComponent);
    this->HitBlocker->SetupAttachment(RootComponent);
    this->HitBlockerBack->SetupAttachment(RootComponent);
    this->UnderConstruction->SetupAttachment(RootComponent);
    this->UnderConstructionBack->SetupAttachment(RootComponent);
    this->StaticMeshBlocker->SetupAttachment(RootComponent);
    this->TutoBox->SetupAttachment(RootComponent);
    this->Mesh->SetupAttachment(RootComponent);
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


