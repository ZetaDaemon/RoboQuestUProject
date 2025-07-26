#pragma once
#include "CoreMinimal.h"
#include "ETileType.h"
#include "Templates/SubclassOf.h"
#include "LoadedTileClass.generated.h"

class AATile;

USTRUCT(BlueprintType)
struct FLoadedTileClass {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AATile> Class;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETileType Type;
    
    ROBOQUEST_API FLoadedTileClass();
};

