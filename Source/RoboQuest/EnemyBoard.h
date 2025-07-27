#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "Engine/DataTable.h"
#include "EnemyBoardRow.h"
#include "EnemyBoard.generated.h"

USTRUCT(BlueprintType)
struct FEnemyBoard : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemyBoardRow EnemyBoard;
    
    ROBOQUEST_API FEnemyBoard();
};

