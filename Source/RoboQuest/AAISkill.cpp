#include "AAISkill.h"

UAAISkill::UAAISkill(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RaycastTrailEmiterBeamIndex.AddDefaulted(1);
    this->AIOwner = NULL;
    this->UseAmount = 0;
    this->TokenRule = ETokenRule::None;
    this->bCancelIfTurnAround = false;
    this->bCanRotate = false;
    this->bRotateBeforePreshoot = false;
    this->FireRate = 0.00f;
    this->RecoveryDuration = 0.00f;
    this->MaxUseAmount = 0;
    this->CurrentUseAmount = 1;
    this->bPredictMovement = false;
    this->bPredictZVelocity = false;
    this->TargetDirection = ETargetDirection::Target;
    this->AreaDelay = 0.00f;
    this->AreaLoopSound = NULL;
    this->BumpIntensity = EBumpIntensity::None;
    this->PreshootOverheadFX = NULL;
    this->PreshootPitchCurve = NULL;
    this->PreshootVolumeCurve = NULL;
    this->PreshootDuration = 0.00f;
    this->PreshootFX = NULL;
    this->PreshootAudioComponent = NULL;
    this->bArcProjectile = false;
    this->bFlatDistance = false;
    this->ArcDistance = 0.00f;
    this->TravelDuration = 0.00f;
    this->bSlowProjectileInClose = false;
    this->bProjectileDestructible = false;
    this->ProjectileDestructibleCollisionSize = 0.00f;
    this->ProjectileDestructibleHealth = 0.00f;
    this->StartPreshootSound = NULL;
    this->LoopPreshootSound = NULL;
    this->DeathSound = NULL;
    this->PreshootAnimation = NULL;
    this->ShootAnimation = NULL;
    this->ShootPlayrate = 0.00f;
    this->OtherMultiShootAnimation = NULL;
    this->OtherMultiShootPlayrate = 0.00f;
    this->AIMSpeedRatio = 0.00f;
    this->AreaPreshootFX = NULL;
}

void UAAISkill::TriggerAreaArroundTarget(const FVector_NetQuantize& StartTrace, const TArray<FVector_NetQuantize>& Locations) {
}

void UAAISkill::ResetCurrentUseAmount() {
}

void UAAISkill::OnMulticastUseSkill_Implementation(const TArray<FNetworkSkillInfo>& NetworkInfos) {
}

void UAAISkill::OnMulticastStartPreshoot_Implementation() {
}

void UAAISkill::OnMulticastAreaArroundTarget_Implementation(const FVector_NetQuantize& StartTrace, const TArray<FVector_NetQuantize>& Locations) {
}

void UAAISkill::OnCommonAISkillDataAssetLoaded() {
}

UAnimMontage* UAAISkill::GetShootAnimation_Implementation() const {
    return NULL;
}

FVector UAAISkill::GetLaunchLocation_Implementation(const FVector& StartTrace, const FVector& ForwardVector, int32 InMuzzleIndex) {
    return FVector{};
}

FVector UAAISkill::GetDelayAreaLocation_Implementation() {
    return FVector{};
}

float UAAISkill::GetArcDistance_Implementation() {
    return 0.0f;
}

ACharacter_AI* UAAISkill::GetAICharacter() const {
    return NULL;
}


