#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TileLoot.h"
#include "StartTile.generated.h"

class AATile;
class AActor;

USTRUCT(BlueprintType)
struct FStartTile {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AATile> TileClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTileLoot> Loot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGenerateRoof;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCustomBorderTiles;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> BorderTiles[7];
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> BorderClasses[7];
    
    ROBOQUEST_API FStartTile();
};

