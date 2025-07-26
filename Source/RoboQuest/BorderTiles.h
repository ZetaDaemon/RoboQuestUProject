#pragma once
#include "CoreMinimal.h"
#include "BorderTiles.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FBorderTiles {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> Classes;
    
    ROBOQUEST_API FBorderTiles();
};

