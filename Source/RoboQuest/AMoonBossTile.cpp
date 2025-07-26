#include "AMoonBossTile.h"
#include "ETileType.h"

AAMoonBossTile::AAMoonBossTile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Type = ETileType::MoonBoss;
    this->ForceOpenedConnectors.AddDefaulted(1);
}

void AAMoonBossTile::PreStartLastMoonBossCombat() {
}

void AAMoonBossTile::PostStartLastMoonBossCombat() {
}


