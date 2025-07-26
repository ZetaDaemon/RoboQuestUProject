#pragma once
#include "CoreMinimal.h"
#include "AInteractive.h"
#include "AInteractiveBomb.generated.h"

class UCurveFloat;

UCLASS(Blueprintable)
class ROBOQUEST_API AAInteractiveBomb : public AAInteractive {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveDefuseInteractTime;
    
    AAInteractiveBomb(const FObjectInitializer& ObjectInitializer);

};

