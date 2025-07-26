#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TileLoot.h"
#include "SpecificWallTile.generated.h"

class AAWallTile;

USTRUCT(BlueprintType)
struct FSpecificWallTile {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AAWallTile> Tile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AAWallTile> Class;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTileLoot> Loot;
    
    ROBOQUEST_API FSpecificWallTile();
};

