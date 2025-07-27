#pragma once
#include "CoreMinimal.h"
#include "APawnAnimInstance.h"
#include "ALarvaAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ROBOQUEST_API UALarvaAnimInstance : public UAPawnAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsInBeamState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHeadbonkProtection;
    
public:
    UALarvaAnimInstance();

};

