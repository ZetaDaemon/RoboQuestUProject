#pragma once
#include "CoreMinimal.h"
#include "EAction.h"
#include "SkillInput.generated.h"

class UASkill;

USTRUCT(BlueprintType)
struct FSkillInput {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAction Input;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UASkill* Skill;
    
    ROBOQUEST_API FSkillInput();
};

