#pragma once
#include "CoreMinimal.h"
#include "ActBoss.generated.h"

class ACharacter_Enemy;

USTRUCT(BlueprintType)
struct FActBoss {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<ACharacter_Enemy>> BossClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BossLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BossXP;
    
    ROBOQUEST_API FActBoss();
};

