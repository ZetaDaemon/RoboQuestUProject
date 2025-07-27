#pragma once
#include "CoreMinimal.h"
#include "APickup.h"
#include "APickup_Experience.generated.h"

class UParticleSystemComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AAPickup_Experience : public AAPickup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* IdleFXComponent;
    
    AAPickup_Experience(const FObjectInitializer& ObjectInitializer);

};

