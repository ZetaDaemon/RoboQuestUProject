#include "AProjectile.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=AudioComponent -FallbackName=AudioComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ParticleSystemComponent -FallbackName=ParticleSystemComponent
#include "Particles/ParticleSystemComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ProjectileMovementComponent -FallbackName=ProjectileMovementComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SphereComponent -FallbackName=SphereComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Components/StaticMeshComponent.h"

AAProjectile::AAProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AAProjectile::SimulateProjectileDeath() {
}

void AAProjectile::ResetDamagingActors() {
}

void AAProjectile::RemoveGameplayTag(EGameplayTags Tag) {
}

void AAProjectile::RecalculateHitDelay() {
}

void AAProjectile::OnStickedCharacterDeath(const FRQDamageInfo& DamageInfo) {
}

void AAProjectile::OnStickedCharacterActivate(bool bNewActivate) {
}

void AAProjectile::OnProjectileStickingEndTrigger() {
}

void AAProjectile::OnProjectileStick_Implementation(FHitResult HitResult) {
}



void AAProjectile::OnProjectileBouncingEndTrigger() {
}

void AAProjectile::OnEndLife_Implementation() {
}

void AAProjectile::OnEndHomingDelayTimer() {
}

void AAProjectile::OnDestroy_Implementation() {
}

void AAProjectile::OnDeactivate_Implementation() {
}

void AAProjectile::OnCallCustomBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}



void AAProjectile::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void AAProjectile::OnBeginHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
}

void AAProjectile::OnActivate_Implementation() {
}

void AAProjectile::AddNewGameplayTag(EGameplayTags Tag) {
}

void AAProjectile::ActivateEnvironmentCollision() {
}


