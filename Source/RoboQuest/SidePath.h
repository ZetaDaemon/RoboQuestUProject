#pragma once
#include "CoreMinimal.h"
#include "EndPathTile.h"
#include "LevelLayoutTile.h"
#include "LootRowHandle.h"
#include "SplineCount.h"
#include "SidePath.generated.h"

USTRUCT(BlueprintType)
struct FSidePath {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEndPathTile SideTile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLevelLayoutTile> Layout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> LocationsID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSplineCount> Splines;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LevelXP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLootRowHandle> LevelLoot;
    
    ROBOQUEST_API FSidePath();
};

