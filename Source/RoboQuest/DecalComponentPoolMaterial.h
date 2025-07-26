#pragma once
#include "CoreMinimal.h"
#include "DecalComponentPoolMaterial.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct FDecalComponentPoolMaterial {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* Material;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PoolBase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PoolMax;
    
    ROBOQUEST_API FDecalComponentPoolMaterial();
};

