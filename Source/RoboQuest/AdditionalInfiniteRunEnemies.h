#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AdditionalInfiniteRunEnemies.generated.h"

class ACharacter_Enemy;

USTRUCT(BlueprintType)
struct FAdditionalInfiniteRunEnemies {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ACharacter_Enemy> EnemyClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACharacter_Enemy> EnemyClassLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 Count;
    
    ROBOQUEST_API FAdditionalInfiniteRunEnemies();
};

