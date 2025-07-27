#pragma once
#include "CoreMinimal.h"
#include "GeneratedLevelLayoutData.generated.h"

class AATile;

USTRUCT(BlueprintType)
struct FGeneratedLevelLayoutData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AATile*> Path;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AATile* LastTile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsPostSas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> AreaIDs;
    
    ROBOQUEST_API FGeneratedLevelLayoutData();
};

