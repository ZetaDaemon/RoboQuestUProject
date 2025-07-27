#pragma once
#include "CoreMinimal.h"
#include "TriggerCondition_AWeapon.h"
#include "TriggerCondition_WeaponTags.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API UTriggerCondition_WeaponTags : public UTriggerCondition_AWeapon {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GameplayTags;
    
    UTriggerCondition_WeaponTags();

};

