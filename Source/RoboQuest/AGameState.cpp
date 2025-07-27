#include "AGameState.h"
#include "AStatManager.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

AAGameState::AAGameState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AAGameState::UnregisterPinggableActor(AActor* ActorRef) {
}

void AAGameState::UnregisterJumpad(AAJumpad* Jumpad) {
}

void AAGameState::UnregisterGrapplePoint(AAGrapplePoint* Jumpad) {
}

void AAGameState::UnregisterCharacter(ETeam Team, AACharacter* Character) {
}

void AAGameState::UnlockPendingDifficulties() {
}

void AAGameState::TriggerBorealisPhase2() {
}

void AAGameState::StopTimeLimitationDamageTimer() {
}

void AAGameState::StopCheckingElapsedTime() {
}

void AAGameState::StartTimeLimitationDamageTimer(float SyncDelayInMs) {
}

void AAGameState::StartTimeLimitationDamageLoopTimer() {
}

void AAGameState::StartMutatorEnemyExplosion(const FVector& Location) {
}

AAInteractiveItem* AAGameState::SpawnPickupItem(const FVector& Location, const FRotator& Rotation, const FName& ItemRowName, bool bStartDeactivate, bool bSnapToGround) {
    return NULL;
}

void AAGameState::SpawnLocomotionVFXSurface(const FSurfaceSoundAndFx& FxAndSound, ELocomotionType LocomotionType, const FHitResult& HitResult, float OverrideDecalSize, float OverrideSoundVolume) {
}

AALevelGenerator* AAGameState::SpawnLevelGenerator(TSubclassOf<AALevelGenerator> LevelGeneratorClass) {
    return NULL;
}

bool AAGameState::ShouldPlayCinematic(FName RowName) const {
    return false;
}

void AAGameState::SetNewDifficulty(const FName& NewDifficulty) {
}

void AAGameState::SetGameTimePaused(bool bIsPaused) {
}

void AAGameState::SetGameLevelName(const FName& LevelName) {
}

void AAGameState::SetCheatCodeStatus(ECheatCode CheatCode, bool bIsActive) {
}


void AAGameState::RegisterReplicatedActor(AActor* ReplicatedActor) {
}

void AAGameState::RegisterPinggableActor(AActor* ActorRef) {
}

void AAGameState::RegisterJumpad(AAJumpad* Jumpad) {
}

void AAGameState::RegisterGrapplePoint(AAGrapplePoint* Jumpad) {
}

void AAGameState::RegisterCharacter(ETeam Team, AACharacter* Character) {
}

void AAGameState::OnStartShootingRangeChallenge(int32 Index, float InDuration) {
}

void AAGameState::OnStartLevel() {
}

void AAGameState::OnSplineDestroyed(AActor* Spline) {
}

void AAGameState::OnShootingRangeLayerLoaded(TSoftClassPtr<AActor> ShootingRangeLayerPtr) {
}

void AAGameState::OnRepSetNewDifficulty() {
}

void AAGameState::OnReplicatedActorDestroyed(AActor* DestroyedActor) {
}

void AAGameState::OnRemoveItemRow(const FName& ItemRow) {
}

void AAGameState::OnPlayerDisconnectedBeforeBeingInitialized(AController* ExitingPlayer) {
}

void AAGameState::OnPlayerDeath(ACharacter_Player* PlayerRef, bool bForceGameOver) {
}

void AAGameState::OnOneWayDoorDestroyed(AActor* Actor) {
}

void AAGameState::OnMutatorEnemyExplosionTriggerSoundLoaded() {
}

void AAGameState::OnMutatorEnemyExplosionPreshotSoundLoaded() {
}

void AAGameState::OnMutatorEnemyExplosionFXLoaded() {
}

void AAGameState::OnMulticastUnloadPreviousLevel_Implementation() {
}

void AAGameState::OnMulticastSetNewDifficulty_Implementation(const FName& NewDifficulty) {
}

void AAGameState::OnMulticastSendShootingRangeChallengeScore_Implementation(int32 Index, int32 Score) {
}

void AAGameState::OnMulticastLevelUp_Implementation(float Reliquat, EXPSource Source) {
}

void AAGameState::OnMaxClassLoaded(TSoftClassPtr<AAMax> MaxClassPtr) {
}

void AAGameState::OnLevelUp(float Reliquat, EXPSource Source) {
}

void AAGameState::OnGrantExperience(float Amount, EXPSource Source) {
}

void AAGameState::OnEndShootingRangeChallenge(int32 Index) {
}




void AAGameState::OnBasecampLayerLevelLoaded(TSoftClassPtr<AActor> BasecampLayerLevelPtr) {
}

void AAGameState::OnBaseBasecampLayerLevelLoaded(TSoftClassPtr<AActor> BaseBasecampLayerPtr) {
}

void AAGameState::NotifyStartTravelling() {
}

void AAGameState::MulticastSynchronizeLevelExperience_Implementation(float ServerLevelExperience) {
}

void AAGameState::MulticastSetCheatCodeStatus_Implementation(ECheatCode CheatCode, bool bIsActive) {
}

void AAGameState::MulticastSendServerFullArenaHealth_Implementation(const TArray<float>& ServerArenaHealth) {
}

void AAGameState::MulticastSendLocalData_Implementation(ACharacter_Player* Player, const FLocalPlayerData& Data) {
}

void AAGameState::MulticastSendLevelMaxTextsOnly_Implementation(const TArray<FName>& MaxTexts) {
}

void AAGameState::MulticastSendLevelInitData_Implementation(const FLevelInitData& LevelInitData) {
}

void AAGameState::MulticastOnMutatorTimeLimitationElapsed_Implementation() {
}

void AAGameState::MulticastOnCorruptedLevelTimeElapsed_Implementation() {
}

void AAGameState::LootWeaponPickup(ACharacter_Enemy* EnemyRef) {
}

bool AAGameState::IsTitleMap() const {
    return false;
}

bool AAGameState::IsTestMap() const {
    return false;
}

bool AAGameState::IsShootingRangeChallengeStarted(int32 Index) {
    return false;
}

bool AAGameState::IsRegisteredCharacter(ETeam Team, AACharacter* Character) const {
    return false;
}

bool AAGameState::IsRaceCorruptedLevel() const {
    return false;
}

bool AAGameState::IsMultiPlayerGame() const {
    return false;
}

bool AAGameState::IsLocalPlayerInitializedInBasecamp() const {
    return false;
}

bool AAGameState::IsLevelGeneratorMap() const {
    return false;
}

bool AAGameState::IsLavaCorruptedLevel() const {
    return false;
}

bool AAGameState::IsLastLevel() const {
    return false;
}

bool AAGameState::IsLastFailedLevel() {
    return false;
}

bool AAGameState::IsInLevelGeneratorMode() const {
    return false;
}

bool AAGameState::IsInfiniteRunMap() const {
    return false;
}

bool AAGameState::IsInfiniteRun() const {
    return false;
}

bool AAGameState::IsGameStateInitialized() const {
    return false;
}

bool AAGameState::IsGameAlreadyOver() const {
    return false;
}

bool AAGameState::IsCrystalActive(const FName& CrystalRowName) const {
    return false;
}

bool AAGameState::IsCrossplayMultiPlayerGame() const {
    return false;
}

bool AAGameState::IsCorruptedLevel() const {
    return false;
}

bool AAGameState::IsBasecampMap() const {
    return false;
}

bool AAGameState::IsAnInteractiveWeapon(const AActor* ReplicatedActor) const {
    return false;
}

void AAGameState::InitMutatorEnemyExplosion(float Delay, float Range, float Damage) {
}

void AAGameState::InitializeItemRows(UDataTable* DataTable, TArray<FName> ItemRows, bool bIgnoreLootable) {
}

void AAGameState::IncrementCurrentEnemyInitializationCount(ACharacter_Enemy* Enemy) {
}

TSubclassOf<ACharacter_Enemy> AAGameState::GetWorkerClass_Implementation(bool bIsLooping) const {
    return NULL;
}

TArray<FName> AAGameState::GetWeaponRowNamesForCompendium() const {
    return TArray<FName>();
}

TArray<FName> AAGameState::GetWeaponRowNames() const {
    return TArray<FName>();
}

FName AAGameState::GetWeaponRowNameFromClass(TSubclassOf<AAWeapon> WeaponClass) const {
    return NAME_None;
}

bool AAGameState::GetWeaponRowFromClass(TSubclassOf<AAWeapon> WeaponClass, FWeaponRow& OutWeaponRow) const {
    return false;
}

bool AAGameState::GetWeaponRow(const FName& RowName, FWeaponRow& OutWeaponRow) const {
    return false;
}

AAInteractiveWeapon* AAGameState::GetWeaponPickupFromPool() {
    return NULL;
}

float AAGameState::GetTotalLevelExperience() {
    return 0.0f;
}

TArray<AATarget*> AAGameState::GetTargetsByIndex(int32 Index) {
    return TArray<AATarget*>();
}

AATarget* AAGameState::GetTargetByLocation(FVector Location) {
    return NULL;
}

TArray<FString> AAGameState::GetStoryUnlocked() const {
    return TArray<FString>();
}

bool AAGameState::GetStoryRowFromRowName(const FName& RowName, FStoryCapsule& OutStoryRow) const {
    return false;
}

AAInteractiveWeapon* AAGameState::GetSpecificWeaponPickupFromPool(const FName& WeaponRowName, int32 WeaponLevel) {
    return NULL;
}

TArray<AAShootingRangeScreen*> AAGameState::GetShootingRangeScreenByIndex(int32 Index) {
    return TArray<AAShootingRangeScreen*>();
}

TArray<AAShootingRangeLight*> AAGameState::GetShootingRangeLightByIndex(int32 Index) {
    return TArray<AAShootingRangeLight*>();
}

AAShootingRangeButton* AAGameState::GetShootingRangeButton(FVector ButtonLocation) {
    return NULL;
}

bool AAGameState::GetServerLocalData(FLocalPlayerData& OutData) const {
    return false;
}

int32 AAGameState::GetSeededRandomRange(int32 Min, int32 Max, ERandomSeedID ID, const FString& Context, bool bSkippable) {
    return 0;
}

float AAGameState::GetRemainingCorruptedLevelTime() const {
    return 0.0f;
}

TArray<AACharacter*> AAGameState::GetRegisteredCharacters(ETeam Team) const {
    return TArray<AACharacter*>();
}

TSoftObjectPtr<UTexture2D> AAGameState::GetRankIcon(ERank rank, bool bIsSmall) const {
    return NULL;
}

ERank AAGameState::GetRankFromStarCount(uint8 Stars) const {
    return ERank::S;
}

TArray<FName> AAGameState::GetRandomItemRowsFromRarityWithExcludedRows(int32 Amount, EItemRarity Rarity, TArray<FName> ExcludedRows, ERandomSeedID SeedID, bool bFromChest) {
    return TArray<FName>();
}

TArray<FName> AAGameState::GetRandomItemRowsFromRarity(int32 Amount, EItemRarity Rarity, ERandomSeedID SeedID, bool bFromChest) {
    return TArray<FName>();
}

TArray<FName> AAGameState::GetRandomItemRowsFromRarities(int32 Amount, TArray<EItemRarity> Rarities, ERandomSeedID SeedID, bool bFromChest) {
    return TArray<FName>();
}

TArray<FName> AAGameState::GetRandomItemRows(int32 Amount, ERandomSeedID SeedID, bool bFromChest) {
    return TArray<FName>();
}

FName AAGameState::GetRandomItemRowFromRarity(ERandomSeedID SeedID, EItemRarity Rarity, TArray<FName> ExcludedItemRows, bool bFromChest) {
    return NAME_None;
}

FName AAGameState::GetRandomItemRowFromRarities(ERandomSeedID SeedID, TArray<EItemRarity> Rarities, TArray<FName> ExcludedItemRows, bool bFromChest) {
    return NAME_None;
}

FName AAGameState::GetRandomItemRow(ERandomSeedID SeedID, TArray<FName> ExcludedItemRows, bool bFromChest) {
    return NAME_None;
}

bool AAGameState::GetPlayerSpawnTransform(uint8 PlayerId, FTransform& OutSpawnTransform) const {
    return false;
}

TArray<ACharacter_Player*> AAGameState::GetPlayersFromLocalData() const {
    return TArray<ACharacter_Player*>();
}

ACharacter_Player* AAGameState::GetPlayerRefByMultiLoot(EMultiplayerLoot MultiplayerLoot) const {
    return NULL;
}

AActor* AAGameState::GetPinggableActorByLocation(FVector Location) {
    return NULL;
}

TArray<AAPickup*> AAGameState::GetPickupFromPool(EPickup Type, int32 Amount) {
    return TArray<AAPickup*>();
}

ENetworkMode AAGameState::GetNetworkMode() const {
    return ENetworkMode::Solo;
}

bool AAGameState::GetMutatorRow(const FName& RowName, FLevelGeneratorMutatorRow& OutMutatorRow) const {
    return false;
}

TArray<FName> AAGameState::GetMissingWeaponCards() {
    return TArray<FName>();
}

TArray<FName> AAGameState::GetMissingEnemyCards() {
    return TArray<FName>();
}

int32 AAGameState::GetMetaRewardsUnlockedCostFromRowName(const FName& RowName) {
    return 0;
}

int32 AAGameState::GetMetaRewardsUnlockedCost() {
    return 0;
}

int32 AAGameState::GetMetaRewardsTotalCostFromRowName(const FName& RowName) {
    return 0;
}

int32 AAGameState::GetMetaRewardsTotalCost() {
    return 0;
}

TArray<FName> AAGameState::GetMetaRewardBoardRowNamesForBasecampLevel() {
    return TArray<FName>();
}

TArray<FName> AAGameState::GetMetaRewardBoardRowNames() {
    return TArray<FName>();
}

bool AAGameState::GetMetaRewardBoardDataFromRowName(const FName& RowName, FMetaRewardBoard& OutMetaRewardBoardRow, bool bThrowError) {
    return false;
}

TSubclassOf<AAMax> AAGameState::GetMaxClass() const {
    return NULL;
}

ACharacter_Player* AAGameState::GetLocalPlayerRef() const {
    return NULL;
}

float AAGameState::GetLocalPlayerPing() const {
    return 0.0f;
}

AAPlayerController* AAGameState::GetLocalPlayerControllerRef() const {
    return NULL;
}

bool AAGameState::GetLocalData(ACharacter_Player* Player, FLocalPlayerData& OutData) const {
    return false;
}

TArray<FName> AAGameState::GetLevelStoryRowNames(const FName& LevelRowName) const {
    return TArray<FName>();
}

bool AAGameState::GetLevelRow(const FName& RowName, FLevelRow& OutLevelRow) const {
    return false;
}

AALevelGenerator* AAGameState::GetLevelGenerator() const {
    return NULL;
}

float AAGameState::GetLevelExperienceFromPath(const FName& LevelName) const {
    return 0.0f;
}

float AAGameState::GetLevelExperienceBySource(EXPSource Source) const {
    return 0.0f;
}

ERank AAGameState::GetLastRank(int32& OutXPStarCount, int32& OutTimeStarCount, bool& bOutHasXP) {
    return ERank::S;
}

float AAGameState::GetLastLevelTotalExperience() const {
    return 0.0f;
}

float AAGameState::GetLastLevelDuration() const {
    return 0.0f;
}

AAJumpad* AAGameState::GetJumpadFromLocation(const FVector& WorldLocation) const {
    return NULL;
}

bool AAGameState::GetItemRow(const FName& ItemRowName, FItem& OutItem, bool bIgnoreBazar) {
    return false;
}

TSubclassOf<AAInteractiveWeapon> AAGameState::GetInteractiveWeaponClass() const {
    return NULL;
}

TSubclassOf<AAInteractiveItem> AAGameState::GetInteractiveItemClass() const {
    return NULL;
}

TArray<FName> AAGameState::GetInitialDifficultyRows() const {
    return TArray<FName>();
}

AAGrapplePoint* AAGameState::GetGrapplePointFromLocation(const FVector& WorldLocation) const {
    return NULL;
}

ERank AAGameState::GetGlobalRank() const {
    return ERank::S;
}

AAInteractiveWeapon* AAGameState::GetGambleWeaponPickupFromPool(EMultiplayerLoot MultiplayerLoot, EGambleWeaponType WeaponType) {
    return NULL;
}

AAInteractiveWeapon* AAGameState::GetExtraWeaponPickupFromPool(EMultiplayerLoot MultiplayerLoot) {
    return NULL;
}

TArray<FName> AAGameState::GetEnemyRowNamesForCompendium() const {
    return TArray<FName>();
}

TArray<FName> AAGameState::GetEnemyRowNames() const {
    return TArray<FName>();
}

bool AAGameState::GetEnemyRowFromClass(TSubclassOf<ACharacter_Enemy> EnemyClass, FEnemyRow& OutEnemyRow) const {
    return false;
}

bool AAGameState::GetEnemyRow(const FName& RowName, FEnemyRow& OutEnemyRow) const {
    return false;
}

TArray<ACharacter_Enemy*> AAGameState::GetEnemiesByEncounter(uint8 EncounterID) const {
    return TArray<ACharacter_Enemy*>();
}

bool AAGameState::GetDifficultyDataFromRowName(const FName& RowName, FDifficultyRow& OutDifficultyRow) const {
    return false;
}

bool AAGameState::GetDifficultyData(FDifficultyRow& OutDifficultyRow) const {
    return false;
}

FName AAGameState::GetCurrentLevelName() const {
    return NAME_None;
}

float AAGameState::GetCurrentLevelDuration() const {
    return 0.0f;
}

int32 AAGameState::GetCurrentEliteValueFromCrystals() const {
    return 0;
}

int32 AAGameState::GetCurrentBasecampLevel(float& OutPercentLevel) {
    return 0;
}

uint8 AAGameState::GetCrystalFoundCountByLocalPlayer() const {
    return 0;
}

bool AAGameState::GetCrystalDataFromRowName(const FName& RowName, FCrystalRow& OutLevelCrystalRow) const {
    return false;
}

bool AAGameState::GetCrystalDataFromLevelName(const FName& LevelName, FCrystalRow& OutLevelCrystalRow) const {
    return false;
}

float AAGameState::GetCrystalCustomFloatProperty(const FName& RowName, const FName& FloatPropertyName) const {
    return 0.0f;
}

ECorruptedLevelType AAGameState::GetCorruptedLevelType() const {
    return ECorruptedLevelType::None;
}

float AAGameState::GetCorruptedLevelTimeLimitation() const {
    return 0.0f;
}

AACharacter* AAGameState::GetClosestActivatedCharacterWithoutStatus(const FVector& BaseLocation, ETeam Team, TArray<TSoftClassPtr<AACharacter>> ExcludedClasses, EStatus Status, AACharacter* RequestInstigator) const {
    return NULL;
}

AACharacter* AAGameState::GetClosestActivatedCharacterWithoutMultipleStatus(const FVector& BaseLocation, ETeam Team, TArray<TSoftClassPtr<AACharacter>> ExcludedClasses, TArray<EStatus> Status, AACharacter* RequestInstigator) const {
    return NULL;
}

AACharacter* AAGameState::GetClosestActivatedCharacter(const FVector& BaseLocation, ETeam Team, TArray<TSoftClassPtr<AACharacter>> ExcludedClasses, AACharacter* RequestInstigator) const {
    return NULL;
}

bool AAGameState::GetCheatCodeStatus(ECheatCode CheatCode) {
    return false;
}

AAInteractiveCard* AAGameState::GetCardFromPool(bool bWeaponCard, FName RowName) {
    return NULL;
}

float AAGameState::GetBossDuration() const {
    return 0.0f;
}

float AAGameState::GetBasecampCompletion() {
    return 0.0f;
}

TArray<FStoryCapsuleDataWithRowName> AAGameState::GetAllStoryCapsulesDataOrdered() const {
    return TArray<FStoryCapsuleDataWithRowName>();
}

TArray<ACharacter_Player*> AAGameState::GetAllPlayersOrdered() const {
    return TArray<ACharacter_Player*>();
}

TArray<ACharacter_Player*> AAGameState::GetAllPlayers() const {
    return TArray<ACharacter_Player*>();
}

TArray<FName> AAGameState::GetAllMutatorRowNames() const {
    return TArray<FName>();
}

TMap<FName, FLevelRow> AAGameState::GetAllLevelRows() const {
    return TMap<FName, FLevelRow>();
}

TArray<FName> AAGameState::GetAllLevelRowNames() const {
    return TArray<FName>();
}

TArray<FName> AAGameState::GetAllDifficultyRowNames() const {
    return TArray<FName>();
}

TMap<FName, FDifficultyRow> AAGameState::GetAllDifficultiesUnlocked() {
    return TMap<FName, FDifficultyRow>();
}

TArray<FName> AAGameState::GetAllDifficultiesToUnlock() const {
    return TArray<FName>();
}

TArray<FName> AAGameState::GetAllCrystalRowNames() const {
    return TArray<FName>();
}

TArray<FCrystalDataWithRowName> AAGameState::GetAllCrystalDataWithRowNames() const {
    return TArray<FCrystalDataWithRowName>();
}

TArray<FCrystalDataWithRowName> AAGameState::GetAllCrystalDataOrdered() const {
    return TArray<FCrystalDataWithRowName>();
}

TArray<FCrystalRow> AAGameState::GetAllCrystalData() const {
    return TArray<FCrystalRow>();
}

TArray<AATarget*> AAGameState::GetActivatedTargetsInRange(FVector BaseLocation, float Range, bool bSorted) {
    return TArray<AATarget*>();
}

TArray<AATarget*> AAGameState::GetActivatedTargets() {
    return TArray<AATarget*>();
}

TArray<AACharacter*> AAGameState::GetActivatedCharactersInRange(const FVector& BaseLocation, ETeam Team, float Range, bool bSorted) const {
    return TArray<AACharacter*>();
}

TArray<AACharacter*> AAGameState::GetActivatedCharacters(ETeam Team) const {
    return TArray<AACharacter*>();
}

void AAGameState::EnsureClientIsUnloadingPreviousLevel() {
}

void AAGameState::DelayedOnLevelUp() {
}

void AAGameState::DeactivateCharacter(ETeam Team, AACharacter* Character) {
}

bool AAGameState::AreAllCrystalsFound() const {
    return false;
}

void AAGameState::ApplyTimeLimitationDamageToAllPlayers() {
}

bool AAGameState::AnyPlayerHasPermanentReward(EPermanentReward InPermanentReward) const {
    return false;
}

bool AAGameState::AnyPlayerHasGambleGarryUnlocked() const {
    return false;
}

bool AAGameState::AllPlayersHavePermanentReward(EPermanentReward InPermanentReward) const {
    return false;
}

bool AAGameState::AllPlayersHaveFoundCrystal(const FName& LevelName) const {
    return false;
}

bool AAGameState::AllPlayersAreReadyToStartInfiniteGame() const {
    return false;
}

bool AAGameState::AllPlayersAreReadyToStartGame() const {
    return false;
}

void AAGameState::AddPickupLifetimeModifier(EPickup Type, float NewModifier) {
}

void AAGameState::AddGameTip(const FName& RowName) {
}

void AAGameState::AddCrystalFoundToAllPlayers() {
}

void AAGameState::AddCardToPool(AAInteractiveCard* Card) {
}

void AAGameState::AddBazarItemCostReduction(int32 NewReduction) {
}

void AAGameState::ActivateTimeLimitationMutator(float DamagePercentAmount, float DamageFirerate) {
}

void AAGameState::ActivateCharacter(ETeam Team, AACharacter* Character) {
}

void AAGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AAGameState, DifficultyRow);
}


