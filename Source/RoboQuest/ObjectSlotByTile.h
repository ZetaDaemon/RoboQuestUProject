#pragma once
#include "CoreMinimal.h"
#include "ObjectSlotByTile.generated.h"

class AAObjectSlot;
class AATile;

USTRUCT(BlueprintType)
struct FObjectSlotByTile {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAObjectSlot* ObjectSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AATile* Tile;
    
    ROBOQUEST_API FObjectSlotByTile();
};

