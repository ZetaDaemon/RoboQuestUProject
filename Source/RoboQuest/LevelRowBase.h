#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "Engine/DataTable.h"
#include "LevelRow.h"
#include "LevelRowBase.generated.h"

USTRUCT(BlueprintType)
struct FLevelRowBase : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelRow LevelRow;
    
    ROBOQUEST_API FLevelRowBase();
};

