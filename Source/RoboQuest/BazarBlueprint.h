#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "BazarBlueprint.generated.h"

class AAInteractive;

USTRUCT(BlueprintType)
struct FBazarBlueprint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AAInteractive> Class;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Price;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Quantity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZOffset;
    
    ROBOQUEST_API FBazarBlueprint();
};

