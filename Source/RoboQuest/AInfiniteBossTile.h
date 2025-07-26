#pragma once
#include "CoreMinimal.h"
#include "ABossTile.h"
#include "Templates/SubclassOf.h"
#include "AInfiniteBossTile.generated.h"

class AAHoleSpawner;
class AAInfiniteBossPoint;
class AActor;

UCLASS(Blueprintable)
class ROBOQUEST_API AAInfiniteBossTile : public AABossTile {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAInfiniteBossPoint*> UnusedInfiniteBossPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAHoleSpawner*> BossHoleSpawners;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> InteriorClassToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* InteriorTileRef;
    
public:
    AAInfiniteBossTile(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetInteriorTile() const;
    
};

