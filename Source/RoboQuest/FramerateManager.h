#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "FramerateManager.generated.h"

class AATile;

UCLASS(Blueprintable)
class ROBOQUEST_API AFramerateManager : public AActor {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUpdateFramerate, int32, FrameRate, bool, bWarning);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FramesBeforePrint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FramerateMinBeforeWarning;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUpdateFramerate OnUpdateFramerate;
    
    AFramerateManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void ToggleFramerateCounter(bool bIsDisplay);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnChangeTile(AATile* OldTile, AATile* NewTile);
    
};

