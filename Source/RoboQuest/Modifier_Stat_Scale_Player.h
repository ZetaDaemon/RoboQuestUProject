#pragma once
#include "CoreMinimal.h"
#include "Modifier_Stat_Scale.h"
#include "Modifier_Stat_Scale_Player.generated.h"

class ACharacter_Player;

UCLASS(Blueprintable)
class ROBOQUEST_API UModifier_Stat_Scale_Player : public UModifier_Stat_Scale {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ACharacter_Player* PlayerRef;
    
    UModifier_Stat_Scale_Player();

};

