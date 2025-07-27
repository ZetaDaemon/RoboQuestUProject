#include "AGrapplePoint.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SphereComponent -FallbackName=SphereComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Components/StaticMeshComponent.h"

AAGrapplePoint::AAGrapplePoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

FVector AAGrapplePoint::GetHookOffset() const {
    return FVector{};
}

UStaticMesh* AAGrapplePoint::GetGrappleMesh() const {
    return NULL;
}


