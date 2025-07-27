#include "AShockwave.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ParticleSystemComponent -FallbackName=ParticleSystemComponent
#include "Particles/ParticleSystemComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"

AAShockwave::AAShockwave(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AAShockwave::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAShockwave, Speed);
    DOREPLIFETIME(AAShockwave, Damage);
    DOREPLIFETIME(AAShockwave, Height);
    DOREPLIFETIME(AAShockwave, BaseSize);
    DOREPLIFETIME(AAShockwave, MaxSize);
}


