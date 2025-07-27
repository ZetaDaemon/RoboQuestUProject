#pragma once
#include "CoreMinimal.h"
#include "APoint.h"
#include "EPickupLocation.h"
#include "APickupPoint.generated.h"

class AAGameState;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AAPickupPoint : public AAPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPickupLocation Location;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAGameState* GameStateRef;
    
public:
    AAPickupPoint(const FObjectInitializer& ObjectInitializer);

};

