#include "AInfiniteBossTile.h"
#include "ETileType.h"

AAInfiniteBossTile::AAInfiniteBossTile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Type = ETileType::InfiniteBoss;
    this->InteriorClassToSpawn = NULL;
    this->InteriorTileRef = NULL;
}

AActor* AAInfiniteBossTile::GetInteriorTile() const {
    return NULL;
}


