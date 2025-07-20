#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "Engine/DataTable.h"
#include "DamageFeedbackRow.h"
#include "DamageFeedback.generated.h"

USTRUCT(BlueprintType)
struct FDamageFeedback : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageFeedbackRow DamageFeedback;
    
    ROBOQUEST_API FDamageFeedback();
};

