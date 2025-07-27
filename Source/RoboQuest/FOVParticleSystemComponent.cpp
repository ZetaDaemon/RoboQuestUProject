#include "FOVParticleSystemComponent.h"

UFOVParticleSystemComponent::UFOVParticleSystemComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FOV = 72.50f;
}

FMatrix UFOVParticleSystemComponent::GetPublicRenderMatrix() {
    return FMatrix{};
}


