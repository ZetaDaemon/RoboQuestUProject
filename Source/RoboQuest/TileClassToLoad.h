#pragma once
#include "CoreMinimal.h"
#include "ETileType.h"
#include "TileClassToLoad.generated.h"

class AATile;

USTRUCT(BlueprintType)
struct FTileClassToLoad {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AATile> Class;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETileType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OrderId;
    
    ROBOQUEST_API FTileClassToLoad();
};

