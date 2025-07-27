#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "Engine/DataTable.h"
#include "AIAttackRow.h"
#include "AIAttack.generated.h"

USTRUCT(BlueprintType)
struct FAIAttack : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIAttackRow AIAttack;
    
    ROBOQUEST_API FAIAttack();
};

