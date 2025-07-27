#include "AEnemyBeam.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=AudioComponent -FallbackName=AudioComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ParticleSystemComponent -FallbackName=ParticleSystemComponent
#include "Particles/ParticleSystemComponent.h"

AAEnemyBeam::AAEnemyBeam(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AAEnemyBeam::StartPreshoot(float PreshootDuration) {
}

void AAEnemyBeam::StartDamageState() {
}






UAGameInstance* AAEnemyBeam::GetGameInstanceRef() {
    return NULL;
}


