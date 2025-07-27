#include "DecalActor_SwapTexture.h"
#include "DecalComponent_SwapTexture.h"

ADecalActor_SwapTexture::ADecalActor_SwapTexture(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UDecalComponent_SwapTexture>(TEXT("NewDecalComponent"))) {
    const FProperty* p_Decal = GetClass()->FindPropertyByName("Decal");
    (*p_Decal->ContainerPtrToValuePtr<UDecalComponent*>(this)) = (UDecalComponent*)RootComponent;
    this->DecalComponentSwapTexture = (UDecalComponent_SwapTexture*)RootComponent;
    this->DynMaterial = NULL;
    this->Material = NULL;
    this->TextureIndex = 1;
}


