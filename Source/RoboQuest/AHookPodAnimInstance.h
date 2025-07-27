#pragma once
#include "CoreMinimal.h"
#include "APodAnimInstance.h"
#include "AHookPodAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAHookPodAnimInstance : public UAPodAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsBurrowed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsNotStunnedAndIsBurrowed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsNotStunnedAndIsNotBurrowed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentPitchAim;
    
    UAHookPodAnimInstance();

};

