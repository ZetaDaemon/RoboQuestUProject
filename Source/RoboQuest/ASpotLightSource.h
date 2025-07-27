#pragma once
#include "CoreMinimal.h"
#include "ALightSource.h"
#include "ASpotLightSource.generated.h"

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AASpotLightSource : public AALightSource {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpotLightInnerConeAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpotLightOuterConeAngle;
    
    AASpotLightSource(const FObjectInitializer& ObjectInitializer);

};

