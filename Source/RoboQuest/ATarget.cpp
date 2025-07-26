#include "ATarget.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ArrowComponent -FallbackName=ArrowComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=CapsuleComponent -FallbackName=CapsuleComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SkeletalMeshComponent -FallbackName=SkeletalMeshComponent

AATarget::AATarget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
    this->CapsuleComponent = (UCapsuleComponent*)RootComponent;
    this->TargetMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TargetMesh"));
    this->HomingComponent = CreateDefaultSubobject<USceneComponent>(TEXT("HomingComponent"));
    this->ArrowLeft = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowLeft"));
    this->ArrowRight = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowRight"));
    this->bCanMove = true;
    this->Health = 120;
    this->ImpactResistance = 60;
    this->StaggerDuration = 1.25f;
    this->CapsuleHalfHeight = 100;
    this->CapsuleRadius = 50;
    this->DeathDuration = 3.00f;
    this->KillAmountToRespawn = 0;
    this->RespawnKillDelay = 0.35f;
    this->Type = EEnemyType::None;
    this->Score = 1;
    this->bRevertMesh = false;
    this->bFlipMesh = false;
    this->Height = 50;
    this->Index = 0;
    this->DelayBeforeRaise = 0.50f;
    this->DelayBeforeResetToInitialPosition = 0.50f;
    this->UpAndDownSpeed = 100.00f;
    this->Speed = 100.00f;
    this->bStartRight = false;
    this->DelayBeforeUpAndDown = 0.00f;
    this->bStartUp = false;
    this->HealthBarSize = 150;
    this->StatusRadius = 50.00f;
    this->StaggerAnimation = NULL;
    this->StunAnimation = NULL;
    this->HitBlendMultiplier = 1.00f;
    this->GameStateRef = NULL;
    this->StatusAudioComponent[0] = NULL;
    this->StatusAudioComponent[1] = NULL;
    this->StatusAudioComponent[2] = NULL;
    this->StatusAudioComponent[3] = NULL;
    this->StatusAudioComponent[4] = NULL;
    this->StatusAudioComponent[5] = NULL;
    this->StatusAudioComponent[6] = NULL;
    this->StatusAudioComponent[7] = NULL;
    this->StatusAudioComponent[8] = NULL;
    this->StatusAudioComponent[9] = NULL;
    this->StatusAudioComponent[10] = NULL;
    this->StatusAudioComponent[11] = NULL;
    this->StatusAudioComponent[12] = NULL;
    this->StatusAudioComponent[13] = NULL;
    this->StatusAudioComponent[14] = NULL;
    this->StatusAudioComponent[15] = NULL;
    this->StatusAudioComponent[16] = NULL;
    this->StatusAudioComponent[17] = NULL;
    this->StatusAudioComponent[18] = NULL;
    this->CurveImpactRegeneration = NULL;
    this->CurveStunRegeneration = NULL;
    this->CurveIceRegeneration = NULL;
    this->InitialParticleSystemPoolCount = 1;
    this->GameInstanceRef = NULL;
    this->TargetMesh->SetupAttachment(RootComponent);
    this->HomingComponent->SetupAttachment(TargetMesh);
    this->ArrowLeft->SetupAttachment(TargetMesh);
    this->ArrowRight->SetupAttachment(TargetMesh);
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



