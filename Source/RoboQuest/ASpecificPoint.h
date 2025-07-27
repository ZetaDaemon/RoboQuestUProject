#pragma once
#include "CoreMinimal.h"
#include "ASpawnPoint.h"
#include "ASpecificPoint.generated.h"

class ACharacter_Enemy;
class UTexture2D;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AASpecificPoint : public AASpawnPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ACharacter_Enemy> ClassToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInvulnerable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* SelfIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* IndieIcon;
    
    AASpecificPoint(const FObjectInitializer& ObjectInitializer);

};

