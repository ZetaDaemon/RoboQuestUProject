#pragma once
#include "CoreMinimal.h"
#include "APodAnimInstance.h"
#include "ABurrowPodAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UABurrowPodAnimInstance : public UAPodAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsBurrowed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NotBurrowedValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInAlmostFinished;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOutAlmostFinished;
    
    UABurrowPodAnimInstance();

};

