#pragma once
#include "CoreMinimal.h"
#include "AProjectile.h"
#include "APlayerProjectile.generated.h"

class AActor;

UCLASS(Blueprintable)
class ROBOQUEST_API AAPlayerProjectile : public AAProjectile {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* HomingTarget;
    
public:
    AAPlayerProjectile(const FObjectInitializer& ObjectInitializer);

};

