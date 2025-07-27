#pragma once
#include "CoreMinimal.h"
#include "AInteractive.h"
#include "AInteractiveEndLevel.generated.h"

class UACompassLocator;

UCLASS(Blueprintable)
class ROBOQUEST_API AAInteractiveEndLevel : public AAInteractive {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TravelToText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText EndGameText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText NextLevelText;
    
    AAInteractiveEndLevel(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnUpdateLocalization(const FString& NewLanguage);
    
public:
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    float GetFadeToBlackDelayBeforeEndLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UACompassLocator* GetCompassLocator();
    
    UFUNCTION(BlueprintCallable)
    void EndLevel();
    
    UFUNCTION(BlueprintCallable)
    void DelayedFadeToBlack();
    
};

