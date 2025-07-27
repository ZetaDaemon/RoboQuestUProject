#include "AAIProjectile.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SphereComponent -FallbackName=SphereComponent

AAAIProjectile::AAAIProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AAAIProjectile::OnTargetHomingCharacterTargetable(bool bTargetable, AActor* NewTarget) {
}

FLinearColor AAAIProjectile::GetFXProjectileColor() const {
    return FLinearColor{};
}

FLinearColor AAAIProjectile::GetBaseProjectileColor() const {
    return FLinearColor{};
}


