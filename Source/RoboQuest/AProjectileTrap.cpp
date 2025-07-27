#include "AProjectileTrap.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TextRenderComponent -FallbackName=TextRenderComponent

AAProjectileTrap::AAProjectileTrap(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AAProjectileTrap::ShootProjectile(float ElapsedTime, bool bPlayUseSound) {
}

void AAProjectileTrap::OnProjectileStartOverlap(const FHitResult& HitResult, AAProjectile* Projectile) {
}


