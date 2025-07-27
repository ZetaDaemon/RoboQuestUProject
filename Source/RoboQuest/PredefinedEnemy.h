#pragma once
#include "CoreMinimal.h"
#include "EEnemyBoardPosition.h"
#include "Templates/SubclassOf.h"
#include "PredefinedEnemy.generated.h"

class ACharacter_Enemy;

USTRUCT(BlueprintType)
struct FPredefinedEnemy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ACharacter_Enemy> AssetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACharacter_Enemy> Class;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemyBoardPosition Position;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Count;
    
    ROBOQUEST_API FPredefinedEnemy();
};

