#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "Engine/DataTable.h"
#include "LootRow.h"
#include "LootRowBase.generated.h"

USTRUCT(BlueprintType)
struct FLootRowBase : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLootRow LootRow;
    
    ROBOQUEST_API FLootRowBase();
};

