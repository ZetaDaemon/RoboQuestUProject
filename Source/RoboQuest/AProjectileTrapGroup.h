#pragma once
#include "CoreMinimal.h"
#include "ATrap.h"
#include "EProjectileExecutionOrder.h"
#include "ProjectileTrapPatternsRowHandle.h"
#include "Templates/SubclassOf.h"
#include "AProjectileTrapGroup.generated.h"

class AAProjectile;
class AAProjectileTrap;
class UAGameInstance;

UCLASS(Blueprintable)
class ROBOQUEST_API AAProjectileTrapGroup : public AATrap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FProjectileTrapPatternsRowHandle PatternsRow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EProjectileExecutionOrder ExecutionOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAvoidSamePatternTwice;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PrevisionalPatternCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAProjectileTrap*> Traps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<AAProjectile>, int32> ProjectileCountNeededByClass;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAGameInstance* GameInstanceRef;
    
public:
    AAProjectileTrapGroup(const FObjectInitializer& ObjectInitializer);

};

