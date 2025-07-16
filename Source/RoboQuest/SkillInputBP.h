#pragma once
#include "CoreMinimal.h"
#include "EAction.h"
#include "Templates/SubclassOf.h"
#include "SkillInputBP.generated.h"

class UASkill;

USTRUCT(BlueprintType)
struct FSkillInputBP {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAction Input;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UASkill> Skill;
    
    ROBOQUEST_API FSkillInputBP();
};

