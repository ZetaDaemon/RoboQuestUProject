#include "AInteractiveLootable.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"

AAInteractiveLootable::AAInteractiveLootable(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PhysicMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PhysicMesh"));
    this->MultiplayerLoot = EMultiplayerLoot::Shared;
    this->PhysicsImpulseHeight = 650.00f;
    this->RandomPhysicsLateralImpulse = 250.00f;
    this->StopCalculatePhysicOffset = 50.00f;
    this->StartCalculateStopPhysicTime = 0.10f;
    this->GravityIncreaseRate = 12500.00f;
    this->MaxGravity = 3000.00f;
    this->PhysicMesh->SetupAttachment(RootComponent);
}


void AAInteractiveLootable::NotifyOnDestroy() {
}

bool AAInteractiveLootable::IsActiveLocally() {
    return false;
}

void AAInteractiveLootable::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAInteractiveLootable, MultiplayerLoot);
}


