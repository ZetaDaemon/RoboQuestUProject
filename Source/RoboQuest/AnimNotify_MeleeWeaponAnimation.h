#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=AnimNotify -FallbackName=AnimNotify
#include "EAnimationType.h"
#include "AnimNotify_MeleeWeaponAnimation.generated.h"

class UAnimMontage;

UCLASS(Blueprintable, CollapseCategories)
class ROBOQUEST_API UAnimNotify_MeleeWeaponAnimation : public UAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* MeleeWeaponAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimationType AnimType;
    
    UAnimNotify_MeleeWeaponAnimation();

};

