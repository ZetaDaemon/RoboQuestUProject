#include "AEndTile.h"
#include "ETileType.h"

AAEndTile::AAEndTile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Type = ETileType::End;
}


