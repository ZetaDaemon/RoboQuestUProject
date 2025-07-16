#pragma once
#include "CoreMinimal.h"
#include "AModifier.h"
#include "EModifierStatType.h"
#include "EStat.h"
#include "Modifier_Stat.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API UModifier_Stat : public UAModifier {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FDelegateOnModify, EStat, Stat, EModifierStatType, Type, float, Reliquat);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStat TargetStat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EModifierStatType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bModifiedBaseValue;
    
    UModifier_Stat();

    UFUNCTION(BlueprintCallable)
    void UpdateValue(float NewValue);
    
};

