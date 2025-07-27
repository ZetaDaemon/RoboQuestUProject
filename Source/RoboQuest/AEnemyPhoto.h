#pragma once
#include "CoreMinimal.h"
#include "ABasecampActor.h"
#include "AEnemyPhoto.generated.h"

class UMaterialInterface;
class USkeletalMeshComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AAEnemyPhoto : public AABasecampActor {
    GENERATED_BODY()
public:
    AAEnemyPhoto(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SyncLoadAndApplyOverrideMaterial(USkeletalMeshComponent* Mesh, TSoftObjectPtr<UMaterialInterface> OverrideMaterialPtr, int32 Index);
    
};

