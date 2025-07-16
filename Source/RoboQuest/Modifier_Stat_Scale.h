#pragma once
#include "CoreMinimal.h"
#include "Modifier_Stat.h"
#include "Modifier_Stat_Scale.generated.h"

class UCurveFloat;

UCLASS(Blueprintable)
class ROBOQUEST_API UModifier_Stat_Scale : public UModifier_Stat {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScaleValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bScaleWithCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* ScaleCurve;
    
    UModifier_Stat_Scale();

    UFUNCTION(BlueprintCallable)
    void UpdateScaleValue(float NewValue);
    
    UFUNCTION(BlueprintCallable)
    void UpdateScaleAmount(int32 NewScaleAmount);
    
};

