#include "APlayerSkill_Summon.h"
#include "Net/UnrealNetwork.h"

UAPlayerSkill_Summon::UAPlayerSkill_Summon(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RaycastTrailEmiterBeamIndex.AddDefaulted(1);
    this->SummonBehavior = ESummonBehavior::Released;
    this->SummonClass = NULL;
    this->bFollowCameraRotation = false;
    this->SummonLifespan = 0.00f;
    this->SummonLifespanModifier = 0.00f;
    this->MaxSummonALive = 0;
    this->CollisionChannel = ECC_GameTraceChannel6;
    this->MaxSummonSpawned = 0;
    this->OutRangeBehavior = EOutRangeBehavior::None;
    this->SpawnRange = 0.00f;
    this->SpawnScale = 1.00f;
    this->MinWallDistance = 0.00f;
    this->SpawnFX = NULL;
    this->SpawnSound = NULL;
    this->bGroundOffset = false;
    this->HoloMeshRef = NULL;
    this->HoloMesh = NULL;
    this->HoloStartSound = NULL;
    this->HoloLoopSound = NULL;
    this->HoloStopSound = NULL;
    this->PlayedHoloLoopSound = NULL;
}

void UAPlayerSkill_Summon::SpawnHoloMesh() {
}

void UAPlayerSkill_Summon::ProcessSpawn(FNetworkSkillInfo NetworkInfo) {
}

void UAPlayerSkill_Summon::OnServerRepositionate_Implementation(FTransform NewTransfrom) {
}
bool UAPlayerSkill_Summon::OnServerRepositionate_Validate(FTransform NewTransfrom) {
    return true;
}

void UAPlayerSkill_Summon::OnRepSummonRefs() {
}

void UAPlayerSkill_Summon::OnMulticastRepositionate_Implementation(FTransform NewTransfrom) {
}

void UAPlayerSkill_Summon::OnLevelGenerationChanged(bool bIsGenerating) {
}

void UAPlayerSkill_Summon::OnDoorCrossedByAllPlayers(const FVector& DoorLocation, const FVector& ForwardVector) {
}

void UAPlayerSkill_Summon::OnActivateAIDeath(const FRQDamageInfo& DamageInfo) {
}

FVector UAPlayerSkill_Summon::GetTeleportLocation_Implementation() {
    return FVector{};
}

int32 UAPlayerSkill_Summon::GetSummonRefActivateAmount() const {
    return 0;
}

FVector UAPlayerSkill_Summon::GetSummonLocation_Implementation(FVector StartTrace, FVector ForwardVector, bool& bTriggerGroundOffset) {
    return FVector{};
}

float UAPlayerSkill_Summon::GetSummonLifespawn_Implementation() const {
    return 0.0f;
}

FTransform UAPlayerSkill_Summon::GetSpawnTransform(const FVector& StartTrace, const FVector& ForwardVector, bool bIsHolo) {
    return FTransform{};
}

float UAPlayerSkill_Summon::GetSpawnRange_Implementation() const {
    return 0.0f;
}

FVector UAPlayerSkill_Summon::GetSpawnLocation_Implementation(FVector StartTrace, FVector ForwardVector, bool& bTriggerGroundOffset) {
    return FVector{};
}

AActor* UAPlayerSkill_Summon::GetLongerActivateSummonRef() {
    return NULL;
}

FTransform UAPlayerSkill_Summon::GetHoloSpawnTransform(const FTransform& BaseSpawnTransform, const FVector& ForwardVector) const {
    return FTransform{};
}

FVector UAPlayerSkill_Summon::GetHoloLocation_Implementation(FVector StartTrace, FVector ForwardVector, bool& bTriggerGroundOffset) {
    return FVector{};
}

void UAPlayerSkill_Summon::DeactivateAllSummonRefs() {
}

void UAPlayerSkill_Summon::AddMaxSummonRef(int32 AddAmount) {
}

void UAPlayerSkill_Summon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UAPlayerSkill_Summon, SummonRefs);
}


