#pragma once
#include "CoreMinimal.h"
#include "APodAnimInstance.h"
#include "ABattlePodAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UABattlePodAnimInstance : public UAPodAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsAA;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsNotStunnedAndIsAA;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsNotStunnedAndIsNotAA;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSAtoSSAlmostFinished;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSStoSAAlmostFinished;
    
    UABattlePodAnimInstance();

};

