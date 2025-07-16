#pragma once
#include "CoreMinimal.h"
#include "SurfaceSoundAndFx.generated.h"

class UParticleSystem;
class USoundCue;

USTRUCT(BlueprintType)
struct FSurfaceSoundAndFx {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* FXByDamageType[10];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* SoundByDamageType[10];
    
    ROBOQUEST_API FSurfaceSoundAndFx();
};

