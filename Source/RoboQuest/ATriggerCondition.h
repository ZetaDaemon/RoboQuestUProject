#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "ATriggerCondition.generated.h"

class ACharacter_Player;
class UATriggerCondition;

UCLASS(Blueprintable)
class ROBOQUEST_API UATriggerCondition : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ACharacter_Player* PlayerCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UATriggerCondition*> Conditions;
    
    UATriggerCondition();

};

