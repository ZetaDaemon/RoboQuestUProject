#include "Character_AI.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=AudioComponent -FallbackName=AudioComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SkeletalMeshComponent -FallbackName=SkeletalMeshComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"

ACharacter_AI::ACharacter_AI(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void ACharacter_AI::UseSkill(EAction Action) {
}

void ACharacter_AI::UpdateTimeDilatation_Implementation(float NewTimeDilation) {
}

void ACharacter_AI::UpdateMoveSpeed(float NewSpeed) {
}

void ACharacter_AI::TriggerTurnRotation(ERotationDirection Direction) {
}

void ACharacter_AI::TriggerDeathMaterialEffects_Implementation(const FRQDamageInfo& DamageInfo) {
}

void ACharacter_AI::StoreDynamicMaterials() {
}

void ACharacter_AI::StopRefreshDynamicLoadingState() {
}

void ACharacter_AI::StopCheckVision() {
}

void ACharacter_AI::StartSpawnEffect() {
}

void ACharacter_AI::StartRefreshDynamicLoadingState() {
}

void ACharacter_AI::StartAutoCheckActivation() {
}

void ACharacter_AI::SimulateSetYawAIM(float InYawAIM) {
}

void ACharacter_AI::SimulateSetPitchAIM(float InPitchAIM) {
}

void ACharacter_AI::SetNewAiState(EAIState NewState) {
}

void ACharacter_AI::SetMeshActivated(bool bActivate) {
}

void ACharacter_AI::SetLoopingSoundActivate_Implementation(bool bActivate) {
}

void ACharacter_AI::SetIconActivate(bool bIsActivate) {
}

void ACharacter_AI::SetDynamicMaterialVectorParam(FName ParameterName, FVector NewVector) {
}

void ACharacter_AI::SetDynamicMaterialFloatParamByIndex(FName ParameterName, float NewValue, int32 Materialindex) {
}

void ACharacter_AI::SetDynamicMaterialFloatParam(FName ParameterName, float NewValue) {
}

void ACharacter_AI::SetDynamicMaterialColorParamByIndex(FName ParameterName, FLinearColor NewColor, int32 Materialindex) {
}

void ACharacter_AI::SetDynamicMaterialColorParam(FName ParameterName, FLinearColor NewColor) {
}

void ACharacter_AI::SetCurrentTarget(FTargetInfo NewTargetInfo) {
}

void ACharacter_AI::SetCompassIconActivate(bool bIsActivate) {
}

void ACharacter_AI::SetCollisionEnabled(bool bIsEnabled) {
}

void ACharacter_AI::SetAIActivated(bool bActivate) {
}

void ACharacter_AI::ResetCurrentTarget() {
}

void ACharacter_AI::RemoveCustomFloatValue(FName PropertyName) {
}

void ACharacter_AI::OnTimerLifeSpanFinished() {
}

void ACharacter_AI::OnNotifyCurrentTargetUpdateTargetable(bool IsTargetable, AActor* NewTarget) {
}

void ACharacter_AI::OnNotifyCurrentTargetDeath(const FRQDamageInfo& DamageInfo) {
}

void ACharacter_AI::OnEndTimerFootstep() {
}

void ACharacter_AI::OnCommonAIDataAssetLoaded() {
}









void ACharacter_AI::MulticastSetNetworkedTarget_Implementation(AActor* NewTarget) {
}

void ACharacter_AI::MulticastSetCollisionEnabled_Implementation(bool bIsEnabled) {
}

void ACharacter_AI::MulticastLockAim_Implementation(bool NewLockAim) {
}

void ACharacter_AI::MulticastActivateWithSpawnEffect_Implementation() {
}




bool ACharacter_AI::IsClassicEnemy() const {
    return false;
}

bool ACharacter_AI::IsBoss() const {
    return false;
}


bool ACharacter_AI::IsBig() const {
    return false;
}

void ACharacter_AI::InitializeEyePatchMaterial(UStaticMeshComponent* InMesh) {
}

float ACharacter_AI::GetYawAIMToLocation(const FVector& TargetLocation, float& OutTargetYawAIM) const {
    return 0.0f;
}

float ACharacter_AI::GetYawAIMDifference() const {
    return 0.0f;
}

float ACharacter_AI::GetYawAIM() {
    return 0.0f;
}

FTargetInfo ACharacter_AI::GetVisibilityInfoOnTarget(AActor* Target) {
    return FTargetInfo{};
}

TArray<ETeam> ACharacter_AI::GetTargetsTeam_Implementation() const {
    return TArray<ETeam>();
}

TArray<AActor*> ACharacter_AI::GetTargetsArround() const {
    return TArray<AActor*>();
}

float ACharacter_AI::GetTargetNavLocationFLyingOffset_Implementation() {
    return 0.0f;
}

float ACharacter_AI::GetSummonTimeRemaining() const {
    return 0.0f;
}

float ACharacter_AI::GetPitchAIMToLocation(const FVector& TargetLocation) const {
    return 0.0f;
}

float ACharacter_AI::GetPitchAIM() {
    return 0.0f;
}

ACharacter_Player* ACharacter_AI::GetLocalPlayerRef() const {
    return NULL;
}

AAPlayerController* ACharacter_AI::GetLocalPlayerControllerRef() const {
    return NULL;
}

float ACharacter_AI::GetHitBlend() const {
    return 0.0f;
}

UAnimMontage* ACharacter_AI::GetHitAnimation_Implementation(const FRQDamageInfo& DamageInfo) const {
    return NULL;
}

FLinearColor ACharacter_AI::GetFXColor() const {
    return FLinearColor{};
}

FVector ACharacter_AI::GetCustomVelocity_Implementation() {
    return FVector{};
}

float ACharacter_AI::GetCustomFloatValue(FName PropertyName) const {
    return 0.0f;
}

FTargetInfo ACharacter_AI::GetCurrentTargetInfo() {
    return FTargetInfo{};
}

AActor* ACharacter_AI::GetCurrentTarget() const {
    return NULL;
}


FLinearColor ACharacter_AI::GetCableColor() {
    return FLinearColor{};
}

void ACharacter_AI::ForceActivation(bool bActivate) {
}

void ACharacter_AI::ExtractDatatable(UDataTable* DataTable, UAStatManager* InStatManager) {
}

void ACharacter_AI::DisableHealthBar() {
}

void ACharacter_AI::CheckVisibilityOnTargets() {
}

bool ACharacter_AI::CanProcessTurnRotation() {
    return false;
}

void ACharacter_AI::AddSummonDuration(float AddDuration) {
}

void ACharacter_AI::AddCustomFloatValue(FName PropertyName, float Value) {
}

void ACharacter_AI::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ACharacter_AI, bAutoCheckActivation);
}


