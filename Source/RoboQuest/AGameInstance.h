#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=AccelByteUe4Sdk -ObjectName=AccountUserData -FallbackName=AccountUserData
//CROSS-MODULE INCLUDE V2: -ModuleName=AdvancedSessions -ObjectName=EBPLoginStatus -FallbackName=EBPLoginStatus
//CROSS-MODULE INCLUDE V2: -ModuleName=AdvancedSessions -ObjectName=EBPUserPrivileges -FallbackName=EBPUserPrivileges
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=IntPoint -FallbackName=IntPoint
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=GameInstance -FallbackName=GameInstance
//CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
//CROSS-MODULE INCLUDE V2: -ModuleName=OnlineSubsystemUtils -ObjectName=BlueprintSessionResult -FallbackName=BlueprintSessionResult
#include "BlockedPlayer.h"
#include "BlueprintAchievementMap.h"
#include "BlueprintUserStats.h"
#include "Compendium.h"
#include "CompendiumHistory.h"
#include "CrystalFound.h"
#include "DifficultyCompletion.h"
#include "EAutoReloadMode.h"
#include "ECheatCode.h"
#include "ECompendiumCategory.h"
#include "ECompendiumCategoryWithLevel.h"
#include "EController.h"
#include "ECrosshairColor.h"
#include "ECrosshairMode.h"
#include "ECrouchMode.h"
#include "EPerkCompendiumCategory.h"
#include "EPermanentReward.h"
#include "EQuestLevel.h"
#include "ERank.h"
#include "ERankStatAchievement.h"
#include "EScopeMode.h"
#include "ESettingsQuality.h"
#include "ESettingsQualityWithOff.h"
#include "ESprintMode.h"
#include "GeneratorRunSaveGame.h"
#include "MetaRewardSaved.h"
#include "PerPlatformEOSConfig.h"
#include "PlayerBlockList.h"
#include "PlayerRunSaveGame.h"
#include "RunRecap.h"
#include "AGameInstance.generated.h"

class AAGameState;
class AAPlayerController;
class AAPlayerState;
class AActor;
class ACharacter_Enemy;
class UTexture2D;

UCLASS(Blueprintable, NonTransient)
class ROBOQUEST_API UAGameInstance : public UGameInstance {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOSSUnlinkCompletedDelegate, bool, bSuccessful, const FString&, ErrorMessage);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOSSLogoutCompletedDelegate);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUserBlockListUpdatedDelegate, const FPlayerBlockList&, BlockedUsers);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSignedInWithConsoleDelegate, bool, bNewUserSignedIn);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPeerConnectionInterruptedDelegate);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPeerConnectionEstablishedDelegate);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnApplicationEnteredForegroundDelegate, float, Duration);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnApplicationEnteredBackgroundDelegate);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGDKConnectionStatusChangedDelegate, bool, bSuccessful);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFriendAvatarUpdateDelegate, const FString&, UserIdAsString, UTexture2D*, Avatar);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateUnlockDifficulty, const FName&, RowName);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateUnlockAchievement, const FName&, ID, bool, bUnlock);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnUpgradeCompendiumEntry, FName, Name, ECompendiumCategoryWithLevel, Category);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnUpdateLocalization, const FString&, NewLanguage);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnResetProfile);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnIncreaseCompendiumWeaponCompletion, FName, Name);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnGlobalTimerStopped, const FString&, TimeContext);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnGlobalTimerStopped DelegateOnGlobalTimerStopped;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsViewportActivated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FpsLimitOnPause;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FpsLimitOnMinimized;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSignedInWithConsoleDelegate OnSignedInWithConsoleDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOSSUnlinkCompletedDelegate OnUnlinkCompletedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGDKConnectionStatusChangedDelegate OnGDKConnectionStatusChangedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnUserBlockListUpdatedDelegate OnUserBlockListUpdatedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFriendAvatarUpdateDelegate OnFriendAvatarUpdateDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FriendlistUpdateInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LowFriendUpdateInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MediumFriendUpdateInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HighFriendUpdateInterval;
    
private:
    
public:
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> BlockedInvites;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InviteUpdateInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InviteTimeout_Inbound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InviteTimeout_Outbound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FBlueprintAchievementMap> CachedAchievements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintUserStats CachedStats;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateUnlockAchievement DelegateOnUnlockAchievement;
    
    UPROPERTY(BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnResetProfile DelegateOnResetProfile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentFPSLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESettingsQuality EffectQuality;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnUpgradeCompendiumEntry DelegateOnUpgradeCompendiumEntry;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCompendium CompendiumData;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRunRecap CurrentRunRecap;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnUpdateLocalization DelegateOnUpdateLocalization;
    
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPeerConnectionEstablishedDelegate OnPeerConnectionEstablishedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPeerConnectionInterruptedDelegate OnPeerConnectionInterruptedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnApplicationEnteredBackgroundDelegate OnApplicationEnteredBackgroundDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnApplicationEnteredForegroundDelegate OnApplicationEnteredForegroundDelegate;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LastJoinSessionError;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ActorsToDestroy;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateUnlockDifficulty DelegateOnUnlockDifficulty;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FString, FString> SanitizedNames;
    
public:
    UAGameInstance();

    UFUNCTION(BlueprintCallable)
    void VerifyAchievementsValidity();
    
    UFUNCTION(BlueprintCallable)
    bool UpgradeCompendiumEntry(const FName& Name, ECompendiumCategoryWithLevel InCategory);
    
    UFUNCTION(BlueprintCallable)
    void UpgradeCompendiumCategoryVersion(ECompendiumCategory InCategory);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateWrenchAmount(int32 AddAmount, const FString& Context);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateQuestLevel(EQuestLevel QuestLevel);
    
private:
    UFUNCTION(BlueprintCallable)
    void UpdateFriendlist();
    
public:
    UFUNCTION(BlueprintCallable)
    void UpdateFPSLimit();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateAchievementStat(FName StatName, int32 StatValue, bool bIncremental, bool bDelaySendDatas);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UnlockSecretRuins(uint8 ID);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UnlockPlayerClass(const FName& className);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UnlockPermanentReward(EPermanentReward InPermanentReward);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool UnlockDifficulty(const FName& DifficultyToUnlock);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UnlockArtefact(const FName& ArtefactRowName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool UnlockAchievementLocally(const FName& AchievementName);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UnlockAchievement(FName AchievementName);
    
    UFUNCTION(BlueprintCallable)
    void UnlinkLocalUserAccount();
    
    UFUNCTION(BlueprintCallable)
    bool TryToSaveRun();
    
    UFUNCTION(BlueprintCallable)
    void TryForceViewportActivated();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TriggerSaveProfile(const FString& Context, bool bSendAchievementStats);
    
    UFUNCTION(BlueprintCallable)
    void StopTimer(const FString& Context);
    
private:
    UFUNCTION(BlueprintCallable)
    void StopFriendListPulling();
    
public:
    UFUNCTION(BlueprintCallable)
    void StartTimer(const FString& Context);
    
private:
    UFUNCTION(BlueprintCallable)
    void StartFriendlistPulling();
    
public:
    UFUNCTION(BlueprintCallable)
    void StartBlockedPlayersPulling();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool ShowOnomatopoeia();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool ShowHitMarker();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool ShowFpsCounter();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool ShowFloatingText();
    
protected:
    UFUNCTION(BlueprintCallable)
    bool ShouldSendStats(const FName& StatName, int32 NewValue, ERankStatAchievement& OutNewRank, int32 OldValue, bool bDelaySendDatas);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTutorialWrenchValidate();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTutorialWeaponSortingValidate();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTutorialSunglassesValidate();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTutorialInfiniteRunValidate();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTutorialGadgetValidate();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTutorialDifficultyValidate();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTutorialCrystalValidate();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTutorialCompleted();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTutorialClassValidate();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPlayerClass(const FName& className);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPendingDifficulties(const TArray<FName>& AllDifficultiesToUnlock);
    
    UFUNCTION(BlueprintCallable)
    void SetNewLastCompendiumCategoryVersion(ECompendiumCategory InCategory);
    
    UFUNCTION(BlueprintCallable)
    void SetGamePaused(bool bPause, const FString& Context);
    
    UFUNCTION(BlueprintCallable)
    void SetFriendlistUpdateInterval_Medium();
    
    UFUNCTION(BlueprintCallable)
    void SetFriendlistUpdateInterval_Low();
    
    UFUNCTION(BlueprintCallable)
    void SetFriendlistUpdateInterval_High();
    
    UFUNCTION(BlueprintCallable)
    void SetFriendlistUpdateInterval(float NewUpdateInterval);
    
    UFUNCTION(BlueprintCallable)
    void SetEOSGlobalConfig(const FPerPlatformEOSConfig& PerPlatformConfigs);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetCurrentDifficulty(const FName& DifficultyName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetCompletionOfDifficulty(const FName& DifficultyRowName, float CompletionTime, ERank rank, bool& OutBestRank, bool& OutBestRunTime);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetCheatCodes(const TMap<ECheatCode, bool>& NewCheatCodes);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetBossesEncounteredID(const TArray<uint8>& NewValues);
    
    UFUNCTION(BlueprintCallable)
    void SetBlockedUser(const FPlayerBlockList& PlayerBlockList);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetBazarBlueprintUnlocked(const TMap<FName, int32>& NewBazarBlueprintUnlocked);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetActivateCrystal(const FName& LevelName, bool bActivate);
    
    UFUNCTION(BlueprintCallable)
    void SetAchievementAsUnlockedForOss(const TArray<FName>& OssNames, const FName& AchievementName);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SendAchievementStats();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SaveTutorialSuggestedDifficulty(const FName& DifficultyRow);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SaveRun();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SaveAlreadyPlayedMaxTexts(const TArray<FName>& AlreadyPlayedTexts);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ResetUnlockedArtefacts();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ResetStoryUnlocked();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ResetSecretRuins();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ResetQuestlevel();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ResetCurrentArtefacts();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ResetBazarBlueprintUnlocked();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ResetAlreadyPlayedMaxTexts();
    
    UFUNCTION(BlueprintCallable)
    void ResetAllCompendiumCategoriesVersion();
    
    UFUNCTION(BlueprintCallable)
    void RemoveUserFromBlockList(const FString& UserIdString);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RemoveFavoriteWeaponRow(FName WeaponRowName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RemoveExcludeWeaponRow(FName WeaponRowName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RemoveCurrentArtefact(const FName& RowName);
    
    UFUNCTION(BlueprintCallable)
    void RejectInboundInvite(const FString& friendId);
    
    UFUNCTION(BlueprintCallable)
    void ReinitializeCompendium();
    
    UFUNCTION(BlueprintCallable)
    void RegisterActorForDestroy(AActor* ActorToRegister);
    
    UFUNCTION(BlueprintCallable)
    void PrintSaveProfile();
    
    UFUNCTION(BlueprintCallable)
    void OnLootCompendiumCard(const FName& Name, ECompendiumCategoryWithLevel InCategory);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintWorldChanged(bool bIsLeavingAnExistingWorld);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSteamOverlayActivated(bool bIsActivated);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintReceivedFocus();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintLostFocus();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintJoinedSessionIsFull();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintDeactivateViewport();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintControllerConnectionChange(bool bIsConnection, int32 ControllerId);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintActivateViewport();
    
    UFUNCTION(BlueprintCallable)
    void LoadCompendiumData(const FString& JsonString);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool IsTutorialValidated();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsStoryUnlocked(const FName& RowName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool IsRotateMiniMapEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool IsRotateMapEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool IsPlayerClassUnlocked(const FName& className);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool IsPendingDifficultyToUnlock(FName RowName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPendingDestroy(AActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLastRunVictorious() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool IsLastFailedLevel(const FName& LevelRowName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool IsInfiniteMusic();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool IsGamepadHapticEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool IsGamepadAdaptiveTriggerEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool IsFavoriteWeaponRow(FName WeaponRowName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool IsExcludeWeaponRow(FName WeaponRowName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEOSUserBlocked(const FString& EOSUserIdString) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool IsDynamicCrosshair();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool IsDifficultyUnlocked(const FName& DifficultyName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool IsCurrentArtefact(const FName& RowName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool IsCrossnetworkEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCompendiumEntryUpgraded(const FName& Name, ECompendiumCategoryWithLevel InCategory);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCompendiumCategoryModified(ECompendiumCategory InCategory);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool IsArtefactUnlocked(const FName& ArtefactRowName);
    
    UFUNCTION(BlueprintCallable)
    bool IsAchievementUnlockForAllOss(const TArray<FName>& OssNames, const FName& AchievementName);
    
    UFUNCTION(BlueprintCallable)
    bool IsAchievementUnlock(const FName& OSSName, const FName& AchievementName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void InvalidateRunSaved(bool bCancelActivity);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void InitAchievements();
    
    UFUNCTION(BlueprintCallable)
    void IncreaseCompendiumWeaponCompletion(const FName& Name, int32 Multiplier);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool HaveValidateWrenchTutorial();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool HaveValidateWeaponSortingTutorial();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool HaveValidateSunglassesTutorial();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool HaveValidateInfiniteRunTutorial();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool HaveValidateGadgetTutorial();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool HaveValidateDifficultyTutorial();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool HaveValidateCrystalTutorial();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool HaveValidateClassTutorial();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HaveUnlockAllStoriesOfLevel(const FName& LevelRowName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HaveUnlockAllArtefactsInLG();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool HaveRunSaved();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HaveFoundAllCrystals();
    
    UFUNCTION(BlueprintCallable)
    bool HaveAnyCompendiumEntryUpgradedOfCategoryWithExcludeRowNames(ECompendiumCategoryWithLevel InCategory, TArray<FName> ExcludeRowNames);
    
    UFUNCTION(BlueprintCallable)
    bool HaveAnyCompendiumEntryUpgradedOfCategory(ECompendiumCategoryWithLevel InCategory);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool HasVSyncEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool HasPermanentReward(EPermanentReward PermanentReward);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GlobalConfig_CanCrossPlay() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    int32 GetWrenchAmount();
    
    UFUNCTION(BlueprintCallable)
    void GetWeaponCompletion(const FName& Name, int32& OutCurrentCompletion, int32& OutMaxCompletion, float& OutPercent);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    TSet<FName> GetUnlockedPlayerClasses();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    TSet<FName> GetUnlockedDifficulties();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    FName GetTutorialSuggestedDifficulty();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetStoryUnlockedAmount();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    ESprintMode GetSprintMode();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    uint8 GetSecretRuinsBitMask();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    EScopeMode GetScopeMode();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetSanitizedName(const FString& NameToSanitize, FString& OutSanitizedName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRunRecapTotalDamageDealt() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<FName, ERank> GetRunRecapRankByLevels() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    ESettingsQualityWithOff GetRagdollQualitySettings();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    TMap<EQuestLevel, int32> GetQuestLevels();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    int32 GetQuestlevel(EQuestLevel QuestLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    FPlayerRunSaveGame GetPlayerSavedRunData();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    int32 GetPlayerClassUnlockedAmount();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    FName GetPlayerClass();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FPlayerBlockList GetPlayerBlocklist() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    TSet<EPermanentReward> GetPermanentRewards();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    TArray<FName> GetPendingDifficulties();
    
    UFUNCTION(BlueprintCallable)
    TArray<FName> GetNonUpgdradedDataNamesByCategory(ECompendiumCategoryWithLevel InCategory);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    float GetMusicVolume();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    float GetMouseVerticalSpeed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    float GetMouseSensitivity();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    float GetMouseHorizontalSpeed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    bool GetMetaRewardUnlocked(const FName& RowName, TArray<int32>& OutEntryLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    TMap<FName, FMetaRewardSaved> GetMetaRewardsSaved();
    
    UFUNCTION(BlueprintCallable)
    TArray<FName> GetMetaRewards();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    float GetMasterVolume();
    
    UFUNCTION(BlueprintCallable)
    FString GetLogLines();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAPlayerController* GetLocalPlayerController() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    FString GetLocalizationString();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetLinkedAchievementNameByStatName(const FName& StatName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetLastRunRecap(FRunRecap& OutLastRunRecap) const;
    
    UFUNCTION(BlueprintPure)
    int64 GetKillAmountOfCurrentRun() const;
    
    UFUNCTION(BlueprintPure)
    int64 GetKillAmount() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    void GetKeyBindings(const FName& ActionName, FKey& KeyboardKey, FKey& SecondaryKeyboardKey, FKey& GamepadKey, FKey& SecondaryGamepadKey);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    float GetInterfaceVolume();
    
    UFUNCTION(BlueprintCallable)
    TArray<uint8> GetInitialBossEncounteredID(const TArray<TSoftClassPtr<ACharacter_Enemy>>& FirstExpectedEncounteredBosses);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FCompendiumHistory GetHistoryDatas();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    FGeneratorRunSaveGame GetGeneratorSavedRunData();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetGDKConnectionStatus() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    TSet<FName> GetGameTips();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAGameState* GetGameStateRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    float GetGamepadVerticalSensitivity();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    float GetGamepadHorizontalSensitivity();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    int32 GetFPSLimit();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    int32 GetFOV();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetFavoriteEntry(const TMap<FName, int32>& Entries) const;
    
    UFUNCTION(BlueprintCallable)
    FString GetFavoriteBrobot();
    
    UFUNCTION(BlueprintCallable)
    int32 GetEnemyAmountToUpgradeWeapon();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GetCurrentResolution(int32& OutX, int32& OutY, FString& OutResolutionAsString);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    FName GetCurrentDifficulty();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    TSet<FName> GetCurrentArtefacts();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FCrystalFound> GetCrystalsFoundForLocalData();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    TMap<FName, bool> GetCrystalsFound();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    ECrouchMode GetCrouchMode();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    ECrosshairMode GetCrosshairType();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    float GetCrosshairOpacity();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    ECrosshairColor GetCrosshairColor();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    EController GetControllerType();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    FDifficultyCompletion GetCompletionOfDifficulty(const FName& DifficultyRowName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    TMap<FName, FDifficultyCompletion> GetCompletionByDifficulty();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetCompendiumDataStringFromStruct();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    TMap<ECheatCode, bool> GetCheatCodes();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetBrobotNameByID(const FString& PlayerId);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    TArray<uint8> GetBossesEncounteredID();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<uint8> GetBlockedUsersDataForWrite() const;
    
    UFUNCTION(BlueprintCallable)
    FIntPoint GetBestFullscreenResolution();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    TMap<FName, int32> GetBazarBlueprintUnlocked();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    void GetAxisBindings(const FName& ActionName, FKey& PositiveAxisKeyboardKey, FKey& PositiveAxisSecondaryKeyboardKey, FKey& PositiveAxisGamepadKey, FKey& PositiveAxisSecondaryGamepadKey, FKey& NegativeAxisKeyboardKey, FKey& NegativeAxisSecondaryKeyboardKey, FKey& NegativeAxisGamepadKey, FKey& NegativeAxisSecondaryGamepadKey);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    EAutoReloadMode GetAutoReloadMode();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    int32 GetArtefactUnlockedAmount();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    TSet<FName> GetArtefactUnlocked();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    TArray<FName> GetAlreadyPlayedMaxTexts();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetAllCompendiumEntriesByCat(ECompendiumCategory InCategory);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    TArray<FName> GetAllAchievementsUnlocked();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    TMap<FName, int32> GetAllAchievementsStats();
    
    UFUNCTION(BlueprintCallable)
    FPlayerRunSaveGame GeneratePlayerSaveRunData();
    
    UFUNCTION(BlueprintCallable)
    FGeneratorRunSaveGame GenerateGeneratorSaveRunData();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool DoesPerkExistInCompendium(const FName& PerkName, const EPerkCompendiumCategory Category);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool DoesEntryExistInCompendium(const FName& Name, ECompendiumCategory InCategory);
    
    UFUNCTION(BlueprintCallable)
    void DebugRecap(const FRunRecap& Recap);
    
    UFUNCTION(BlueprintCallable)
    void DebugHistory();
    
    UFUNCTION(BlueprintCallable)
    void DebugCompendium();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CreateSaveFiles();
    
    UFUNCTION(BlueprintCallable)
    void ConsumeInboundInvite(const FString& friendId);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ClearPermanentRewards();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ClearGameTips();
    
    UFUNCTION(BlueprintCallable)
    void CheckLastJoinSessionError();
    
    UFUNCTION(BlueprintCallable)
    void CheatCodeTestAchievement();
    
    UFUNCTION(BlueprintCallable)
    void CancelAllOutboundInvites();
    
    UFUNCTION(BlueprintCallable)
    void CallGDKConnectionStatusChanged_DEBUG();
    
    UFUNCTION(BlueprintCallable)
    void BlockInboundInvite(const FString& friendId);
    
    UFUNCTION(BlueprintCallable)
    bool AddUserToBlockList(const AAPlayerState* PlayerState, FBlockedPlayer& OutBlockedPlayer);
    
    UFUNCTION(BlueprintCallable)
    void AddSanitizedName(const FString& NameToSanitize, const FString& SanitizedName);
    
    UFUNCTION(BlueprintCallable)
    bool AddPerkEntryToCompendium(const FName& Name, EPerkCompendiumCategory InPerkCategory);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AddKeyBinding(const FName& ActionName, const FKey& KeyboardKey, const FKey& SecondaryKeyboardKey, const FKey& GamepadKey, const FKey& SecondaryGamepadKey);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AddGameTip(const FName& GameTip);
    
    UFUNCTION(BlueprintCallable)
    uint8 AddFlagToBitmask(uint8 NewFlag, uint8 Bitmask);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AddFavoriteWeaponRow(FName WeaponRowName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AddExcludeWeaponRow(FName WeaponRowName);
    
    UFUNCTION(BlueprintCallable)
    bool AddEntryToCompendium(const FName& Name, ECompendiumCategory InCategory);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AddCurrentArtefact(const FName& RowName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AddCrystalFound(const FName& LevelName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AddAxisBinding(const FName& ActionName, const FKey& PositiveAxisKeyboardKey, const FKey& PositiveAxisSecondaryKeyboardKey, const FKey& PositiveAxisGamepadKey, const FKey& PositiveAxisSecondaryGamepadKey, const FKey& NegativeAxisKeyboardKey, const FKey& NegativeAxisSecondaryKeyboardKey, const FKey& NegativeAxisGamepadKey, const FKey& NegativeAxisSecondaryGamepadKey);
    
};

