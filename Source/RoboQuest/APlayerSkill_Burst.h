#pragma once
#include "CoreMinimal.h"
#include "APlayerSkill_Automatic.h"
#include "APlayerSkill_Burst.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROBOQUEST_API UAPlayerSkill_Burst : public UAPlayerSkill_Automatic {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BurstFirerate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BurstAmount;
    
    UAPlayerSkill_Burst(const FObjectInitializer& ObjectInitializer);

};

