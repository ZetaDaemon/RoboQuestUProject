#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "Engine/DataTable.h"
#include "PlayerClassRow.h"
#include "PlayerClass.generated.h"

USTRUCT(BlueprintType)
struct FPlayerClass : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerClassRow PlayerClass;
    
    ROBOQUEST_API FPlayerClass();
};

