#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "Engine/DataTable.h"
#include "AISkillRow.h"
#include "AISkill.generated.h"

USTRUCT(BlueprintType)
struct FAISkill : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAISkillRow AISkill;
    
    ROBOQUEST_API FAISkill();
};

