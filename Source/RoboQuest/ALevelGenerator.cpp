#include "ALevelGenerator.h"
#include "Templates/SubclassOf.h"

AALevelGenerator::AALevelGenerator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InfiniteTicketByRank[0] = 0;
    this->InfiniteTicketByRank[1] = 0;
    this->InfiniteTicketByRank[2] = 0;
    this->InfiniteTicketByRank[3] = 0;
    this->InfiniteTicketByRank[4] = 0;
    this->InfiniteTicketByRank[5] = 0;
    this->InfiniteRunEnemyLevel = 1;
    this->CurrentInfiniteBossMusic = NULL;
    this->CurrentInfiniteMusic = NULL;
    this->InteriorInfiniteBossTileClass = NULL;
    this->InfiniteBossHoleSpawnerClass = NULL;
    this->CurrentInfiniteRunLevelAmount = 0;
    this->CurrentInfiniteRunActAmount = 0;
    this->AddEliteValue = 0;
    this->AddBigValue = 0;
    this->TrapMultiplier = 1.00f;
    this->TicketModifier = 0;
    this->bActivateTrap = false;
    this->HeadbonkBubbleMutatorLuck = 0.00f;
    this->EyeProtectionMutatorLuck = 0.00f;
    this->TurretEmpowerMutatorLuck = 0.00f;
    this->EnemyExplosionMutatorLuck = 0.00f;
    this->bCommonGeneratorDataAssetInit = false;
    this->StartTile = NULL;
    this->EndLevelBeam = NULL;
    this->DT_EnemyBoard = NULL;
    this->RegularWorkerSpawnClass = NULL;
    this->LoopingWorkerSpawnClass = NULL;
    this->DT_MaxTexts = NULL;
    this->InteractiveStoryClass = NULL;
    this->OasisCorruptedDoorTimeLimit = 0.00f;
    this->NasaDoorTimeLimit = 0.00f;
    this->CorruptedRuinsArenaHealthPercentModifier = 0.00f;
    this->CorruptedRuinsArenaImpactPercentModifier = 0.00f;
    this->MPC_Corrupted = NULL;
    this->MoonBossTileClassLoaded = NULL;
    this->MoonBossTile = NULL;
    this->MoonBossClassLoaded = NULL;
    this->MoonBossMusic = NULL;
    this->BossLayerClass = NULL;
    this->BossLayer = NULL;
    this->BossSequence = NULL;
    this->NextBossID = 0;
    this->StartingWorkerSplineMesh = NULL;
    this->EndingWorkerSplineMesh = NULL;
    this->BaseWorkerSplineMesh = NULL;
    this->TrapClasses[0] = NULL;
    this->TrapClasses[1] = NULL;
    this->TrapClasses[2] = NULL;
    this->TrapClasses[3] = NULL;
    this->TrapClasses[4] = NULL;
    this->TrapClasses[5] = NULL;
    this->TrapClasses[6] = NULL;
    this->TrapClasses[7] = NULL;
    this->TrapClasses[8] = NULL;
    this->TrapClasses[9] = NULL;
    this->TrapClasses[10] = NULL;
    this->GameInstanceRef = NULL;
    this->GameModeRef = NULL;
    this->GameStateRef = NULL;
    this->LightSelectorRef = NULL;
}

void AALevelGenerator::UnlockEndActAchievement() {
}

void AALevelGenerator::ShowLoadingError(const FString& ErrorMsg) {
}

void AALevelGenerator::SendLoadingStep(ELoadingStep LoadingStep, bool bIsStarting, bool bIsLocal) {
}

void AALevelGenerator::RandomizeLevel() {
}

void AALevelGenerator::OnStorySpawnClassLoaded(TSoftClassPtr<AActor> SpawnClass, FTransform SpawnTransform, FName RowName) {
}

void AALevelGenerator::OnStartTileLootRegistered() {
}

void AALevelGenerator::OnPlayerDisconnectedDuringGeneration(AController* ExitingPlayer) {
}

void AALevelGenerator::OnMutatorLoaded(FLevelGeneratorMutatorRow MutatorRow, FName RowName, bool bInit, int32 Index) {
}

void AALevelGenerator::OnHoleSpawnerDestroyed(AActor* Actor) {
}

void AALevelGenerator::OnBossTakeDamage(const FRQDamageInfo& DamageInfo) {
}









void AALevelGenerator::OnBigDeathDuringQuest(const FRQDamageInfo& DamageInfo) {
}

bool AALevelGenerator::IsTutoLevel() const {
    return false;
}

bool AALevelGenerator::IsStraightLineLevel() const {
    return false;
}

bool AALevelGenerator::IsRaceCorruptedLevel() const {
    return false;
}

bool AALevelGenerator::IsNasaDoorStillOpened(float GameTime, bool bPrintLog) const {
    return false;
}

bool AALevelGenerator::IsLavaCorruptedLevel() const {
    return false;
}

bool AALevelGenerator::IsLastLevelOfAct(const FName& NextLevelRowName) const {
    return false;
}

bool AALevelGenerator::IsLastLevel() const {
    return false;
}

bool AALevelGenerator::IsInfiniteRun() const {
    return false;
}

bool AALevelGenerator::IsFirstLevelOfRun() const {
    return false;
}

bool AALevelGenerator::IsEnemyGenerationFinished() const {
    return false;
}

bool AALevelGenerator::IsCorruptedLevelPath(const FName& LevelDestinationName) const {
    return false;
}

bool AALevelGenerator::IsCorruptedLevel() const {
    return false;
}

bool AALevelGenerator::IsActiveOrPendingMutator(const FName& RowName) const {
    return false;
}

void AALevelGenerator::IncrementUnlockedStoryCapsuleCount() {
}

TSubclassOf<ACharacter_Enemy> AALevelGenerator::GetWorkerClass(bool bIsLooping) const {
    return NULL;
}

int32 AALevelGenerator::GetWeaponLevel() const {
    return 0;
}

float AALevelGenerator::GetWaitingOtherPlayerTimer() const {
    return 0.0f;
}

float AALevelGenerator::GetUnloadingLevelTimer() const {
    return 0.0f;
}

float AALevelGenerator::GetTotalLoadingTimer() const {
    return 0.0f;
}

AATile* AALevelGenerator::GetTileFromWorldLocation(const FVector& WorldLocation) const {
    return NULL;
}

int32 AALevelGenerator::GetTicketByRank(ERank rank) const {
    return 0;
}

AAStartTile* AALevelGenerator::GetStartTile() const {
    return NULL;
}

TMap<FName, FSpecificWeaponInPool> AALevelGenerator::GetSpecificWeaponsInPool(bool bIsMultiPlayerGame) {
    return TMap<FName, FSpecificWeaponInPool>();
}

int32 AALevelGenerator::GetSpecificWeaponPickupPoolCount(bool bIsMultiPlayerGame) {
    return 0;
}

FSidePath AALevelGenerator::GetSidePath(int32 PathID) const {
    return FSidePath{};
}

float AALevelGenerator::GetSeededRandomRangeFloat(float Min, float Max, const FString& Context, ERandomSeedID ID, bool bSkippable) {
    return 0.0f;
}

int32 AALevelGenerator::GetSeededRandomRange(int32 Min, int32 Max, const FString& Context, ERandomSeedID ID, bool bSkippable) {
    return 0;
}

TArray<AASasTile*> AALevelGenerator::GetSasTiles() const {
    return TArray<AASasTile*>();
}

ERank AALevelGenerator::GetRank(const FName& GameLevel, float LevelDuration, float LevelTotalExperience, int32& OutXPStarCount, int32& OutTimeStarCount, bool& bOutHasXP) {
    return ERank::S;
}

float AALevelGenerator::GetPercentForCompletionTime(bool bIsCorruptedPath, int32 PathID, float Duration) const {
    return 0.0f;
}

int32 AALevelGenerator::GetPathIDFromLevelName(const FName& LevelName) const {
    return 0;
}

bool AALevelGenerator::GetNextLevelName(int32 PathID, FName& OutRowName) const {
    return false;
}

float AALevelGenerator::GetNavMeshGenerationTimer() const {
    return 0.0f;
}

AAMoonBossTile* AALevelGenerator::GetMoonBossTileRef() const {
    return NULL;
}
TArray<FVector2D> AALevelGenerator::GetMerchantItemLuck() const {
    return TArray<FVector2D>();
}

bool AALevelGenerator::GetMaxTextFromRowName(const FName& RowName, FText& OutText, EMaxTextType& OutType) const {
    return false;
}

bool AALevelGenerator::GetMaxText(ETileType TileType, FName& OutRowName) {
    return false;
}

FIntPoint AALevelGenerator::GetLootRange() const {
    return FIntPoint{};
}

float AALevelGenerator::GetLootGenerationTimer() const {
    return 0.0f;
}

AAPlayerController* AALevelGenerator::GetLocalPlayerControllerRef() const {
    return NULL;
}

AALightSelector* AALevelGenerator::GetLightSelectorRef() const {
    return NULL;
}

float AALevelGenerator::GetLevelTimeRatioRemaining(float Duration) const {
    return 0.0f;
}


float AALevelGenerator::GetLevelGenerationTimer() const {
    return 0.0f;
}

float AALevelGenerator::GetExtractingPackageTimer() const {
    return 0.0f;
}

int32 AALevelGenerator::GetEnemyLevel() const {
    return 0;
}

float AALevelGenerator::GetEnemyGenerationTimer() const {
    return 0.0f;
}

FName AALevelGenerator::GetEndCinematicRowName() const {
    return NAME_None;
}

AActor* AALevelGenerator::GetDiggingHoleFromLocation(const FVector& WorldLocation) const {
    return NULL;
}

FName AALevelGenerator::GetCurrentLevelName() const {
    return NAME_None;
}

int32 AALevelGenerator::GetCountOfActiveMutatorsByTypes(const TArray<EMutatorType>& Types) const {
    return 0;
}

ECorruptedLevelType AALevelGenerator::GetCorruptedLevelType() const {
    return ECorruptedLevelType::None;
}

float AALevelGenerator::GetCorruptedLevelTimeLimitation(ECorruptedRaceDifficulty Difficulty) const {
    return 0.0f;
}

int32 AALevelGenerator::GetCorruptedLevelPathIDFromLevelName(const FName& LevelName) const {
    return 0;
}

bool AALevelGenerator::GetCorruptedLevelPathFromLocation(ETileType Location, FCorruptedLevelPath& OutCorruptedLevelPath) const {
    return false;
}

FCorruptedLevelPath AALevelGenerator::GetCorruptedLevelPath(int32 PathID) const {
    return FCorruptedLevelPath{};
}

TSoftObjectPtr<ULevelSequence> AALevelGenerator::GetCorruptedLevelArenaSequence() const {
    return NULL;
}

FText AALevelGenerator::GetCorruptedLevelArenaName() const {
    return FText::GetEmpty();
}

FVector2D AALevelGenerator::GetCompletionTimeRange(bool bIsCorruptedPath, int32 PathID) const {
    return FVector2D{};
}

int32 AALevelGenerator::GetCodeNumber() {
    return 0;
}

TArray<AABossTile*> AALevelGenerator::GetBossTilesRef() const {
    return TArray<AABossTile*>();
}

FActBoss AALevelGenerator::GetBossData() const {
    return FActBoss{};
}

TArray<AAArenaTile*> AALevelGenerator::GetArenaTiles() const {
    return TArray<AAArenaTile*>();
}

USoundCue* AALevelGenerator::GetAmbientSound() {
    return NULL;
}

TArray<UALevelGeneratorMutator*> AALevelGenerator::GetAllActiveMutators() const {
    return TArray<UALevelGeneratorMutator*>();
}

TArray<FName> AALevelGenerator::GetAllActiveMutatorNamesWithoutScalable() const {
    return TArray<FName>();
}

TArray<FName> AALevelGenerator::GetAllActiveMutatorNames() const {
    return TArray<FName>();
}

UALevelGeneratorMutator* AALevelGenerator::GetActiveMutatorByRowName(const FName& RowName) const {
    return NULL;
}

UALevelGeneratorMutator* AALevelGenerator::FindActiveParentMutator(const FName& RowName) const {
    return NULL;
}

void AALevelGenerator::ExtractRowFromDataTable(const FName& RowName) {
}

void AALevelGenerator::DelayedInitAllArenaTiles() {
}

void AALevelGenerator::DeactivateTrapsOfGroupPermanently(uint8 ID) {
}

void AALevelGenerator::CleanUpTilesFromQueue() {
}

void AALevelGenerator::AllOrderableActorsRegistered() {
}

void AALevelGenerator::AllDoorsRegistered(AATile* Tile) {
}

void AALevelGenerator::AddPercentChanceToHaveAdditionalInfiniteRunEnemiesByEncounter(TSoftClassPtr<ACharacter_Enemy> EnemyClass, TArray<float> PercentChances) {
}

void AALevelGenerator::AddAdditionalInfiniteRunEnemies(TSoftClassPtr<ACharacter_Enemy> EnemyClass, int32 Count) {
}


