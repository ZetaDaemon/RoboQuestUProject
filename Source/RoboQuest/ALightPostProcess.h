#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "ALightPostProcess.generated.h"

class UPostProcessComponent;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AALightPostProcess : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNeedsFlashLight;
    
    AALightPostProcess(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    UPostProcessComponent* GetPostProcessComponent() const;
    
};

