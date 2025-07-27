#pragma once
#include "CoreMinimal.h"
#include "Modifier_Damage.h"
#include "Modifier_Damage_Scale.generated.h"

class ACharacter_Player;

UCLASS(Blueprintable)
class ROBOQUEST_API UModifier_Damage_Scale : public UModifier_Damage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ACharacter_Player* PlayerRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScaleValue;
    
    UModifier_Damage_Scale();

};

