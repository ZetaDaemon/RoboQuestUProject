#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
#include "StaticMeshMirrored.generated.h"

class UStaticMesh;

USTRUCT(BlueprintType)
struct FStaticMeshMirrored {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform MirroredTransform;
    
    ROBOQUEST_API FStaticMeshMirrored();
};

