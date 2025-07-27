#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Color -FallbackName=Color
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "Request_Crash.h"
#include "Request_Feedback.h"
#include "Request_Game.h"
#include "Request_InfiniteGame.h"
#include "AHttpService.generated.h"

UCLASS(Blueprintable)
class AAHttpService : public AActor {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnCrashReceived);
    
    AAHttpService(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SendUIScreenshot();
    
    UFUNCTION(BlueprintCallable)
    void SendTextData();
    
    UFUNCTION(BlueprintCallable)
    void SendInfiniteGameData(FRequest_InfiniteGame InfiniteGameData);
    
    UFUNCTION(BlueprintCallable)
    void SendGameData(FRequest_Game GameData);
    
    UFUNCTION(BlueprintCallable)
    void SendFeedback(FRequest_Feedback FeedbackRequest);
    
    UFUNCTION(BlueprintCallable)
    void SendCrash(FRequest_Crash CrashData);
    
    UFUNCTION(BlueprintCallable)
    void OnUIScreenshotFinished(int32 InSizeX, int32 InSizeY, const TArray<FColor>& InImageData);
    
};

