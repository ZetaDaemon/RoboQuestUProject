#pragma once
#include "CoreMinimal.h"
#include "DecalComponentPoolMaterial.h"
#include "DecalComponentPoolData.generated.h"

USTRUCT(BlueprintType)
struct FDecalComponentPoolData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FDecalComponentPoolMaterial ImpactDecals[4];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FDecalComponentPoolMaterial AreaDecals[5];
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FDecalComponentPoolMaterial EnemyDeathDecals[7];
    
    ROBOQUEST_API FDecalComponentPoolData();
};

