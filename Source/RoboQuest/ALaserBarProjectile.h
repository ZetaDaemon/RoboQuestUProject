#pragma once
#include "CoreMinimal.h"
#include "AAIProjectile.h"
#include "ALaserBarProjectile.generated.h"

class AALaserTrap;
class USceneComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AALaserBarProjectile : public AAAIProjectile {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* LaserBarRoot;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AALaserTrap*> LaserRefs;
    
public:
    AALaserBarProjectile(const FObjectInitializer& ObjectInitializer);

};

