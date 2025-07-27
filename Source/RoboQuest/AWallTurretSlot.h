#pragma once
#include "CoreMinimal.h"
#include "ASpawnerSlot.h"
#include "AWallTurretSlot.generated.h"

class USkeletalMeshComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AAWallTurretSlot : public AASpawnerSlot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* HoloMesh;
    
    AAWallTurretSlot(const FObjectInitializer& ObjectInitializer);

};

