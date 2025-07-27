#pragma once
#include "CoreMinimal.h"
#include "ANPCAnimInstance.h"
#include "AGarryAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ROBOQUEST_API UAGarryAnimInstance : public UANPCAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSuccess;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bJackpot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HypeRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDeactivate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartDeactivate;
    
public:
    UAGarryAnimInstance();

};

