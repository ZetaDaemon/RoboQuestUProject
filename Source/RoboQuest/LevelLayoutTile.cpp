#include "LevelLayoutTile.h"

FLevelLayoutTile::FLevelLayoutTile() {
    this->Type = ETileType::Arena;
    this->bLevelUpEnemies = false;
    this->SpecificLayout = ESpecificLayout::None;
    this->SpecificTile = ESpecificTile::Random;
    this->PoolID = 0;
    this->bGenerateRoof = false;
}

