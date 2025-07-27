#include "APlayerSkill_Beam.h"

UAPlayerSkill_Beam::UAPlayerSkill_Beam(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RaycastTrailEmiterBeamIndex.AddDefaulted(1);
    this->BeamLaserFX = NULL;
    this->BeamEndFX = NULL;
    this->BeamStartFX = NULL;
    this->BeamLaserMesh = NULL;
    this->BeamLaserMeshMaterial = NULL;
    this->EndBeamFX = NULL;
    this->BeamMeshComponent = NULL;
    this->bDebugBeamRaycast = false;
}



