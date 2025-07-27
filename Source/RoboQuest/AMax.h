#pragma once
#include "CoreMinimal.h"
#include "ACharacter.h"
#include "AMax.generated.h"

class UAnimSequence;
class UBlendSpace;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AAMax : public AACharacter {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateSpeak);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> UROVisibleDistanceFactorThesholds;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateSpeak DelegateStartSpeak;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateSpeak DelegateEndSpeak;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TutoIndex;
    
    AAMax(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateIdleAndAIM(UAnimSequence* IdleAnimation, UBlendSpace* AIM, bool bHandTablette);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetScaredState(bool bScared);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetDialogBoxMaxDistance(float NewDistance);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintAssignTextAndAnimation(const FText& Text, const FName& AnimRowName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintAssignText(const FName& TextRowName);
    
};

