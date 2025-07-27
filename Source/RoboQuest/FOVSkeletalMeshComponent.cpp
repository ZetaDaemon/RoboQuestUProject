#include "FOVSkeletalMeshComponent.h"

UFOVSkeletalMeshComponent::UFOVSkeletalMeshComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FOV = 72.50f;
}

FMatrix UFOVSkeletalMeshComponent::GetPublicRenderMatrix() {
    return FMatrix{};
}


