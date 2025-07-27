#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=OnlineBlueprintCallProxyBase -FallbackName=OnlineBlueprintCallProxyBase
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "UpdateStatsCallbackDelegateDelegate.h"
#include "UpdateStatsCallbackProxy.generated.h"

class APlayerController;
class UObject;
class UUpdateStatsCallbackProxy;

UCLASS(Blueprintable)
class ROBOQUEST_API UUpdateStatsCallbackProxy : public UOnlineBlueprintCallProxyBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUpdateStatsCallbackDelegate OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUpdateStatsCallbackDelegate OnFailure;
    
public:
    UUpdateStatsCallbackProxy();

private:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UUpdateStatsCallbackProxy* UpdateStats(UObject* WorldContextObject, APlayerController* PlayerController, TMap<FName, int32> StatsInt, TMap<FName, float> StatsFloat);
    
};

