#include "AGameInstance.h"

UAGameInstance::UAGameInstance() {
    this->bIsViewportActivated = false;
    this->FpsLimitOnPause = 0;
    this->FpsLimitOnMinimized = 0;
    this->FriendlistUpdateInterval = 15.00f;
    this->LowFriendUpdateInterval = 5.00f;
    this->MediumFriendUpdateInterval = 15.00f;
    this->HighFriendUpdateInterval = 60.00f;
    this->InviteUpdateInterval = 2.00f;
    this->InviteTimeout_Inbound = 30.00f;
    this->InviteTimeout_Outbound = 30.00f;
    this->CurrentFPSLimit = -1;
    this->EffectQuality = ESettingsQuality::Low;
}

void UAGameInstance::VerifyAchievementsValidity() {
}

bool UAGameInstance::UpgradeCompendiumEntry(const FName& Name, ECompendiumCategoryWithLevel InCategory) {
    return false;
}

void UAGameInstance::UpgradeCompendiumCategoryVersion(ECompendiumCategory InCategory) {
}



void UAGameInstance::UpdateFriendlist() {
}

void UAGameInstance::UpdateFPSLimit() {
}

void UAGameInstance::UpdateAchievementStat_Implementation(FName StatName, int32 StatValue, bool bIncremental, bool bDelaySendDatas) {
}







void UAGameInstance::UnlockAchievement_Implementation(FName AchievementName) {
}

void UAGameInstance::UnlinkLocalUserAccount() {
}

bool UAGameInstance::TryToSaveRun() {
    return false;
}

void UAGameInstance::TryForceViewportActivated() {
}


void UAGameInstance::StopTimer(const FString& Context) {
}

void UAGameInstance::StopFriendListPulling() {
}

void UAGameInstance::StartTimer(const FString& Context) {
}

void UAGameInstance::StartFriendlistPulling() {
}

void UAGameInstance::StartBlockedPlayersPulling() {
}





bool UAGameInstance::ShouldSendStats(const FName& StatName, int32 NewValue, ERankStatAchievement& OutNewRank, int32 OldValue, bool bDelaySendDatas) {
    return false;
}












void UAGameInstance::SetNewLastCompendiumCategoryVersion(ECompendiumCategory InCategory) {
}

void UAGameInstance::SetGamePaused(bool bPause, const FString& Context) {
}

void UAGameInstance::SetFriendlistUpdateInterval_Medium() {
}

void UAGameInstance::SetFriendlistUpdateInterval_Low() {
}

void UAGameInstance::SetFriendlistUpdateInterval_High() {
}

void UAGameInstance::SetFriendlistUpdateInterval(float NewUpdateInterval) {
}

void UAGameInstance::SetEOSGlobalConfig(const FPerPlatformEOSConfig& PerPlatformConfigs) {
}





void UAGameInstance::SetBlockedUser(const FPlayerBlockList& PlayerBlockList) {
}



void UAGameInstance::SetAchievementAsUnlockedForOss(const TArray<FName>& OssNames, const FName& AchievementName) {
}

void UAGameInstance::SendAchievementStats_Implementation() {
}





void UAGameInstance::ResetStoryUnlocked_Implementation() {
}






void UAGameInstance::ResetAllCompendiumCategoriesVersion() {
}

void UAGameInstance::RemoveUserFromBlockList(const FString& UserIdString) {
}




void UAGameInstance::RejectInboundInvite(const FString& friendId) {
}

void UAGameInstance::ReinitializeCompendium() {
}


void UAGameInstance::RegisterActorForDestroy(AActor* ActorToRegister) {
}

void UAGameInstance::PrintSaveProfile() {
}

void UAGameInstance::OnLootCompendiumCard(const FName& Name, ECompendiumCategoryWithLevel InCategory) {
}












void UAGameInstance::LoadCompendiumData(const FString& JsonString) {
}


bool UAGameInstance::IsStoryUnlocked(const FName& RowName) {
    return false;
}





bool UAGameInstance::IsPendingDestroy(AActor* Actor) const {
    return false;
}

bool UAGameInstance::IsLastRunVictorious() const {
    return false;
}







bool UAGameInstance::IsEOSUserBlocked(const FString& EOSUserIdString) const {
    return false;
}





bool UAGameInstance::IsCompendiumEntryUpgraded(const FName& Name, ECompendiumCategoryWithLevel InCategory) {
    return false;
}

bool UAGameInstance::IsCompendiumCategoryModified(ECompendiumCategory InCategory) {
    return false;
}


bool UAGameInstance::IsAchievementUnlockForAllOss(const TArray<FName>& OssNames, const FName& AchievementName) {
    return false;
}

bool UAGameInstance::IsAchievementUnlock(const FName& OSSName, const FName& AchievementName) {
    return false;
}


void UAGameInstance::InitAchievements_Implementation() {
}

void UAGameInstance::IncreaseCompendiumWeaponCompletion(const FName& Name, int32 Multiplier) {
}









bool UAGameInstance::HaveUnlockAllStoriesOfLevel(const FName& LevelRowName) {
    return false;
}

bool UAGameInstance::HaveUnlockAllArtefactsInLG() {
    return false;
}


bool UAGameInstance::HaveFoundAllCrystals() {
    return false;
}

bool UAGameInstance::HaveAnyCompendiumEntryUpgradedOfCategoryWithExcludeRowNames(ECompendiumCategoryWithLevel InCategory, TArray<FName> ExcludeRowNames) {
    return false;
}

bool UAGameInstance::HaveAnyCompendiumEntryUpgradedOfCategory(ECompendiumCategoryWithLevel InCategory) {
    return false;
}



bool UAGameInstance::GlobalConfig_CanCrossPlay() const {
    return false;
}


void UAGameInstance::GetWeaponCompletion(const FName& Name, int32& OutCurrentCompletion, int32& OutMaxCompletion, float& OutPercent) {
}




int32 UAGameInstance::GetStoryUnlockedAmount() {
    return 0;
}




bool UAGameInstance::GetSanitizedName(const FString& NameToSanitize, FString& OutSanitizedName) {
    return false;
}

float UAGameInstance::GetRunRecapTotalDamageDealt() const {
    return 0.0f;
}

TMap<FName, ERank> UAGameInstance::GetRunRecapRankByLevels() const {
    return TMap<FName, ERank>();
}







FPlayerBlockList UAGameInstance::GetPlayerBlocklist() const {
    return FPlayerBlockList{};
}



TArray<FName> UAGameInstance::GetNonUpgdradedDataNamesByCategory(ECompendiumCategoryWithLevel InCategory) {
    return TArray<FName>();
}







TArray<FName> UAGameInstance::GetMetaRewards() {
    return TArray<FName>();
}


FString UAGameInstance::GetLogLines() {
    return TEXT("");
}

AAPlayerController* UAGameInstance::GetLocalPlayerController() const {
    return NULL;
}


FName UAGameInstance::GetLinkedAchievementNameByStatName(const FName& StatName) {
    return NAME_None;
}

bool UAGameInstance::GetLastRunRecap(FRunRecap& OutLastRunRecap) const {
    return false;
}

int64 UAGameInstance::GetKillAmountOfCurrentRun() const {
    return 0;
}

int64 UAGameInstance::GetKillAmount() const {
    return 0;
}



TArray<uint8> UAGameInstance::GetInitialBossEncounteredID(const TArray<TSoftClassPtr<ACharacter_Enemy>>& FirstExpectedEncounteredBosses) {
    return TArray<uint8>();
}

FCompendiumHistory UAGameInstance::GetHistoryDatas() {
    return FCompendiumHistory{};
}


bool UAGameInstance::GetGDKConnectionStatus() const {
    return false;
}


AAGameState* UAGameInstance::GetGameStateRef() const {
    return NULL;
}





FName UAGameInstance::GetFavoriteEntry(const TMap<FName, int32>& Entries) const {
    return NAME_None;
}

FString UAGameInstance::GetFavoriteBrobot() {
    return TEXT("");
}

int32 UAGameInstance::GetEnemyAmountToUpgradeWeapon() {
    return 0;
}




TArray<FCrystalFound> UAGameInstance::GetCrystalsFoundForLocalData() {
    return TArray<FCrystalFound>();
}









FString UAGameInstance::GetCompendiumDataStringFromStruct() {
    return TEXT("");
}



FString UAGameInstance::GetBrobotNameByID(const FString& PlayerId) {
    return TEXT("");
}


TArray<uint8> UAGameInstance::GetBlockedUsersDataForWrite() const {
    return TArray<uint8>();
}

FIntPoint UAGameInstance::GetBestFullscreenResolution() {
    return FIntPoint{};
}







TArray<FName> UAGameInstance::GetAllCompendiumEntriesByCat(ECompendiumCategory InCategory) {
    return TArray<FName>();
}



FPlayerRunSaveGame UAGameInstance::GeneratePlayerSaveRunData() {
    return FPlayerRunSaveGame{};
}

FGeneratorRunSaveGame UAGameInstance::GenerateGeneratorSaveRunData() {
    return FGeneratorRunSaveGame{};
}

bool UAGameInstance::DoesPerkExistInCompendium_Implementation(const FName& PerkName, const EPerkCompendiumCategory Category) {
    return false;
}

bool UAGameInstance::DoesEntryExistInCompendium(const FName& Name, ECompendiumCategory InCategory) {
    return false;
}

void UAGameInstance::DebugRecap(const FRunRecap& Recap) {
}

void UAGameInstance::DebugHistory() {
}

void UAGameInstance::DebugCompendium() {
}


void UAGameInstance::ConsumeInboundInvite(const FString& friendId) {
}



void UAGameInstance::CheckLastJoinSessionError() {
}

void UAGameInstance::CheatCodeTestAchievement() {
}

void UAGameInstance::CancelAllOutboundInvites() {
}

void UAGameInstance::CallGDKConnectionStatusChanged_DEBUG() {
}

void UAGameInstance::BlockInboundInvite(const FString& friendId) {
}

bool UAGameInstance::AddUserToBlockList(const AAPlayerState* PlayerState, FBlockedPlayer& OutBlockedPlayer) {
    return false;
}

void UAGameInstance::AddSanitizedName(const FString& NameToSanitize, const FString& SanitizedName) {
}

bool UAGameInstance::AddPerkEntryToCompendium(const FName& Name, EPerkCompendiumCategory InPerkCategory) {
    return false;
}



uint8 UAGameInstance::AddFlagToBitmask(uint8 NewFlag, uint8 Bitmask) {
    return 0;
}



bool UAGameInstance::AddEntryToCompendium(const FName& Name, ECompendiumCategory InCategory) {
    return false;
}





