#pragma once
#include "CoreMinimal.h"
#include "ParticleSystemComponentPool.generated.h"

class UParticleSystemComponent;

USTRUCT(BlueprintType)
struct FParticleSystemComponentPool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* ParticleSystemComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 UseCount;
    
    ROBOQUEST_API FParticleSystemComponentPool();
};

