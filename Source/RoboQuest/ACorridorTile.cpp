#include "ACorridorTile.h"
#include "ETileType.h"

AACorridorTile::AACorridorTile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Type = ETileType::Corridor;
}


