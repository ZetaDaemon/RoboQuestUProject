#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=AnimNotify -FallbackName=AnimNotify
#include "EAnimationType.h"
#include "AnimNotify_MeleeWeaponVisibility.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class ROBOQUEST_API UAnimNotify_MeleeWeaponVisibility : public UAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bVisible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWeapon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimationType AnimType;
    
    UAnimNotify_MeleeWeaponVisibility();

};

