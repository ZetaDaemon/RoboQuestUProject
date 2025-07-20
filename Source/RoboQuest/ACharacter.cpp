#include "ACharacter.h"
#include "ASkillManager.h"
#include "Net/UnrealNetwork.h"

AACharacter::AACharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->isInitialized = false;
    this->bIsTargetable = true;
    this->SkillManager = CreateDefaultSubobject<UASkillManager>(TEXT("SkillManager"));
    this->CurrentTile = NULL;
    this->bShouldBeDead = false;
    this->ShieldDamageReduction = 0.00f;
    this->IceRatioModifier = 0.00f;
    this->ShockRatioModifier = 0.00f;
    this->bCanStun = true;
    this->IceDurationRatio = 1.00f;
    this->ShockDurationRatio = 1.00f;
    this->bIsDead = false;
    this->bLocalDamage = false;
    this->bIceAutoCritical = false;
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
    this->StatusResistanceDuration[0] = 0.00f;
    this->StatusResistanceDuration[1] = 0.00f;
    this->StatusResistanceDuration[2] = 0.00f;
    this->StatusResistanceDuration[3] = 0.00f;
    this->StatusResistanceDuration[4] = 0.00f;
    this->StatusResistanceDuration[5] = 0.00f;
    this->StatusResistanceDuration[6] = 0.00f;
    this->StatusResistanceDuration[7] = 0.00f;
    this->StatusResistanceDuration[8] = 0.00f;
    this->StatusResistanceDuration[9] = 0.00f;
    this->StatusResistanceDuration[10] = 0.00f;
    this->StatusResistanceDuration[11] = 0.00f;
    this->StatusResistanceDuration[12] = 0.00f;
    this->StatusResistanceDuration[13] = 0.00f;
    this->StatusResistanceDuration[14] = 0.00f;
    this->StatusResistanceDuration[15] = 0.00f;
    this->StatusResistanceDuration[16] = 0.00f;
    this->StatusResistanceDuration[17] = 0.00f;
    this->StatusResistanceDuration[18] = 0.00f;
    this->ActorDynamicLoadingRangeSquared[0] = 0.00f;
    this->ActorDynamicLoadingRangeSquared[1] = 0.00f;
    this->TemporaryNearStateDuration = 5.00f;
    this->CurveImpactForceVelocity = NULL;
    this->CurveImpactForceImpulse = NULL;
    this->bComputeIKWhenMoving = false;
    this->IKMinUpdateRate = 0.05f;
    this->IKMaxUpdateRate = 0.10f;
    this->IKLeftFootOffset = 0.00f;
    this->IKRightFootOffset = 0.00f;
    this->IKFeetRaycastLength = 75.00f;
    this->IKFeetInterpSpeed = 13.00f;
    this->IKFeetCollisionChannel = ECC_GameTraceChannel6;
    this->IKHipsOffset = 0.00f;
    this->IKHipsInterpSpeed = 7.00f;
    this->InitialParticleSystemPoolCount = 1;
    this->bAutoRegisterToGameState = true;
    this->CreationTime = 1750726445191;
}

void AACharacter::StoreMonitoringTimer(const FString& Context, bool bPrint) {
}

void AACharacter::SpawnStatusLoopingParticle(EStatus Status, const FName& SocketName, float InStatusRadius) {
}

UAudioComponent* AACharacter::SpawnSoundVibration(USoundCue* BaseSoundRef, float Intensity, bool bAttached, bool bAutoDestroy) {
    return NULL;
}

UAudioComponent* AACharacter::SpawnSoundAttached(USceneComponent* Root, USoundCue* Sound, const FVector& Location, bool bWeaponSound, float BaseVolumeMultiplier, bool bMono, bool bAutoDestroy) {
    return NULL;
}

UAudioComponent* AACharacter::SpawnSoundAtLocation(USoundCue* Sound, const FVector& Location, bool bWeaponSound, float BaseVolumeMultiplier, bool bMono) {
    return NULL;
}

void AACharacter::SetTargetable(bool IsTargetable, AActor* NewTarget) {
}

void AACharacter::SetShieldDamageReduction(float NewShieldDamageReduction) {
}

void AACharacter::SetNewDifficulty(const FName& DifficultyRowName, const FDifficultyRow& Difficulty) {
}

void AACharacter::SetInvulnerability(bool bNewInvulnerable) {
}

void AACharacter::RemoveGlobalSuperFeedback() {
}

void AACharacter::RemoveGlobalStatModifier(UModifier_Stat* StatModifier) {
}

void AACharacter::RemoveGlobalDamageModifier(UModifier_Damage* DamageModifier) {
}

void AACharacter::RemoveAllStatus() {
}

UAudioComponent* AACharacter::PlaySoundVibration(USoundCue* BaseSoundRef, float Intensity) {
    return NULL;
}

void AACharacter::PlaySoundAtLocation(USoundCue* Sound, const FVector& Location, bool bWeaponSound, float BaseVolumeMultiplier, bool bMono) {
}

void AACharacter::OnTriggerDeathInternal(const FRQDamageInfo& DamageInfo) {
}


void AACharacter::OnServerApplyDamage_Implementation(float DamageAmount, float ImpactForceAmount, AACharacter* DamageInstigator, int32 GameplayTags, float IceRatio, float ShockRatio) {
}
bool AACharacter::OnServerApplyDamage_Validate(float DamageAmount, float ImpactForceAmount, AACharacter* DamageInstigator, int32 GameplayTags, float IceRatio, float ShockRatio) {
    return true;
}

void AACharacter::OnNotifyStatFull(EStat enumStat) {
}

void AACharacter::OnNotifyStatEmpty(EStat enumStat) {
}

void AACharacter::OnNotifyStat(EStat enumStat, float curVal, float Value) {
}

void AACharacter::OnMulticastDeathWithDamageInfo_Implementation(const FRQDamageInfo& DamageInfo) {
}

void AACharacter::OnMulticastDeath_Implementation() {
}

void AACharacter::OnMulticastApplyDamage_Implementation(float DamageAmount, float ImpactForceAmount, AACharacter* DamageInstigator, int32 GameplayTags, float IceRatio, float ShockRatio) {
}

void AACharacter::OnImpulseBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void AACharacter::OnImpulseBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void AACharacter::OnCommonCharacterDataAssetLoaded() {
}

void AACharacter::OnCharacterDestroyed(AActor* Actor) {
}

void AACharacter::OnCancelSkill(EAction Action) {
}



bool AACharacter::IsValidNavLocation(const FVector& Location, FVector& ProjectedLocationOnNavMesh) const {
    return false;
}

UAudioComponent* AACharacter::GetStatusAudioComponent(EStatus Status) {
    return NULL;
}

AACharacter* AACharacter::GetRealDamageInstigator() {
    return NULL;
}

float AACharacter::GetRagdollDuration() {
    return 0.0f;
}

FVector AACharacter::GetNavLocation() const {
    return FVector{};
}

FName AACharacter::GetMuzzleSocketName(int32 MuzzleIndex) const {
    return NAME_None;
}

FVector AACharacter::GetMuzzleSocketLocation(int32 MuzzleIndex) {
    return FVector{};
}

EDirection AACharacter::GetHitDirection(const FRQDamageInfo& DamageInfo) const {
    return EDirection::Up;
}

FHitResult AACharacter::GetFootRaycast(bool bIgnoreOverlap) {
    return FHitResult{};
}

FString AACharacter::GetDisplayName() const {
    return TEXT("");
}

AATile* AACharacter::GetCurrentTile() const {
    return NULL;
}

USkeletalMeshComponent* AACharacter::GetCharacterMesh() {
    return NULL;
}

FVector AACharacter::GetBodyLocation() const {
    return FVector{};
}


void AACharacter::CancelAllSkill() {
}

void AACharacter::CallServerInitialization_Implementation() {
}
bool AACharacter::CallServerInitialization_Validate() {
    return true;
}

void AACharacter::AddGlobalSuperFeedback() {
}

void AACharacter::AddGlobalStatModifier(UModifier_Stat* StatModifier) {
}

void AACharacter::AddGlobalDamageModifier(UModifier_Damage* DamageModifier) {
}

void AACharacter::AddDamageReductionByGameplayTag(float AddDamageReduction, EGameplayTags GameplayTag) {
}

void AACharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AACharacter, bAutoRegisterToGameState);
    DOREPLIFETIME(AACharacter, CreationTime);
}


