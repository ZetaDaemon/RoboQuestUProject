#pragma once
#include "CoreMinimal.h"
#include "APoint.h"
#include "ASpawnVolume.generated.h"

class UBoxComponent;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AASpawnVolume : public AAPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* Volume;
    
    AASpawnVolume(const FObjectInitializer& ObjectInitializer);

};

