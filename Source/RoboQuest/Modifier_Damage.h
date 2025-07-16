#pragma once
#include "CoreMinimal.h"
#include "AModifier.h"
#include "EGameplayTags.h"
#include "EModifierStatType.h"
#include "EStatus.h"
#include "RQHitResult.h"
#include "Modifier_Damage.generated.h"

class AACharacter;
class AAProjectile;
class UASkill;

UCLASS(Blueprintable)
class ROBOQUEST_API UModifier_Damage : public UAModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSuperTextFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMegaTextFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EModifierStatType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EGameplayTags> AddGameplayTag;
    
    UModifier_Damage();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool IsValidModifier(const FRQHitResult& RQHitResult, UASkill* Skill, AACharacter* Instigator, const TArray<EStatus>& StatusList, int32 GameplayTags, AAProjectile* Projectile);
    
};

