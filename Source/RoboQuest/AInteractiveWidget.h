#pragma once
#include "CoreMinimal.h"
#include "AInteractive.h"
#include "AInteractiveWidget.generated.h"

class UCurveFloat;
class UWidgetComponent;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AAInteractiveWidget : public AAInteractive {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* CurveDistance;
    
    AAInteractiveWidget(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetWidgetDisplay(bool bIsDisplay);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    UWidgetComponent* GetWidgetComponent() const;
    
};

