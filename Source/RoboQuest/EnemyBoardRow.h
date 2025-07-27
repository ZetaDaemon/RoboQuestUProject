#pragma once
#include "CoreMinimal.h"
#include "ArenaEncounter.h"
#include "EEnemyBoardSelection.h"
#include "EnemyReplacementArray.h"
#include "HoleSpawner.h"
#include "PredefinedEncounter.h"
#include "Templates/SubclassOf.h"
#include "EnemyBoardRow.generated.h"

class ACharacter_Enemy;

USTRUCT(BlueprintType)
struct FEnemyBoardRow {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPredefinedEncounter> RegularEncounters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPredefinedEncounter> SpecificEncounters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPredefinedEncounter> IndieEncounters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FArenaEncounter> ArenaEncounters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemyBoardSelection ArenaEncountersSelection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<ACharacter_Enemy>> BigClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<ACharacter_Enemy>> BigSpawnClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ACharacter_Enemy> RegularWorkerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ACharacter_Enemy> LoopingWorkerClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<ACharacter_Enemy>> WallTurrets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<ACharacter_Enemy>> WallTurretClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FHoleSpawner> HoleSpawners;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemyReplacementArray ClassesToReplaceByPathPostSAS[3];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<ACharacter_Enemy>> ClassesToReplaceByElite;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<ACharacter_Enemy>> ClassesToReplaceByEliteLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEnemyReplacementArray> NewGamePlus;
    
    ROBOQUEST_API FEnemyBoardRow();
};

