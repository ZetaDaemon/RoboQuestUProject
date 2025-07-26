#include "SFXSurface.h"

FSFXSurface::FSFXSurface() {
    this->SurfaceDecalType = ESurfaceImpactDecalTypes::Crack;
    this->DeathDecalType = EEnemyDeathDecalMaterialTypes::Small;
    this->DecalDuration = 0.00f;
    this->DecalFadeDuration = 0.00f;
    this->bRandomizeDecalRoll = false;
}

