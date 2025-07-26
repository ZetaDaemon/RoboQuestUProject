#pragma once
#include "CoreMinimal.h"
#include "ReplacementMesh.generated.h"

class UStaticMesh;

USTRUCT(BlueprintType)
struct FReplacementMesh {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> PreviousMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> NewMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PercentChances;
    
    ROBOQUEST_API FReplacementMesh();
};

