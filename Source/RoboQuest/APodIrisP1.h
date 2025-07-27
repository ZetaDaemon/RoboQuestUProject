#pragma once
#include "CoreMinimal.h"
#include "APodAnimInstance.h"
#include "APodIrisP1.generated.h"

UCLASS(Blueprintable, NonTransient)
class ROBOQUEST_API UAPodIrisP1 : public UAPodAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOpen;
    
public:
    UAPodIrisP1();

};

