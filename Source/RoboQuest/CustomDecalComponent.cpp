#include "CustomDecalComponent.h"

UCustomDecalComponent::UCustomDecalComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAllowMirrorX = true;
    this->bAllowMirrorY = true;
    this->bAllowMirrorZ = true;
}


