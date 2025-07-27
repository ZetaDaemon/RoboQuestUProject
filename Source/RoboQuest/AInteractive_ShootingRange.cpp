#include "AInteractive_ShootingRange.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Components/StaticMeshComponent.h"

AAInteractive_ShootingRange::AAInteractive_ShootingRange(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MeshRoot = CreateDefaultSubobject<USceneComponent>(TEXT("MeshRoot"));
    this->CollisionMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CollisionMeshComponent"));
    this->StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
    this->LockedMesh = NULL;
    this->UnlockedMesh = NULL;
    this->CollisionMesh = NULL;
    this->MeshRoot->SetupAttachment(RootComponent);
    this->CollisionMeshComponent->SetupAttachment(MeshRoot);
    this->StaticMeshComponent->SetupAttachment(MeshRoot);
}

void AAInteractive_ShootingRange::InitializeMesh_Implementation(bool bUnlocked) {
}


