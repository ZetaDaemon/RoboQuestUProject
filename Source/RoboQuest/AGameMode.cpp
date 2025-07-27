#include "AGameMode.h"
#include "Templates/SubclassOf.h"

AAGameMode::AAGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

FPlayerClassRow AAGameMode::SyncGetPlayerClassRow(const FName& RowName) {
    return FPlayerClassRow{};
}

AAInteractiveWeapon* AAGameMode::SpawnPickupWeaponByPowerLevel(const FIntPoint& LootRange, const FVector& Location, const FRotator& Rotation, EMultiplayerLoot MultiplayerLoot, int32 WeaponLevel, TArray<TSubclassOf<AAWeapon>> ExcludedWeapons) {
    return NULL;
}

AAInteractiveWeapon* AAGameMode::SpawnPickupWeapon(const FVector& Location, const FRotator& Rotation, AAWeapon* WeaponRef, TSubclassOf<AAWeapon> WeaponClass, bool bStartDeactivate, int32 BaseRandomSeed, EMultiplayerLoot MultiplayerLoot, int32 WeaponLevel, int32 AffixAmount, bool bInitialWeapon, bool bSnapToGround, EWeaponMetaRewardModifier MetaRewardModifier, TSubclassOf<AAInteractiveWeapon> OverrideClass, TSoftClassPtr<AAWeapon> WeaponClassSoftPtr) {
    return NULL;
}

bool AAGameMode::ShouldSetNetworkModeMulti() const {
    return false;
}

void AAGameMode::SetNewPlayerData(const FPlayerData& NewPlayerData) {
}

void AAGameMode::OnWeaponsDataTableLoaded() {
}

void AAGameMode::OnWeaponLoaded() {
}

void AAGameMode::OnPlayerReadyForNextLevel(AController* Controller) {
}

void AAGameMode::OnPlayerDisconnectedDuringEndLevel(AController* Controller) {
}

void AAGameMode::OnPlayerClassesDataTableLoaded(const FString& UniqueIdString, FName ClassRowName, FTransform SpawnTransform) {
}

void AAGameMode::OnEndLevel(const FName& NextLevelName) {
}

void AAGameMode::OnEndGame(bool bVictory) {
}

void AAGameMode::OnCommonWeaponDataAssetLoaded() {
}







void AAGameMode::LoadCommonWeaponDataAsset() {
}

TSubclassOf<AAWeapon> AAGameMode::GetWeaponClassLoaded(TSoftClassPtr<AAWeapon> WeaponClassPtr) {
    return NULL;
}

TSubclassOf<AAWeapon> AAGameMode::GetRandomWeaponClassByCategory(const FIntPoint& LootRange, EWeaponCategory Category, ACharacter_Player* PlayerRef, TArray<TSubclassOf<AAWeapon>> ExcludedWeapons, ERandomSeedID SeedID) {
    return NULL;
}

TSubclassOf<AAWeapon> AAGameMode::GetRandomWeaponClass(const FIntPoint& LootRange, ACharacter_Player* PlayerRef, TArray<TSubclassOf<AAWeapon>> ExcludedWeapons, ERandomSeedID SeedID) {
    return NULL;
}

TArray<FPlayerData> AAGameMode::GetPlayersDataArray() const {
    return TArray<FPlayerData>();
}

int32 AAGameMode::GetMaxLevelWeaponPickupValue() {
    return 0;
}

AAPlayerController* AAGameMode::GetLocalPlayerControllerRef() const {
    return NULL;
}

AAGameState* AAGameMode::GetGameStateRef() const {
    return NULL;
}

void AAGameMode::ExtractWeaponData() {
}


