#pragma once
#include "CoreMinimal.h"
#include "ParticleSystemComponentPool.h"
#include "ParticleSystemComponentsPoolArray.generated.h"

USTRUCT(BlueprintType)
struct FParticleSystemComponentsPoolArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FParticleSystemComponentPool> Array;
    
    ROBOQUEST_API FParticleSystemComponentsPoolArray();
};

