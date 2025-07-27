#include "AInteractive_WeaponSpawner.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BillboardComponent -FallbackName=BillboardComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SkeletalMeshComponent -FallbackName=SkeletalMeshComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Components/StaticMeshComponent.h"

AAInteractive_WeaponSpawner::AAInteractive_WeaponSpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AAInteractive_WeaponSpawner::SpawnWeapon_Implementation(const TSoftClassPtr<AAWeapon>& WeaponClass, ACharacter_Player* PlayerRef) {
}

void AAInteractive_WeaponSpawner::SetSpawnFeedbackActivate_Implementation(bool bActivate) {
}


