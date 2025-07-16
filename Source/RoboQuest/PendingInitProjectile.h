#pragma once
#include "CoreMinimal.h"
#include "PendingInitProjectile.generated.h"

class AAProjectile;

USTRUCT(BlueprintType)
struct FPendingInitProjectile {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAProjectile* Projectile;
    
    ROBOQUEST_API FPendingInitProjectile();
};

