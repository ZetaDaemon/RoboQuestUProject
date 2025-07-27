#pragma once
#include "CoreMinimal.h"
#include "ASpawnerSlot.h"
#include "AHoleSpawnerSlot.generated.h"

class AAGameState;
class AAHoleSpawner;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AAHoleSpawnerSlot : public AASpawnerSlot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* HoloMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AAHoleSpawner> SpawnClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpawnLevel;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAGameState* GameStateRef;
    
public:
    AAHoleSpawnerSlot(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAGameState* GetGameStateRef() const;
    
};

