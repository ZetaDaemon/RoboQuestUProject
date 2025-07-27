#include "SkeletalMeshActorWithMobility.h"
#include "SkeletalMeshComponentWithMobility.h"

ASkeletalMeshActorWithMobility::ASkeletalMeshActorWithMobility(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<USkeletalMeshComponentWithMobility>(TEXT("SkeletalMeshComponent0"))) {
    const FProperty* p_SkeletalMeshComponent = GetClass()->FindPropertyByName("SkeletalMeshComponent");
    (*p_SkeletalMeshComponent->ContainerPtrToValuePtr<USkeletalMeshComponent*>(this)) = (USkeletalMeshComponent*)RootComponent;
    this->Mobility = EComponentMobility::Static;
}


