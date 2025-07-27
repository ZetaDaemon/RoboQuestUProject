#include "StaticMeshBlocker.h"

AStaticMeshBlocker::AStaticMeshBlocker(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanBeInCluster = false;
}


