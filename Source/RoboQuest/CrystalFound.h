#pragma once
#include "CoreMinimal.h"
#include "CrystalFound.generated.h"

USTRUCT(BlueprintType)
struct FCrystalFound {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LevelName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsActivated;
    
    ROBOQUEST_API FCrystalFound();
};

