#pragma once
#include "CoreMinimal.h"
#include "AEnemyAnimInstance.h"
#include "AWorkerAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAWorkerAnimInstance : public UAEnemyAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsInTurboMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsNotStunnedAndInTurboMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsNotStunnedAndNotInTurboMode;
    
    UAWorkerAnimInstance();

};

