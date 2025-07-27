#pragma once
#include "CoreMinimal.h"
#include "ReplacementMeshLoaded.generated.h"

class UStaticMesh;

USTRUCT(BlueprintType)
struct FReplacementMeshLoaded {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UStaticMesh* PreviousMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UStaticMesh* NewMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float PercentChances;
    
    ROBOQUEST_API FReplacementMeshLoaded();
};

