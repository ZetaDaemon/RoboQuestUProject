#pragma once
#include "CoreMinimal.h"
#include "CommonGeneratorDataAsset.h"
#include "EnemyBoardRowHandle.h"
#include "InfiniteActRowHandle.h"
#include "InfiniteBossRowHandle.h"
#include "InfiniteLayoutArray.h"
#include "LevelGeneratorMutatorRowHandle.h"
#include "LevelRowHandle.h"
#include "LootRowHandle.h"
#include "TileLoot.h"
#include "WeaponRowHandle.h"
#include "InfiniteRunDataAsset.generated.h"

class AActor;
class ACharacter_Enemy;

UCLASS(Blueprintable)
class ROBOQUEST_API UInfiniteRunDataAsset : public UCommonGeneratorDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInfiniteActRowHandle> ActsPool;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 TicketByRank[6];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLevelRowHandle> LevelsPool;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FInfiniteLayoutArray LayoutPool[3];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> XPByLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ACharacter_Enemy> StartLayoutWorkerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemyBoardRowHandle> EnemyBoardPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> SpecialTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInfiniteBossRowHandle> BossPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BossXPPercentOfLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PercentChanceToHaveLinkedMutators;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxCountOfMainMutatorsApplied;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxCountOfSecondaryMutatorsApplied;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelGeneratorMutatorRowHandle MaxLimitReachedMutator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTileLoot> FirstStartTileLoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTileLoot> StartTileLoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTileLoot> BossTileLoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLootRowHandle SmithingTedRow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeaponRowHandle> SmithingTedSpecificWeapons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWeaponRowHandle> SmithingTedSpecificWeaponsMultiplayer;
    
    UInfiniteRunDataAsset();

};

