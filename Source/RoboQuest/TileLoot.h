#pragma once
#include "CoreMinimal.h"
#include "EObjectSlotLocation.h"
#include "LootBundleRowHandle.h"
#include "TileLoot.generated.h"

USTRUCT(BlueprintType)
struct FTileLoot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLootBundleRowHandle Loot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EObjectSlotLocation Location;
    
    ROBOQUEST_API FTileLoot();
};

