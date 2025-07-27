#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "Engine/DataTable.h"
#include "AllyRow.h"
#include "Ally.generated.h"

USTRUCT(BlueprintType)
struct FAlly : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAllyRow Ally;
    
    ROBOQUEST_API FAlly();
};

