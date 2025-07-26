#include "LevelRow.h"

FLevelRow::FLevelRow() {
    this->EnemyLevel = 0;
    this->BigCount = 0;
    this->BigQuestCount = 0;
    this->LevelXP = 0.00f;
    this->bOverrideGravityZ = false;
    this->GravityZ = 0.00f;
    this->Music = NULL;
    this->Theme = ELevelTheme::Canyon;
    this->bShowLevelInRandomMeshEditor = false;
    this->MaxTileCountInSameDirection = 0;
    this->EndLevelBeamClass = NULL;
    this->EndLevelBeamDistance = 0.00f;
    this->TilesSize = 0.00f;
    this->bGenerateStraightLineLevel = false;
    this->LevelXPPreSas = 0.00f;
    this->LevelXPPostSas = 0.00f;
    this->SpecificWallTileCountToSpawn = 0;
    this->RoofHeight = 0.00f;
    this->RoofBlockingBoxHeight = 0.00f;
    this->bOverrideMeshes = false;
    this->bIsCorrupted = false;
    this->CorruptedLevelType = ECorruptedLevelType::None;
    this->bIsLavaLevel = false;
    this->TimeLimitation[0] = 0.00f;
    this->TimeLimitation[1] = 0.00f;
    this->TimeLimitation[2] = 0.00f;
    this->bIsPlaceHolderRow = false;
}

