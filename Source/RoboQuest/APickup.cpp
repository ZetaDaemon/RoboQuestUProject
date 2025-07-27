#include "APickup.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ParticleSystemComponent -FallbackName=ParticleSystemComponent
#include "Particles/ParticleSystemComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=RotatingMovementComponent -FallbackName=RotatingMovementComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SphereComponent -FallbackName=SphereComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Components/StaticMeshComponent.h"

AAPickup::AAPickup(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
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


