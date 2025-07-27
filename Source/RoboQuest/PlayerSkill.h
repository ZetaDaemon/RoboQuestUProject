#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "Engine/DataTable.h"
#include "PlayerSkillRow.h"
#include "PlayerSkill.generated.h"

USTRUCT(BlueprintType)
struct FPlayerSkill : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerSkillRow PlayerSkill;
    
    ROBOQUEST_API FPlayerSkill();
};

