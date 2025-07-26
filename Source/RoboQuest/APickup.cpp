#include "APickup.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ParticleSystemComponent -FallbackName=ParticleSystemComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=RotatingMovementComponent -FallbackName=RotatingMovementComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SphereComponent -FallbackName=SphereComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent

AAPickup::AAPickup(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    this->Mesh = (UStaticMeshComponent*)RootComponent;
    this->SphereTrigger = CreateDefaultSubobject<USphereComponent>(TEXT("SphereTrigger"));
    this->RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovement"));
    this->DisappearFXComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("DisappearFX"));
    this->Type = EPickup::Experience;
    this->Value = 1.00f;
    this->Lifetime = 6.00f;
    this->CollisionActivationDelay = 0.65f;
    this->GatherRange = 900.00f;
    this->bLocalPickup = false;
    this->LootedSound = NULL;
    this->GrantSound = NULL;
    this->bQueuedSound = false;
    this->bShouldAttract = true;
    this->AttractDuration = 0.30f;
    this->bInstantGrantBonus = true;
    this->AttractSound = NULL;
    this->bIsPhysic = true;
    this->ImpulseHeight = 550.00f;
    this->ImpulseStrength = 250.00f;
    this->bShouldHover = true;
    this->HoverHeight = 100.00f;
    this->HoverActivationDelay = 0.20f;
    this->bShouldRotate = false;
    this->RotateSpeed = 180.00f;
    this->OverlappedPlayer = NULL;
    this->AttractPlayer = NULL;
    this->BlowerImpulseMultiplier = 50.00f;
    this->LevelGeneratorRef = NULL;
    this->GameStateRef = NULL;
    this->DisappearFXComponent->SetupAttachment(RootComponent);
    this->SphereTrigger->SetupAttachment(RootComponent);
}

void AAPickup::OnPlayerOverlap(ACharacter_Player* Player) {
}

void AAPickup::OnGrantPickup_Implementation(ACharacter_Player* Player) {
}

void AAPickup::OnEndLifetime_Implementation() {
}

void AAPickup::OnEndAttract(int32 Linkage) {
}

void AAPickup::OnDestroy() {
}



void AAPickup::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

float AAPickup::GetLifetime() const {
    return 0.0f;
}

AALevelGenerator* AAPickup::GetLevelGeneratorRef() const {
    return NULL;
}

AAGameState* AAPickup::GetGameStateRef() const {
    return NULL;
}

float AAPickup::GetCurrentLifetime() const {
    return 0.0f;
}


