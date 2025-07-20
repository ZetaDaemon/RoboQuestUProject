#include "SummonStaticMesh.h"

ASummonStaticMesh::ASummonStaticMesh(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bCanBeInCluster = false;
    this->DynamicMaterial = NULL;
}


