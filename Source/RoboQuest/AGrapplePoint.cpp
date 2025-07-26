#include "AGrapplePoint.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SphereComponent -FallbackName=SphereComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent

AAGrapplePoint::AAGrapplePoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    this->Root = (USceneComponent*)RootComponent;
    this->HookPoint = CreateDefaultSubobject<USphereComponent>(TEXT("HookPoint"));
    this->Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    this->HookPointType = EHookPointType::Act1;
    this->MeshByType[0] = NULL;
    this->MeshByType[1] = NULL;
    this->MeshByType[2] = NULL;
    this->MeshByType[3] = NULL;
    this->GameStateRef = NULL;
    this->HookPoint->SetupAttachment(RootComponent);
    this->Mesh->SetupAttachment(RootComponent);
}

FVector AAGrapplePoint::GetHookOffset() const {
    return FVector{};
}

UStaticMesh* AAGrapplePoint::GetGrappleMesh() const {
    return NULL;
}


