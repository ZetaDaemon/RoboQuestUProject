#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "Engine/DataTable.h"
#include "RandomMeshAsset.h"
#include "RandomMeshRow.generated.h"

USTRUCT(BlueprintType)
struct FRandomMeshRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Dimension;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FRandomMeshAsset Tags[6];
    
    ROBOQUEST_API FRandomMeshRow();
};

