#pragma once
#include "CoreMinimal.h"
#include "ACameraPoint.h"
#include "APlayerPoint.generated.h"

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AAPlayerPoint : public AACameraPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 PlayerId;
    
    AAPlayerPoint(const FObjectInitializer& ObjectInitializer);

};

