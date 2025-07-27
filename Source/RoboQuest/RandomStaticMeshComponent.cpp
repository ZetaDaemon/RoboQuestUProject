#include "RandomStaticMeshComponent.h"

URandomStaticMeshComponent::URandomStaticMeshComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAllowRotation = true;
    this->bAllowMirrored = true;
}


