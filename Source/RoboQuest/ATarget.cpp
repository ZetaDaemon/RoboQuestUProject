#include "ATarget.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ArrowComponent -FallbackName=ArrowComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=CapsuleComponent -FallbackName=CapsuleComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SkeletalMeshComponent -FallbackName=SkeletalMeshComponent

AATarget::AATarget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AATarget::StartUpAndDown() {
}

void AATarget::StartMoving() {
}

void AATarget::SetTargetActivate(bool bNewActivate) {
}

void AATarget::RemoveAllStatus() {
}

void AATarget::OnEndResetToInitialPositionTimer() {
}

void AATarget::OnDelegateTargetDeath(int32 TargetIndex, AATarget* TargetRef) {
}

void AATarget::OnDeathDurationEnd() {
}

void AATarget::OnCommonEnemyDataAssetLoaded() {
}

void AATarget::InitializeMesh() {
}

AAGameState* AATarget::GetGameStateRef() {
    return NULL;
}



