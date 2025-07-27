#include "APlayerAnimInstance.h"

UAPlayerAnimInstance::UAPlayerAnimInstance() {
    this->bIsTPV = false;
    this->PlayerRef = NULL;
    this->PitchAIM_InterpSpeed = 200.00f;
    this->PitchAIM_Offset = -5.00f;
    this->bIsIdle = true;
    this->CurrentMoveSpeed = 0.00f;
    this->RunPlayRate = 0.00f;
    this->CrouchPlayRate = 0.00f;
    this->SprintPlayRate = 0.00f;
    this->CameraYawDirection = 0.00f;
    this->CameraPitchDirection = 0.00f;
    this->StrafeDirection = 0.00f;
    this->MoveDirection = 0.00f;
    this->MeshDirection = 0.00f;
    this->MeshYawRotation = 0.00f;
    this->YawAIM = 0.00f;
    this->PitchAIM = 0.00f;
    this->Lean_CurveByMovespeed = NULL;
    this->Lean_IncrementSpeed = 2.00f;
    this->Lean_ResetSpeed = 2.00f;
    this->LeanDirection = 0.00f;
    this->AdditiveRidingLerpSpeed = 12.00f;
    this->AdditiveRidingAlpha = 0.00f;
    this->AnimLeftHandPose = NULL;
    this->AnimRightHandPose = NULL;
    this->AlphaRightHandPose = 0.00f;
    this->AlphaLeftHandPose = 0.00f;
    this->TPV_IdleAnimations[0] = NULL;
    this->TPV_IdleAnimations[1] = NULL;
    this->TPV_IdleAnimations[2] = NULL;
    this->TPV_IdleAnimations[3] = NULL;
    this->TPV_IdleAnimations[4] = NULL;
    this->TPV_LastIdleAnimation = NULL;
    this->TPV_IdleAnimation = NULL;
    this->TPV_CrouchIdleAnimations[0] = NULL;
    this->TPV_CrouchIdleAnimations[1] = NULL;
    this->TPV_CrouchIdleAnimations[2] = NULL;
    this->TPV_CrouchIdleAnimations[3] = NULL;
    this->TPV_CrouchIdleAnimations[4] = NULL;
    this->TPV_LastCrouchIdleAnimation = NULL;
    this->TPV_CrouchIdleAnimation = NULL;
    this->TPV_BaseAIM[0] = NULL;
    this->TPV_BaseAIM[1] = NULL;
    this->TPV_BaseAIM[2] = NULL;
    this->TPV_BaseAIM[3] = NULL;
    this->TPV_BaseAIM[4] = NULL;
    this->TPV_AIM = NULL;
    this->TPV_JumpLoopAnimations[0] = NULL;
    this->TPV_JumpLoopAnimations[1] = NULL;
    this->TPV_JumpLoopAnimations[2] = NULL;
    this->TPV_JumpLoopAnimations[3] = NULL;
    this->TPV_JumpLoopAnimations[4] = NULL;
    this->TPV_LastJumpLoopAnimation = NULL;
    this->TPV_JumpLoopAnimation = NULL;
    this->TPV_RunAnimations[0] = NULL;
    this->TPV_RunAnimations[1] = NULL;
    this->TPV_RunAnimations[2] = NULL;
    this->TPV_RunAnimations[3] = NULL;
    this->TPV_RunAnimations[4] = NULL;
    this->TPV_LastRunAnimation = NULL;
    this->TPV_RunAnimation = NULL;
    this->TPV_CrouchRunAnimations[0] = NULL;
    this->TPV_CrouchRunAnimations[1] = NULL;
    this->TPV_CrouchRunAnimations[2] = NULL;
    this->TPV_CrouchRunAnimations[3] = NULL;
    this->TPV_CrouchRunAnimations[4] = NULL;
    this->TPV_LastCrouchRunAnimation = NULL;
    this->TPV_CrouchRunAnimation = NULL;
    this->TPV_SprintRunAnimations[0] = NULL;
    this->TPV_SprintRunAnimations[1] = NULL;
    this->TPV_SprintRunAnimations[2] = NULL;
    this->TPV_SprintRunAnimations[3] = NULL;
    this->TPV_SprintRunAnimations[4] = NULL;
    this->TPV_LastSprintRunAnimation = NULL;
    this->TPV_SprintRunAnimation = NULL;
    this->TPV_SlideAnimations[0] = NULL;
    this->TPV_SlideAnimations[1] = NULL;
    this->TPV_SlideAnimations[2] = NULL;
    this->TPV_SlideAnimations[3] = NULL;
    this->TPV_SlideAnimations[4] = NULL;
    this->TPV_LastSlideAnimation = NULL;
    this->TPV_SlideAnimation = NULL;
    this->TPV_DeathAnimation = NULL;
    this->FPV_IdleRunAnimations[0] = NULL;
    this->FPV_IdleRunAnimations[1] = NULL;
    this->FPV_IdleRunAnimations[2] = NULL;
    this->FPV_IdleRunAnimations[3] = NULL;
    this->FPV_IdleRunAnimations[4] = NULL;
    this->FPV_IdleRunAnimation = NULL;
    this->FPV_SprintLoopAnimations[0] = NULL;
    this->FPV_SprintLoopAnimations[1] = NULL;
    this->FPV_SprintLoopAnimations[2] = NULL;
    this->FPV_SprintLoopAnimations[3] = NULL;
    this->FPV_SprintLoopAnimations[4] = NULL;
    this->FPV_SprintLoopAnimation = NULL;
    this->FPV_JumpRunLoopAnimations[0] = NULL;
    this->FPV_JumpRunLoopAnimations[1] = NULL;
    this->FPV_JumpRunLoopAnimations[2] = NULL;
    this->FPV_JumpRunLoopAnimations[3] = NULL;
    this->FPV_JumpRunLoopAnimations[4] = NULL;
    this->FPV_JumpRunLoopAnimation = NULL;
    this->FPV_JumpSprintLoopAnimations[0] = NULL;
    this->FPV_JumpSprintLoopAnimations[1] = NULL;
    this->FPV_JumpSprintLoopAnimations[2] = NULL;
    this->FPV_JumpSprintLoopAnimations[3] = NULL;
    this->FPV_JumpSprintLoopAnimations[4] = NULL;
    this->FPV_JumpSprintLoopAnimation = NULL;
    this->FPV_JumpRunFallAnimations[0] = NULL;
    this->FPV_JumpRunFallAnimations[1] = NULL;
    this->FPV_JumpRunFallAnimations[2] = NULL;
    this->FPV_JumpRunFallAnimations[3] = NULL;
    this->FPV_JumpRunFallAnimations[4] = NULL;
    this->FPV_JumpRunFallAnimation = NULL;
    this->FPV_JumpSprintFallAnimations[0] = NULL;
    this->FPV_JumpSprintFallAnimations[1] = NULL;
    this->FPV_JumpSprintFallAnimations[2] = NULL;
    this->FPV_JumpSprintFallAnimations[3] = NULL;
    this->FPV_JumpSprintFallAnimations[4] = NULL;
    this->FPV_JumpSprintFallAnimation = NULL;
    this->FPV_AIMOffsets[0] = NULL;
    this->FPV_AIMOffsets[1] = NULL;
    this->FPV_AIMOffsets[2] = NULL;
    this->FPV_AIMOffsets[3] = NULL;
    this->FPV_AIMOffsets[4] = NULL;
    this->FPV_AIMOffset = NULL;
    this->FPV_AIMStrafes[0] = NULL;
    this->FPV_AIMStrafes[1] = NULL;
    this->FPV_AIMStrafes[2] = NULL;
    this->FPV_AIMStrafes[3] = NULL;
    this->FPV_AIMStrafes[4] = NULL;
    this->FPV_AIMStrafe = NULL;
    this->FPV_RideAnimations[0] = NULL;
    this->FPV_RideAnimations[1] = NULL;
    this->FPV_RideAnimations[2] = NULL;
    this->FPV_RideAnimations[3] = NULL;
    this->FPV_RideAnimations[4] = NULL;
    this->FPV_RideAnimation = NULL;
    this->FPV_StunLoopAnimations[0] = NULL;
    this->FPV_StunLoopAnimations[1] = NULL;
    this->FPV_StunLoopAnimations[2] = NULL;
    this->FPV_StunLoopAnimations[3] = NULL;
    this->FPV_StunLoopAnimations[4] = NULL;
    this->FPV_StunLoopAnimation = NULL;
    this->SwitchAnimationTypeBlendSpeed = 8.00f;
    this->AlphaSwitchAnimationType = 1.00f;
    this->bCenterCrosshair = false;
    this->DisableCameraShake = 0.00f;
    this->AutomaticFireShakeAnimation = NULL;
    this->AutomaticFireShakeBlendValue = 0.00f;
    this->bWeaponCoolingOverheat = false;
    this->bIsShooting = false;
    this->ChargeBlendspace = NULL;
    this->bIsCharging = false;
    this->ChargeRatio = 0.00f;
    this->CurrentBindedWeapon = NULL;
    this->bIsStun = false;
    this->bLocallyControlled = false;
    this->bIsDead = false;
    this->bIsFalling = false;
    this->bIsOnAir = false;
    this->bIsOnAirAndFalling = false;
    this->bIsOnAirAndNotFalling = false;
    this->bIsSprinting = false;
    this->bIsCrouch = false;
    this->bIsCrouchOrPowersliding = false;
    this->bIsJumping = false;
    this->bIsRiding = false;
    this->bIsPowerSliding = false;
    this->bIsReloading = false;
    this->bIsSwitching = false;
    this->bNotIdleAndNotSprinting = false;
    this->bIdleAndNotCrouch = false;
    this->bNotFallingAndNotIdleAndNotCrouch = false;
    this->bIsIdleAndCrouchButNotFalling = false;
    this->bIsIdleButNotCrouchAndNotFalling = false;
    this->bNotCrouchAndNotSprinting = false;
    this->bIsCrouchButNotFallingAndNotIdle = false;
    this->bIsSprintingAndNotFalling = false;
    this->bIsCrouchButNotSprintingAndNotIdle = false;
    this->bIsIdleAndCrouch = false;
    this->bIsIdleButNotCrouch = false;
    this->bIsNotAndIdleAndNotCrouchAndNotSprinting = false;
    this->PowerSlideRate = 0.00f;
}

void UAPlayerAnimInstance::SetupAnimationTypeData_Implementation() {
}

void UAPlayerAnimInstance::SetHandPose(UAnimSequence* NewPose, bool bIsRight) {
}

void UAPlayerAnimInstance::OnPlayerEndInitialization_Implementation(ACharacter_Player* InPlayer) {
}

void UAPlayerAnimInstance::OnDelegateUsedWeaponSkill(UASkill* Skill, bool bIsStarting) {
}

void UAPlayerAnimInstance::OnDelegateUpdateSkillChargeRatio(UAPlayerSkill* Skill, float NewChargeRatio) {
}
void UAPlayerAnimInstance::OnDelegatePowerSlide(bool bIsStart) {
}

void UAPlayerAnimInstance::OnDelegateDispatchStatus(EStatus Status, bool bIsStart, float Duration) {
}

void UAPlayerAnimInstance::OnDelegateCurrentWeapon(AAWeapon* NewWeapon) {
}

void UAPlayerAnimInstance::OnDelegateCenterCrosshair(bool bNewValue) {
}

void UAPlayerAnimInstance::OnDelegateCameraShake(bool bNewValue) {
}


