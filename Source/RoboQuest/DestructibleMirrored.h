#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "DestructibleMirrored.generated.h"

class AADestructible;

USTRUCT(BlueprintType)
struct FDestructibleMirrored {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AADestructible> Regular;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AADestructible> Mirrored;
    
    ROBOQUEST_API FDestructibleMirrored();
};

