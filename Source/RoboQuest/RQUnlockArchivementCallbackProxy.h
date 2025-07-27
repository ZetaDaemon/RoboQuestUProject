#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=OnlineBlueprintCallProxyBase -FallbackName=OnlineBlueprintCallProxyBase
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "UnlockAchievementCallbackDelegateDelegate.h"
#include "RQUnlockArchivementCallbackProxy.generated.h"

class APlayerController;
class UObject;
class URQUnlockArchivementCallbackProxy;

UCLASS(Blueprintable)
class ROBOQUEST_API URQUnlockArchivementCallbackProxy : public UOnlineBlueprintCallProxyBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUnlockAchievementCallbackDelegate OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUnlockAchievementCallbackDelegate OnFailure;
    
    URQUnlockArchivementCallbackProxy();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static URQUnlockArchivementCallbackProxy* WriteAchievementProgress(UObject* WorldContextObject, APlayerController* PlayerController, FName AchievementName, float Progress);
    
};

