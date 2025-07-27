#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=OnlineBlueprintCallProxyBase -FallbackName=OnlineBlueprintCallProxyBase
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "QueryAchievementCallbackDelegateDelegate.h"
#include "RQQueryAchievementsCallbackProxy.generated.h"

class APlayerController;
class UObject;
class URQQueryAchievementsCallbackProxy;

UCLASS(Blueprintable)
class ROBOQUEST_API URQQueryAchievementsCallbackProxy : public UOnlineBlueprintCallProxyBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQueryAchievementCallbackDelegate OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQueryAchievementCallbackDelegate OnFailure;
    
public:
    URQQueryAchievementsCallbackProxy();

private:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static URQQueryAchievementsCallbackProxy* QueryAchievement(UObject* WorldContextObject, APlayerController* PlayerController);
    
};

