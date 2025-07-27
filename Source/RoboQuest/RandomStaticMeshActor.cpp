#include "RandomStaticMeshActor.h"
#include "RandomStaticMeshComponent.h"

ARandomStaticMeshActor::ARandomStaticMeshActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<URandomStaticMeshComponent>(TEXT("StaticMeshComponent0"))) {
    this->bCanBeInCluster = false;
    const FProperty* p_StaticMeshComponent = GetClass()->FindPropertyByName("StaticMeshComponent");
    (*p_StaticMeshComponent->ContainerPtrToValuePtr<UStaticMeshComponent*>(this)) = (UStaticMeshComponent*)RootComponent;
    this->RootRandomStaticMeshComponent = (URandomStaticMeshComponent*)RootComponent;
    this->bAllowRotation = true;
    this->bAllowMirrored = true;
}

void ARandomStaticMeshActor::RandomizeMesh() {
}


