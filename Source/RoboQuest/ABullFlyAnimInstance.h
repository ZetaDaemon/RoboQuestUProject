#pragma once
#include "CoreMinimal.h"
#include "AFlyAnimInstance.h"
#include "ABullFlyAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ROBOQUEST_API UABullFlyAnimInstance : public UAFlyAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsCharging;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHaveHitPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bChargeLoopToEndCharge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bChargeLoopToEndChargeHit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartChargeToChargeLoop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEndChargeToIdle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEndChargeHitToIdle;
    
public:
    UABullFlyAnimInstance();

    UFUNCTION(BlueprintCallable)
    void SetIsCharging(bool bCharging);
    
    UFUNCTION(BlueprintCallable)
    void SetHaveHitPlayer(bool bHitPlayer);
    
};

