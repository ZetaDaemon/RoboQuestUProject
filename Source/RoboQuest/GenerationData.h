#pragma once
#include "CoreMinimal.h"
#include "GenerationData.generated.h"

class AATile;

USTRUCT(BlueprintType)
struct FGenerationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText LevelName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TileSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AATile*> GeneratedTiles;
    
    ROBOQUEST_API FGenerationData();
};

