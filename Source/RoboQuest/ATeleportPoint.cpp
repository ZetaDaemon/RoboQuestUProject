#include "ATeleportPoint.h"
#include "Components/BoxComponent.h"

AATeleportPoint::AATeleportPoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

FTransform AATeleportPoint::GetTeleportTransform() const {
    return FTransform{};
}


