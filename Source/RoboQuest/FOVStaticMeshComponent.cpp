#include "FOVStaticMeshComponent.h"

UFOVStaticMeshComponent::UFOVStaticMeshComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FOV = 72.50f;
}

FMatrix UFOVStaticMeshComponent::GetPublicRenderMatrix() {
    return FMatrix{};
}


