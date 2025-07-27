#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=PrimaryAssetId -FallbackName=PrimaryAssetId
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
#include "GameFramework/GameStateBase.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
//CROSS-MODULE INCLUDE V2: -ModuleName=PhysicsCore -ObjectName=EPhysicalSurface -FallbackName=EPhysicalSurface
#include "CrystalDataWithRowName.h"
#include "CrystalRow.h"
#include "DecalComponentPool.h"
#include "DecalComponentPoolData.h"
#include "DelegateCheatCodeDelegate.h"
#include "DelegateOnGrantPickupDelegate.h"
#include "DelegateSetNewDifficultyDelegate.h"
#include "DifficultyRow.h"
#include "ECheatCode.h"
#include "ECorruptedLevelType.h"
#include "EGambleWeaponType.h"
#include "EItemRarity.h"
#include "ELocomotionType.h"
#include "EMultiplayerLoot.h"
#include "ENetworkMode.h"
#include "EPermanentReward.h"
#include "EPickup.h"
#include "ERandomSeedID.h"
#include "ERank.h"
#include "EStat.h"
#include "EStatus.h"
#include "ETeam.h"
#include "EXPSource.h"
#include "EndLevelData.h"
#include "EnemyRow.h"
#include "GameTip.h"
#include "HitSurface.h"
#include "IStatManager.h"
#include "Item.h"
#include "ItemPool.h"
#include "LevelGeneratorMutatorRow.h"
#include "LevelInitData.h"
#include "LevelRow.h"
#include "LocalPlayerData.h"
#include "LocomotionSurface.h"
#include "MetaRewardBoard.h"
#include "OverrideStarsByPCPercent.h"
#include "RankIcon.h"
#include "Request_GameLevel.h"
#include "Request_InfiniteGameLevel.h"
#include "StatValues.h"
#include "StoryCapsule.h"
#include "StoryCapsuleDataWithRowName.h"
#include "SurfaceSoundAndFx.h"
#include "Templates/SubclassOf.h"
#include "WeaponRow.h"
#include "AGameState.generated.h"

class AACharacter;
class AADoor;
class AAGrapplePoint;
class AAInteractiveBasecamp;
class AAInteractiveCard;
class AAInteractiveItem;
class AAInteractiveWeapon;
class AAJumpad;
class AALevelGenerator;
class AAMax;
class AAMaxSlot;
class AAPickup;
class AAPlayerController;
class AAProjectile;
class AAShootingRangeButton;
class AAShootingRangeLight;
class AAShootingRangeScreen;
class AATarget;
class AAWeapon;
class AActor;
class ACharacter_Enemy;
class ACharacter_Player;
class AController;
class UAStatManager;
class UAudioComponent;
class UCurveFloat;
class UDataTable;
class UMaterialParameterCollection;
class UParticleSystem;
class USoundCue;
class UTexture2D;

UCLASS(Blueprintable)
class ROBOQUEST_API AAGameState : public AGameStateBase, public IIStatManager {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateGameTime, float, GameTime);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNetworkModeChanged, ENetworkMode, NetworkMode);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameTimePaused, bool, bNewPaused);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateTargetRegistered, AATarget*, Target, bool, bIsRegister);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateTargetDeath, int32, TargetIndex, AATarget*, TargetRef);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateStartTravelling);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateShootingRangeChallengeStarted, int32, Index, bool, bIsStart);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateShootingRangeChallengeDuration, int32, Index, float, Duration);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateReceptServerScore, int32, Index, int32, ServerScore);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnUpdateBazarItemCostReduction, int32, NewCostReduction);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnTriggerLevelUp, int32, Level);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnSynchronizeLevelExperience);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnRemoveItemRow, FName, ItemRow);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnPlayerResurect, ACharacter_Player*, ResurectedPlayer);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnPlayerDisconnected, ACharacter_Player*, ExitingPlayer);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnPlayerDeath, ACharacter_Player*, DeathPlayer);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDelegateOnNewPlayerConnected, ACharacter_Player*, NewPlayer, const FName&, Name, const FString&, NameSuffix);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnMutatorTimeLimitationElapsed, float, SyncDelayInMs);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnLocalPlayerInitializedInBasecamp);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnLevelUp, int32, Level);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnLevelGenerationChanged, bool, bIsGenerating);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnInteractWithEndLevel);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnGrantExperience, float, Amount, EXPSource, Source);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnGameStateInitialized);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnGameStateDataAssetLoaded);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnEnterBossSafeZone);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnEnemyEndInitialization, ACharacter_Enemy*, Enemy);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnEndLevel);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnDoorCrossByAllPlayers, const FVector&, DoorLocation, const FVector&, ForwardVector);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnCorruptedLevelTimeElapsed);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateAttackingEnemies, int32, Amount);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPrimaryAssetId GameStateDataAssetID;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_Loot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_AIAttacks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_PlayerSkills;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_ModSkills;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_EnemySkill;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_AllySkill;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnGameStateInitialized DelegateOnGameStateInitialized;
    
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnNetworkModeChanged OnNetworkModeChangedDelegate;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsTravelling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAStatManager* StatManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGameStateGenerator;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnNewPlayerConnected DelegateOnNewPlayerConnected;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateStartTravelling DelegateStartTravelling;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<ACharacter_Player*, FLocalPlayerData> PlayersLocalData;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAInteractiveWeapon*> PendingInitialWeapons;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnLocalPlayerInitializedInBasecamp DelegateOnLocalPlayerInitializedInBasecamp;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnPlayerDisconnected DelegateOnPlayerDisconnected;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnDoorCrossByAllPlayers DelegateOnDoorCrossedByAllPlayers;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AALevelGenerator* LevelGeneratorRef;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRequest_GameLevel> PreviousLevels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRequest_InfiniteGameLevel> PreviousInfiniteLevels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LastLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName GameLevel;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FName> SpawnableMerchants;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AADoor*> OneWayDoorsOfLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_Levels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ReplicatedActorsPendingRegistration;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MarkRatioMultiplier;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_Enemy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_Ally;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_EnemyDeath;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnEnemyEndInitialization DelegateOnEnemyEndInitialization;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 EliteLootTicketLuckModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHitFeedbackDisabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ACharacter_Enemy*> AttackingEnemies;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* ShootingRangeLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AATarget*> RegisteredTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAShootingRangeScreen*> ShootingRangeScreens;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAShootingRangeLight*> ShootingRangeLights;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FVector, AAShootingRangeButton*> RegisteredShootingRangeButton;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateTargetRegistered DelegateTargetRegistered;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateShootingRangeChallengeStarted DelegateShootingRangeChallengeStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateShootingRangeChallengeDuration DelegateShootingRangeChallengeDuration;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateReceptServerScore DelegateReceptServerScore;
    
private:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AAPickup> PickupClasses[11];
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AAPickup> PickupClassesLoaded[11];
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 PickupPoolAmount[11];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float MultiplayerTimePickupValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveHealthPickup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDisableWeaponPickupLoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 WeaponPickupLootValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 MultiplayerWeaponPickupLootValue;
    
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    float PickupLifetimeModifier[11];
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnGrantPickup DelegateOnGrantPickup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PickupRangeRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthPickupValueModifier;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnLevelUp DelegateOnLevelUp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PlayerLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_Weapons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AAInteractiveWeapon> InteractiveWeaponClassPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AAInteractiveWeapon> InteractiveWeaponClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WeaponPickupValueModifier;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_Crystals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_Items;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_BazarItems;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemPool ItemRowNames[5];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemPool ItemRowPool[5];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FName> ExcludedItemRowsFromChest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, int32> ItemQuantity;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BazarItemCostReduction;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnUpdateBazarItemCostReduction DelegateOnUpdateBazarItemCostReduction;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnRemoveItemRow DelegateOnRemoveItemRow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AAInteractiveItem> InteractiveItemClassPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AAInteractiveItem> InteractiveItemClass;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_HitSurface;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_LocomotionSurface;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnUpdateGameTime OnUpdateGameTime;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameTimePaused OnGameTimePaused;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GameTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GameTimeOnLevelStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TotalRunTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGameTimePaused;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FEndLevelData LastLevelData;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnEnterBossSafeZone DelegateOnEnterBossSafeZone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ECheatCode, bool> CheatCodes;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateCheatCode DelegateCheatCode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AAInteractiveCard> WeaponCardClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AAInteractiveCard> EnemyCardClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAInteractiveCard*> WeaponCards;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAInteractiveCard*> EnemyCards;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> PinggableActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D PlayerProjectilePoolBase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAProjectile*> PlayerProjectiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CustomProjectileMaxPoolSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<AAProjectile>, int32> OverrideMaxPoolSizeForClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProjectileDestroyLifeSpan;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAProjectile*> CustomProjectileStored;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<AAProjectile>, int32> CustomProjectilesPoolSize;
    
private:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDecalComponentPool NewDecalPooling[3];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDecalComponentPoolData DecalComponentPoolDatas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_MetaRewardBoard;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_GameTips;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FGameTip> GameTips;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_Difficulty;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRepSetNewDifficulty, meta=(AllowPrivateAccess=true))
    FName DifficultyRow;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateSetNewDifficulty DelegateSetNewDifficulty;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_StoryCapsule;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRankIcon RankIcons[6];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FOverrideStarsByPCPercent> OverrideStarsByPCPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* BaseBasecampLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* CurrentBasecampLayerLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAInteractiveBasecamp*> InteractivesInBasecamp;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAudioComponent*> BasecampAudioComponents;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAJumpad*> Jumpads;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAGrapplePoint*> GrapplePoints;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<ACharacter_Enemy>> WorkerClasses;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FName> CurrentMaxTexts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AAMax> MaxClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAMaxSlot*> MaxSlotsInBasecamp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* MPC_Borealis;
    
public:
    
private:
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_LevelGeneratorMutator;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDeactivateHealbot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HealbotCost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CorruptedCellPercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxItemInChest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TrapAddDamagePercent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTimeLimitationMutator;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnMutatorTimeLimitationElapsed DelegateOnMutatorTimeLimitationElapsed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ACharacter_Enemy> BattleWorkerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BattleWorkerAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BattleWorkerSpawnDelay;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FVector, float> MutatorExplosions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* MutatorEnemyExplosionPreshotSoundLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundCue* MutatorEnemyExplosionTriggerSoundLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystem* MutatorEnemyExplosionFXLoaded;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundCue> MutatorEnemyExplosionPreshotSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USoundCue> MutatorEnemyExplosionTriggerSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UParticleSystem> MutatorEnemyExplosionFX;
    
    AAGameState(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void UnregisterPinggableActor(AActor* ActorRef);
    
    UFUNCTION(BlueprintCallable)
    void UnregisterJumpad(AAJumpad* Jumpad);
    
    UFUNCTION(BlueprintCallable)
    void UnregisterGrapplePoint(AAGrapplePoint* Jumpad);
    
    UFUNCTION(BlueprintCallable)
    void UnregisterCharacter(ETeam Team, AACharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    void UnlockPendingDifficulties();
    
    UFUNCTION(BlueprintCallable)
    void TriggerBorealisPhase2();
    
private:
    UFUNCTION(BlueprintCallable)
    void StopTimeLimitationDamageTimer();
    
    UFUNCTION(BlueprintCallable)
    void StopCheckingElapsedTime();
    
    UFUNCTION(BlueprintCallable)
    void StartTimeLimitationDamageTimer(float SyncDelayInMs);
    
    UFUNCTION(BlueprintCallable)
    void StartTimeLimitationDamageLoopTimer();
    
public:
    UFUNCTION(BlueprintCallable)
    void StartMutatorEnemyExplosion(const FVector& Location);
    
    UFUNCTION(BlueprintCallable)
    AAInteractiveItem* SpawnPickupItem(const FVector& Location, const FRotator& Rotation, const FName& ItemRowName, bool bStartDeactivate, bool bSnapToGround);
    
    UFUNCTION(BlueprintCallable)
    void SpawnLocomotionVFXSurface(const FSurfaceSoundAndFx& FxAndSound, ELocomotionType LocomotionType, const FHitResult& HitResult, float OverrideDecalSize, float OverrideSoundVolume);
    
    UFUNCTION(BlueprintCallable)
    AALevelGenerator* SpawnLevelGenerator(TSubclassOf<AALevelGenerator> LevelGeneratorClass);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldPlayCinematic(FName RowName) const;
    
    UFUNCTION(BlueprintCallable)
    void SetNewDifficulty(const FName& NewDifficulty);
    
    UFUNCTION(BlueprintCallable)
    void SetGameTimePaused(bool bIsPaused);
    
    UFUNCTION(BlueprintCallable)
    void SetGameLevelName(const FName& LevelName);
    
    UFUNCTION(BlueprintCallable)
    void SetCheatCodeStatus(ECheatCode CheatCode, bool bIsActive);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SaveCheatCodes();
    
    UFUNCTION(BlueprintCallable)
    void RegisterReplicatedActor(AActor* ReplicatedActor);
    
    UFUNCTION(BlueprintCallable)
    void RegisterPinggableActor(AActor* ActorRef);
    
    UFUNCTION(BlueprintCallable)
    void RegisterJumpad(AAJumpad* Jumpad);
    
    UFUNCTION(BlueprintCallable)
    void RegisterGrapplePoint(AAGrapplePoint* Jumpad);
    
    UFUNCTION(BlueprintCallable)
    void RegisterCharacter(ETeam Team, AACharacter* Character);
    
    UFUNCTION(BlueprintCallable)
    void OnStartShootingRangeChallenge(int32 Index, float InDuration);
    
    UFUNCTION(BlueprintCallable)
    void OnStartLevel();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSplineDestroyed(AActor* Spline);
    
    UFUNCTION(BlueprintCallable)
    void OnShootingRangeLayerLoaded(TSoftClassPtr<AActor> ShootingRangeLayerPtr);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnRepSetNewDifficulty();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnReplicatedActorDestroyed(AActor* DestroyedActor);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnRemoveItemRow(const FName& ItemRow);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnPlayerDisconnectedBeforeBeingInitialized(AController* ExitingPlayer);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnPlayerDeath(ACharacter_Player* PlayerRef, bool bForceGameOver);
    
    UFUNCTION(BlueprintCallable)
    void OnOneWayDoorDestroyed(AActor* Actor);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnMutatorEnemyExplosionTriggerSoundLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnMutatorEnemyExplosionPreshotSoundLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnMutatorEnemyExplosionFXLoaded();
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastUnloadPreviousLevel();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastSetNewDifficulty(const FName& NewDifficulty);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastSendShootingRangeChallengeScore(int32 Index, int32 Score);
    
private:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void OnMulticastLevelUp(float Reliquat, EXPSource Source);
    
    UFUNCTION(BlueprintCallable)
    void OnMaxClassLoaded(TSoftClassPtr<AAMax> MaxClassPtr);
    
    UFUNCTION(BlueprintCallable)
    void OnLevelUp(float Reliquat, EXPSource Source);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnGrantExperience(float Amount, EXPSource Source);
    
    UFUNCTION(BlueprintCallable)
    void OnEndShootingRangeChallenge(int32 Index);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintLevelGenerationEnd();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintInitLocalData(ACharacter_Player* Player, FLocalPlayerData Data);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    FGameTip OnBlueprintGetRandomGameTip();
    
    UFUNCTION(BlueprintCallable)
    void OnBasecampLayerLevelLoaded(TSoftClassPtr<AActor> BasecampLayerLevelPtr);
    
    UFUNCTION(BlueprintCallable)
    void OnBaseBasecampLayerLevelLoaded(TSoftClassPtr<AActor> BaseBasecampLayerPtr);
    
    UFUNCTION(BlueprintCallable)
    void NotifyStartTravelling();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSynchronizeLevelExperience(float ServerLevelExperience);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSetCheatCodeStatus(ECheatCode CheatCode, bool bIsActive);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSendServerFullArenaHealth(const TArray<float>& ServerArenaHealth);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSendLocalData(ACharacter_Player* Player, const FLocalPlayerData& Data);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSendLevelMaxTextsOnly(const TArray<FName>& MaxTexts);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSendLevelInitData(const FLevelInitData& LevelInitData);
    
private:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastOnMutatorTimeLimitationElapsed();
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastOnCorruptedLevelTimeElapsed();
    
    UFUNCTION(BlueprintCallable)
    void LootWeaponPickup(ACharacter_Enemy* EnemyRef);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTitleMap() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTestMap() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsShootingRangeChallengeStarted(int32 Index);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRegisteredCharacter(ETeam Team, AACharacter* Character) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRaceCorruptedLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMultiPlayerGame() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocalPlayerInitializedInBasecamp() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLevelGeneratorMap() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLavaCorruptedLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLastLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLastFailedLevel();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInLevelGeneratorMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInfiniteRunMap() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInfiniteRun() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsGameStateInitialized() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsGameAlreadyOver() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCrystalActive(const FName& CrystalRowName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCrossplayMultiPlayerGame() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCorruptedLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBasecampMap() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAnInteractiveWeapon(const AActor* ReplicatedActor) const;
    
    UFUNCTION(BlueprintCallable)
    void InitMutatorEnemyExplosion(float Delay, float Range, float Damage);
    
    UFUNCTION(BlueprintCallable)
    void InitializeItemRows(UDataTable* DataTable, TArray<FName> ItemRows, bool bIgnoreLootable);
    
private:
    UFUNCTION(BlueprintCallable)
    void IncrementCurrentEnemyInitializationCount(ACharacter_Enemy* Enemy);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    TSubclassOf<ACharacter_Enemy> GetWorkerClass(bool bIsLooping) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetWeaponRowNamesForCompendium() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetWeaponRowNames() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetWeaponRowNameFromClass(TSubclassOf<AAWeapon> WeaponClass) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetWeaponRowFromClass(TSubclassOf<AAWeapon> WeaponClass, FWeaponRow& OutWeaponRow) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetWeaponRow(const FName& RowName, FWeaponRow& OutWeaponRow) const;
    
    UFUNCTION(BlueprintCallable)
    AAInteractiveWeapon* GetWeaponPickupFromPool();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTotalLevelExperience();
    
    UFUNCTION(BlueprintCallable)
    TArray<AATarget*> GetTargetsByIndex(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    AATarget* GetTargetByLocation(FVector Location);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FString> GetStoryUnlocked() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetStoryRowFromRowName(const FName& RowName, FStoryCapsule& OutStoryRow) const;
    
    UFUNCTION(BlueprintCallable)
    AAInteractiveWeapon* GetSpecificWeaponPickupFromPool(const FName& WeaponRowName, int32 WeaponLevel);
    
    UFUNCTION(BlueprintCallable)
    TArray<AAShootingRangeScreen*> GetShootingRangeScreenByIndex(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    TArray<AAShootingRangeLight*> GetShootingRangeLightByIndex(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    AAShootingRangeButton* GetShootingRangeButton(FVector ButtonLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetServerLocalData(FLocalPlayerData& OutData) const;
    
    UFUNCTION(BlueprintCallable)
    int32 GetSeededRandomRange(int32 Min, int32 Max, ERandomSeedID ID, const FString& Context, bool bSkippable);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRemainingCorruptedLevelTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AACharacter*> GetRegisteredCharacters(ETeam Team) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSoftObjectPtr<UTexture2D> GetRankIcon(ERank rank, bool bIsSmall) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ERank GetRankFromStarCount(uint8 Stars) const;
    
    UFUNCTION(BlueprintCallable)
    TArray<FName> GetRandomItemRowsFromRarityWithExcludedRows(int32 Amount, EItemRarity Rarity, TArray<FName> ExcludedRows, ERandomSeedID SeedID, bool bFromChest);
    
    UFUNCTION(BlueprintCallable)
    TArray<FName> GetRandomItemRowsFromRarity(int32 Amount, EItemRarity Rarity, ERandomSeedID SeedID, bool bFromChest);
    
    UFUNCTION(BlueprintCallable)
    TArray<FName> GetRandomItemRowsFromRarities(int32 Amount, TArray<EItemRarity> Rarities, ERandomSeedID SeedID, bool bFromChest);
    
    UFUNCTION(BlueprintCallable)
    TArray<FName> GetRandomItemRows(int32 Amount, ERandomSeedID SeedID, bool bFromChest);
    
    UFUNCTION(BlueprintCallable)
    FName GetRandomItemRowFromRarity(ERandomSeedID SeedID, EItemRarity Rarity, TArray<FName> ExcludedItemRows, bool bFromChest);
    
    UFUNCTION(BlueprintCallable)
    FName GetRandomItemRowFromRarities(ERandomSeedID SeedID, TArray<EItemRarity> Rarities, TArray<FName> ExcludedItemRows, bool bFromChest);
    
    UFUNCTION(BlueprintCallable)
    FName GetRandomItemRow(ERandomSeedID SeedID, TArray<FName> ExcludedItemRows, bool bFromChest);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPlayerSpawnTransform(uint8 PlayerId, FTransform& OutSpawnTransform) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ACharacter_Player*> GetPlayersFromLocalData() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACharacter_Player* GetPlayerRefByMultiLoot(EMultiplayerLoot MultiplayerLoot) const;
    
    UFUNCTION(BlueprintCallable)
    AActor* GetPinggableActorByLocation(FVector Location);
    
    UFUNCTION(BlueprintCallable)
    TArray<AAPickup*> GetPickupFromPool(EPickup Type, int32 Amount);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ENetworkMode GetNetworkMode() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetMutatorRow(const FName& RowName, FLevelGeneratorMutatorRow& OutMutatorRow) const;
    
    UFUNCTION(BlueprintCallable)
    TArray<FName> GetMissingWeaponCards();
    
    UFUNCTION(BlueprintCallable)
    TArray<FName> GetMissingEnemyCards();
    
    UFUNCTION(BlueprintCallable)
    int32 GetMetaRewardsUnlockedCostFromRowName(const FName& RowName);
    
    UFUNCTION(BlueprintCallable)
    int32 GetMetaRewardsUnlockedCost();
    
    UFUNCTION(BlueprintCallable)
    int32 GetMetaRewardsTotalCostFromRowName(const FName& RowName);
    
    UFUNCTION(BlueprintCallable)
    int32 GetMetaRewardsTotalCost();
    
    UFUNCTION(BlueprintCallable)
    TArray<FName> GetMetaRewardBoardRowNamesForBasecampLevel();
    
    UFUNCTION(BlueprintCallable)
    TArray<FName> GetMetaRewardBoardRowNames();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetMetaRewardBoardDataFromRowName(const FName& RowName, FMetaRewardBoard& OutMetaRewardBoardRow, bool bThrowError);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<AAMax> GetMaxClass() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACharacter_Player* GetLocalPlayerRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLocalPlayerPing() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAPlayerController* GetLocalPlayerControllerRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetLocalData(ACharacter_Player* Player, FLocalPlayerData& OutData) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetLevelStoryRowNames(const FName& LevelRowName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetLevelRow(const FName& RowName, FLevelRow& OutLevelRow) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AALevelGenerator* GetLevelGenerator() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLevelExperienceFromPath(const FName& LevelName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLevelExperienceBySource(EXPSource Source) const;
    
    UFUNCTION(BlueprintCallable)
    ERank GetLastRank(int32& OutXPStarCount, int32& OutTimeStarCount, bool& bOutHasXP);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLastLevelTotalExperience() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLastLevelDuration() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAJumpad* GetJumpadFromLocation(const FVector& WorldLocation) const;
    
    UFUNCTION(BlueprintCallable)
    bool GetItemRow(const FName& ItemRowName, FItem& OutItem, bool bIgnoreBazar);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<AAInteractiveWeapon> GetInteractiveWeaponClass() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<AAInteractiveItem> GetInteractiveItemClass() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetInitialDifficultyRows() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAGrapplePoint* GetGrapplePointFromLocation(const FVector& WorldLocation) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ERank GetGlobalRank() const;
    
    UFUNCTION(BlueprintCallable)
    AAInteractiveWeapon* GetGambleWeaponPickupFromPool(EMultiplayerLoot MultiplayerLoot, EGambleWeaponType WeaponType);
    
    UFUNCTION(BlueprintCallable)
    AAInteractiveWeapon* GetExtraWeaponPickupFromPool(EMultiplayerLoot MultiplayerLoot);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetEnemyRowNamesForCompendium() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetEnemyRowNames() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetEnemyRowFromClass(TSubclassOf<ACharacter_Enemy> EnemyClass, FEnemyRow& OutEnemyRow) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetEnemyRow(const FName& RowName, FEnemyRow& OutEnemyRow) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ACharacter_Enemy*> GetEnemiesByEncounter(uint8 EncounterID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetDifficultyDataFromRowName(const FName& RowName, FDifficultyRow& OutDifficultyRow) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetDifficultyData(FDifficultyRow& OutDifficultyRow) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetCurrentLevelName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentLevelDuration() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentEliteValueFromCrystals() const;
    
    UFUNCTION(BlueprintCallable)
    int32 GetCurrentBasecampLevel(float& OutPercentLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetCrystalFoundCountByLocalPlayer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCrystalDataFromRowName(const FName& RowName, FCrystalRow& OutLevelCrystalRow) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCrystalDataFromLevelName(const FName& LevelName, FCrystalRow& OutLevelCrystalRow) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCrystalCustomFloatProperty(const FName& RowName, const FName& FloatPropertyName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECorruptedLevelType GetCorruptedLevelType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCorruptedLevelTimeLimitation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AACharacter* GetClosestActivatedCharacterWithoutStatus(const FVector& BaseLocation, ETeam Team, TArray<TSoftClassPtr<AACharacter>> ExcludedClasses, EStatus Status, AACharacter* RequestInstigator) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AACharacter* GetClosestActivatedCharacterWithoutMultipleStatus(const FVector& BaseLocation, ETeam Team, TArray<TSoftClassPtr<AACharacter>> ExcludedClasses, TArray<EStatus> Status, AACharacter* RequestInstigator) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AACharacter* GetClosestActivatedCharacter(const FVector& BaseLocation, ETeam Team, TArray<TSoftClassPtr<AACharacter>> ExcludedClasses, AACharacter* RequestInstigator) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCheatCodeStatus(ECheatCode CheatCode);
    
    UFUNCTION(BlueprintCallable)
    AAInteractiveCard* GetCardFromPool(bool bWeaponCard, FName RowName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBossDuration() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetBasecampCompletion();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FStoryCapsuleDataWithRowName> GetAllStoryCapsulesDataOrdered() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ACharacter_Player*> GetAllPlayersOrdered() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<ACharacter_Player*> GetAllPlayers() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetAllMutatorRowNames() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<FName, FLevelRow> GetAllLevelRows() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetAllLevelRowNames() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetAllDifficultyRowNames() const;
    
    UFUNCTION(BlueprintCallable)
    TMap<FName, FDifficultyRow> GetAllDifficultiesUnlocked();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetAllDifficultiesToUnlock() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetAllCrystalRowNames() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FCrystalDataWithRowName> GetAllCrystalDataWithRowNames() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FCrystalDataWithRowName> GetAllCrystalDataOrdered() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FCrystalRow> GetAllCrystalData() const;
    
    UFUNCTION(BlueprintCallable)
    TArray<AATarget*> GetActivatedTargetsInRange(FVector BaseLocation, float Range, bool bSorted);
    
    UFUNCTION(BlueprintCallable)
    TArray<AATarget*> GetActivatedTargets();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AACharacter*> GetActivatedCharactersInRange(const FVector& BaseLocation, ETeam Team, float Range, bool bSorted) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AACharacter*> GetActivatedCharacters(ETeam Team) const;
    
    UFUNCTION(BlueprintCallable)
    void EnsureClientIsUnloadingPreviousLevel();
    
private:
    UFUNCTION(BlueprintCallable)
    void DelayedOnLevelUp();
    
public:
    UFUNCTION(BlueprintCallable)
    void DeactivateCharacter(ETeam Team, AACharacter* Character);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreAllCrystalsFound() const;
    
private:
    UFUNCTION(BlueprintCallable)
    void ApplyTimeLimitationDamageToAllPlayers();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AnyPlayerHasPermanentReward(EPermanentReward InPermanentReward) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AnyPlayerHasGambleGarryUnlocked() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AllPlayersHavePermanentReward(EPermanentReward InPermanentReward) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AllPlayersHaveFoundCrystal(const FName& LevelName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AllPlayersAreReadyToStartInfiniteGame() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AllPlayersAreReadyToStartGame() const;
    
    UFUNCTION(BlueprintCallable)
    void AddPickupLifetimeModifier(EPickup Type, float NewModifier);
    
    UFUNCTION(BlueprintCallable)
    void AddGameTip(const FName& RowName);
    
    UFUNCTION(BlueprintCallable)
    void AddCrystalFoundToAllPlayers();
    
    UFUNCTION(BlueprintCallable)
    void AddCardToPool(AAInteractiveCard* Card);
    
    UFUNCTION(BlueprintCallable)
    void AddBazarItemCostReduction(int32 NewReduction);
    
    UFUNCTION(BlueprintCallable)
    void ActivateTimeLimitationMutator(float DamagePercentAmount, float DamageFirerate);
    
    UFUNCTION(BlueprintCallable)
    void ActivateCharacter(ETeam Team, AACharacter* Character);
    

    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    bool RestoreStat(EStat enumStat, float Modifier) override PURE_VIRTUAL(RestoreStat, return false;);
    
    UFUNCTION(BlueprintCallable)
    bool ReduceStat(EStat enumStat, float Modifier) override PURE_VIRTUAL(ReduceStat, return false;);
    
    UFUNCTION()
    void OnNotifyStatFull(EStat enumStat) override PURE_VIRTUAL(OnNotifyStatFull,);
    
    UFUNCTION()
    void OnNotifyStatEmpty(EStat enumStat) override PURE_VIRTUAL(OnNotifyStatEmpty,);
    
    UFUNCTION()
    void OnNotifyStat(EStat enumStat, float curVal, float Value) override PURE_VIRTUAL(OnNotifyStat,);
    
    UFUNCTION(BlueprintCallable)
    void MinimiseStat(EStat enumStat) override PURE_VIRTUAL(MinimiseStat,);
    
    UFUNCTION(BlueprintCallable)
    void MaximiseStat(EStat enumStat) override PURE_VIRTUAL(MaximiseStat,);
    
    UFUNCTION(BlueprintCallable)
    bool HaveStat(EStat enumStat) const override PURE_VIRTUAL(HaveStat, return false;);
    
    UFUNCTION(BlueprintCallable)
    float GetStatValue(EStat enumStat) const override PURE_VIRTUAL(GetStatValue, return 0.0f;);
    
    UFUNCTION(BlueprintCallable)
    FStatValues GetStatStruct(EStat enumStat) const override PURE_VIRTUAL(GetStatStruct, return FStatValues{};);
    
    UFUNCTION(BlueprintCallable)
    UAStatManager* GetStatManager() const override PURE_VIRTUAL(GetStatManager, return NULL;);
    
    UFUNCTION(BlueprintCallable)
    float GetStatCurrentValue(EStat enumStat) const override PURE_VIRTUAL(GetStatCurrentValue, return 0.0f;);
    
    UFUNCTION(BlueprintCallable)
    float GetMoveStatValue(float InitialValue) const override PURE_VIRTUAL(GetMoveStatValue, return 0.0f;);
    
};

