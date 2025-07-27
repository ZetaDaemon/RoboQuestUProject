#pragma once
#include "CoreMinimal.h"
#include "RandomMeshAsset.generated.h"

class UStaticMesh;

USTRUCT(BlueprintType)
struct FRandomMeshAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UStaticMesh>> Meshes;
    
    ROBOQUEST_API FRandomMeshAsset();
};

