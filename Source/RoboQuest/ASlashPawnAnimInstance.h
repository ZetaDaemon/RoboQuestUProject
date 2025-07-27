#pragma once
#include "CoreMinimal.h"
#include "AFlyPawnAnimInstance.h"
#include "ASlashPawnAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ROBOQUEST_API UASlashPawnAnimInstance : public UAFlyPawnAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSlashState;
    
public:
    UASlashPawnAnimInstance();

    UFUNCTION(BlueprintCallable)
    void SetSlashState(bool bSlash);
    
};

