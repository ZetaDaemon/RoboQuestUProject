#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AdditionalInfiniteRunEnemiesPercentByEncounter.generated.h"

class ACharacter_Enemy;

USTRUCT(BlueprintType)
struct FAdditionalInfiniteRunEnemiesPercentByEncounter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ACharacter_Enemy> EnemyClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACharacter_Enemy> EnemyClassLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<float> PercentChances;
    
    ROBOQUEST_API FAdditionalInfiniteRunEnemiesPercentByEncounter();
};

