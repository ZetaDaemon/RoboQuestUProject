#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=IntPoint -FallbackName=IntPoint
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=PrimaryAssetId -FallbackName=PrimaryAssetId
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "ActBoss.h"
#include "ActRow.h"
#include "AdditionalInfiniteRunEnemies.h"
#include "AdditionalInfiniteRunEnemiesPercentByEncounter.h"
#include "CorruptedLevelPath.h"
#include "DestructibleMirrored.h"
#include "ECorruptedLevelType.h"
#include "ECorruptedRaceDifficulty.h"
#include "ELoadingStep.h"
#include "EMaxTextType.h"
#include "EMutatorType.h"
#include "ERandomSeedID.h"
#include "ERank.h"
#include "ETileType.h"
#include "EnemyBoardRow.h"
#include "EnemyBoardRowHandle.h"
#include "FirstTimeMaxText.h"
#include "InfiniteAct.h"
#include "InfiniteActRowHandle.h"
#include "InfiniteBossRow.h"
#include "InfiniteBossRowHandle.h"
#include "InfiniteLayout.h"
#include "InfiniteLayoutArray.h"
#include "LevelGeneratorMutatorRow.h"
#include "LevelRow.h"
#include "LevelRowHandle.h"
#include "LoadedTileClass.h"
#include "LootRowHandle.h"
#include "MaxTextRowHandle.h"
#include "RQDamageInfo.h"
#include "ReplacementMeshLoaded.h"
#include "SidePath.h"
#include "SpecificWeaponInPool.h"
#include "StaticMeshMirrored.h"
#include "Templates/SubclassOf.h"
#include "TileLoot.h"
#include "WeaponRowHandle.h"
#include "ALevelGenerator.generated.h"

class AAArenaTile;
class AABossTile;
class AAGameState;
class AAHoleSpawner;
class AAInteractiveStory;
class AALightSelector;
class AAMoonBossTile;
class AAPlayerController;
class AASasTile;
class AAStartTile;
class AATile;
class AATrap;
class ACharacter_Enemy;
class AController;
class UALevelGeneratorMutator;
class UDataTable;
class ULevelSequence;
class UMaterialParameterCollection;
class USoundCue;
class UStaticMesh;
class UTexture2D;

UCLASS(Blueprintable)
class ROBOQUEST_API AALevelGenerator : public AActor {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateUnloadPreviousLevel);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateOnStoryCapsuleCountChanged, int32, UnlockedStoryCount, int32, TotalStoryCount);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDelegateOnNewMutatorApplied, const FName&, RowName, const FName&, ParentRowName, bool, bInit);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnLevelGenerationFinished, const FName&, LevelRowName);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnEndEnemyGeneration);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnCrystalCorruptedDoorOpened);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateCommonGeneratorDataAssetLoaded);
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FInfiniteActRowHandle> InfiniteRunActsPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> InfiniteRunSpecialTilesPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<float> InfiniteRunXPByLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FInfiniteBossRowHandle> InfiniteBossPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FTileLoot> InfiniteFirstStartTileLoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FTileLoot> InfiniteStartTileLoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FTileLoot> InfiniteBossTileLoot;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 InfiniteTicketByRank[6];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLootRowHandle InfiniteRunSmithingTedRow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FWeaponRowHandle> InfiniteRunSmithingTedSpecificWeapons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FWeaponRowHandle> InfiniteRunSmithingTedSpecificWeaponsMultiplayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FInfiniteAct> CurrentInfiniteRunActPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 InfiniteRunEnemyLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FName> PendingMutators;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FInfiniteBossRow> CurrentInfiniteRunBossPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FInfiniteBossRowHandle LastBossSelectedFromPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FInfiniteBossRow CurrentInfiniteBossRow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> InteriorInfiniteBossTileClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<ACharacter_Enemy>> InfiniteBossEnemyClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> InfiniteBossHoleSpawnerClass;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentInfiniteRunLevelAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrentInfiniteRunActAmount;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UALevelGeneratorMutator*> ActiveMutators;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FAdditionalInfiniteRunEnemiesPercentByEncounter> PercentAdditionalInfiniteRunEnemiesByEncounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FAdditionalInfiniteRunEnemies> AdditionalInfiniteRunEnemies;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AddEliteValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 AddBigValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TrapMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TicketModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bActivateTrap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeadbonkBubbleMutatorLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EyeProtectionMutatorLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TurretEmpowerMutatorLuck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnemyExplosionMutatorLuck;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnNewMutatorApplied DelegateOnNewMutatorApplied;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LastMutatorRowName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPrimaryAssetId CommonGeneratorDataAssetID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCommonGeneratorDataAssetInit;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TSoftClassPtr<AActor>, TSubclassOf<AActor>> RoofClassesLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TSoftClassPtr<ACharacter_Enemy>, TSubclassOf<ACharacter_Enemy>> EnemyClassesLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TSoftClassPtr<AActor>, TSubclassOf<AActor>> BorderClassesLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FReplacementMeshLoaded> ReplacementMeshesLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FActRow CurrentActRow;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FLevelRowHandle> LevelsPool;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FLoadedTileClass> LoadedTileClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AActor>> LoadedInteriorSpecialClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, FSpecificWeaponInPool> LoadedSpecificWeaponsInPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FName> CurrentLevelsPool;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelRow CurrentLevelRow;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateUnloadPreviousLevel DelegateUnloadPreviousLevel;
    
private:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FInfiniteLayoutArray LayoutPool[3];
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FInfiniteLayoutArray CurrentLayoutPool[3];
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName CurrentInfiniteLayoutRowName;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FInfiniteLayout CurrentInfiniteLayout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FString> SelectedInteriorSpecialClassesIDs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AATile*> GeneratedTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AATile*> PendingCleanUpTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAStartTile* StartTile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAArenaTile*> ArenaTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AASasTile*> SasTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* EndLevelBeam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> BorderActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_EnemyBoard;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ACharacter_Enemy> StartLayoutWorkerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FEnemyBoardRowHandle> EnemyBoardPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FName> CurrentEnemyBoardPool;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName EnemyBoardRowName;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FEnemyBoardRow EnemyBoardRow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<ACharacter_Enemy>, int32> EnemyCountByClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACharacter_Enemy> RegularWorkerSpawnClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACharacter_Enemy> LoopingWorkerSpawnClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<uint8> EnemyCountByEncounterID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<ACharacter_Enemy>, float> EnemyXPByClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ACharacter_Enemy*> BigEnemiesSpawned;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<ACharacter_Enemy>> EliteClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<ACharacter_Enemy>> CurrentEliteClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<ACharacter_Enemy>> CurrentBigSpawnClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AATile*> TileToSpawnBigEnemies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FLootRowHandle> MerchantsPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FLootRowHandle, float> SpecificMerchantsSpawnPercentChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FLootRowHandle> CurrentMerchantsPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_MaxTexts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FFirstTimeMaxText> FirstTimeTexts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FMaxTextRowHandle> LooseTextsPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FMaxTextRowHandle> RandomTextsPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FMaxTextRowHandle> RandomBossTextsPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FName> AlreadyPlayedTexts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AAInteractiveStory> InteractiveStoryClass;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnStoryCapsuleCountChanged DelegateOnStoryCapsuleCountChanged;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnLevelGenerationFinished DelegateOnLevelGenerationFinished;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ACharacter_Enemy> KeyBotClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLootRowHandle KeyBotLootRow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLootRowHandle ShovelLootRow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLootRowHandle SwordLootRow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OasisCorruptedDoorTimeLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NasaDoorTimeLimit;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLootRowHandle FieldsCorruptedPortalRow;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CorruptedRuinsArenaHealthPercentModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CorruptedRuinsArenaImpactPercentModifier;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> CorruptedQuarrySpecialTilesPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* MPC_Corrupted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLinearColor BaseCorruptedColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLinearColor WaveCorruptedColor;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnCrystalCorruptedDoorOpened DelegateOnCrystalCorruptedDoorOpened;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AATile> MoonBossTileClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AATile> MoonBossTileClassLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAMoonBossTile* MoonBossTile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ACharacter_Enemy> MoonBossClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACharacter_Enemy> MoonBossClassLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ACharacter_Enemy*> BossRefs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> BossLayerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* BossLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULevelSequence* BossSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AABossTile*> BossTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<ACharacter_Enemy>> SelectedBossClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<uint8> BossesEncounteredID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<uint8, int32> CountOfBossEncounteredByID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 NextBossID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UStaticMesh* StartingWorkerSplineMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UStaticMesh* EndingWorkerSplineMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UStaticMesh* BaseWorkerSplineMesh;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AATrap> TrapClasses[11];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FDestructibleMirrored> DestructiblesMirrored;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FStaticMeshMirrored> StaticMeshesMirrored;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAHoleSpawner*> OpenedHoleSpawners;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ClosedHoleSpawners;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> SpecialQuestIconOn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> SpecialQuestIconOff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAGameState* GameStateRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AALightSelector* LightSelectorRef;
    
public:
    AALevelGenerator(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UnlockEndActAchievement();
    
    UFUNCTION(BlueprintCallable)
    void ShowLoadingError(const FString& ErrorMsg);
    
    UFUNCTION(BlueprintCallable)
    void SendLoadingStep(ELoadingStep LoadingStep, bool bIsStarting, bool bIsLocal);
    
    UFUNCTION(BlueprintCallable)
    void RandomizeLevel();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnStorySpawnClassLoaded(TSoftClassPtr<AActor> SpawnClass, FTransform SpawnTransform, FName RowName);
    
    UFUNCTION(BlueprintCallable)
    void OnStartTileLootRegistered();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnPlayerDisconnectedDuringGeneration(AController* ExitingPlayer);
    
    UFUNCTION(BlueprintCallable)
    void OnMutatorLoaded(FLevelGeneratorMutatorRow MutatorRow, FName RowName, bool bInit, int32 Index);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnHoleSpawnerDestroyed(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void OnBossTakeDamage(const FRQDamageInfo& DamageInfo);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintPreFinishReplicatedActorsInit();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintPostFinishReplicatedActorsInit();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintLoadingStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintLoadingFinished();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintLoadAssets();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintLevelGenerationFinished();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintLevelDestructionFinished();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintAllAssetsAreLoaded();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnBigDeathDuringQuest(const FRQDamageInfo& DamageInfo);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTutoLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsStraightLineLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRaceCorruptedLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsNasaDoorStillOpened(float GameTime, bool bPrintLog) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLavaCorruptedLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLastLevelOfAct(const FName& NextLevelRowName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLastLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInfiniteRun() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFirstLevelOfRun() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEnemyGenerationFinished() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCorruptedLevelPath(const FName& LevelDestinationName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCorruptedLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActiveOrPendingMutator(const FName& RowName) const;
    
    UFUNCTION(BlueprintCallable)
    void IncrementUnlockedStoryCapsuleCount();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<ACharacter_Enemy> GetWorkerClass(bool bIsLooping) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetWeaponLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetWaitingOtherPlayerTimer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetUnloadingLevelTimer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTotalLoadingTimer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AATile* GetTileFromWorldLocation(const FVector& WorldLocation) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTicketByRank(ERank rank) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAStartTile* GetStartTile() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<FName, FSpecificWeaponInPool> GetSpecificWeaponsInPool(bool bIsMultiPlayerGame);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSpecificWeaponPickupPoolCount(bool bIsMultiPlayerGame);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FSidePath GetSidePath(int32 PathID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSeededRandomRangeFloat(float Min, float Max, const FString& Context, ERandomSeedID ID, bool bSkippable);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetSeededRandomRange(int32 Min, int32 Max, const FString& Context, ERandomSeedID ID, bool bSkippable);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AASasTile*> GetSasTiles() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ERank GetRank(const FName& GameLevel, float LevelDuration, float LevelTotalExperience, int32& OutXPStarCount, int32& OutTimeStarCount, bool& bOutHasXP);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPercentForCompletionTime(bool bIsCorruptedPath, int32 PathID, float Duration) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetPathIDFromLevelName(const FName& LevelName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetNextLevelName(int32 PathID, FName& OutRowName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetNavMeshGenerationTimer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAMoonBossTile* GetMoonBossTileRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FVector2D> GetMerchantItemLuck() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetMaxTextFromRowName(const FName& RowName, FText& OutText, EMaxTextType& OutType) const;
    
    UFUNCTION(BlueprintCallable)
    bool GetMaxText(ETileType TileType, FName& OutRowName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FIntPoint GetLootRange() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLootGenerationTimer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAPlayerController* GetLocalPlayerControllerRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AALightSelector* GetLightSelectorRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLevelTimeRatioRemaining(float Duration) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLevelGenerationTimer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetExtractingPackageTimer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetEnemyLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetEnemyGenerationTimer() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetEndCinematicRowName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetDiggingHoleFromLocation(const FVector& WorldLocation) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetCurrentLevelName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCountOfActiveMutatorsByTypes(const TArray<EMutatorType>& Types) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ECorruptedLevelType GetCorruptedLevelType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCorruptedLevelTimeLimitation(ECorruptedRaceDifficulty Difficulty) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCorruptedLevelPathIDFromLevelName(const FName& LevelName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCorruptedLevelPathFromLocation(ETileType Location, FCorruptedLevelPath& OutCorruptedLevelPath) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FCorruptedLevelPath GetCorruptedLevelPath(int32 PathID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSoftObjectPtr<ULevelSequence> GetCorruptedLevelArenaSequence() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FText GetCorruptedLevelArenaName() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetCompletionTimeRange(bool bIsCorruptedPath, int32 PathID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCodeNumber();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AABossTile*> GetBossTilesRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FActBoss GetBossData() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AAArenaTile*> GetArenaTiles() const;
    
    UFUNCTION(BlueprintCallable)
    USoundCue* GetAmbientSound();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UALevelGeneratorMutator*> GetAllActiveMutators() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetAllActiveMutatorNamesWithoutScalable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FName> GetAllActiveMutatorNames() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UALevelGeneratorMutator* GetActiveMutatorByRowName(const FName& RowName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UALevelGeneratorMutator* FindActiveParentMutator(const FName& RowName) const;
    
    UFUNCTION(BlueprintCallable)
    void ExtractRowFromDataTable(const FName& RowName);
    
private:
    UFUNCTION(BlueprintCallable)
    void DelayedInitAllArenaTiles();
    
public:
    UFUNCTION(BlueprintCallable)
    void DeactivateTrapsOfGroupPermanently(uint8 ID);
    
private:
    UFUNCTION(BlueprintCallable)
    void CleanUpTilesFromQueue();
    
    UFUNCTION(BlueprintCallable)
    void AllOrderableActorsRegistered();
    
    UFUNCTION(BlueprintCallable)
    void AllDoorsRegistered(AATile* Tile);
    
public:
    UFUNCTION(BlueprintCallable)
    void AddPercentChanceToHaveAdditionalInfiniteRunEnemiesByEncounter(TSoftClassPtr<ACharacter_Enemy> EnemyClass, TArray<float> PercentChances);
    
    UFUNCTION(BlueprintCallable)
    void AddAdditionalInfiniteRunEnemies(TSoftClassPtr<ACharacter_Enemy> EnemyClass, int32 Count);
    
};

