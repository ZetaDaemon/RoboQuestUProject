#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "Engine/DataTable.h"
#include "DifficultyRow.h"
#include "SDifficulty.generated.h"

USTRUCT(BlueprintType)
struct FSDifficulty : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDifficultyRow Difficulty;
    
    ROBOQUEST_API FSDifficulty();
};

