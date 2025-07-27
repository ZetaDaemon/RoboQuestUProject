#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "ASpeaker.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API AASpeaker : public AActor {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateSpeaker);
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateSpeaker DelegateStartSpeak;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateSpeaker DelegateEndSpeak;
    
    AASpeaker(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetDialogBoxMaxDistance(float NewDistance);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintAssignText(const FName& TextRowName);
    
};

