#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=OnlineBlueprintCallProxyBase -FallbackName=OnlineBlueprintCallProxyBase
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "QueryStatsCallbackDelegateDelegate.h"
#include "RQQueryStatsCallbackProxy.generated.h"

class APlayerController;
class UObject;
class URQQueryStatsCallbackProxy;

UCLASS(Blueprintable)
class ROBOQUEST_API URQQueryStatsCallbackProxy : public UOnlineBlueprintCallProxyBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQueryStatsCallbackDelegate OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQueryStatsCallbackDelegate OnFailure;
    
public:
    URQQueryStatsCallbackProxy();

private:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static URQQueryStatsCallbackProxy* QueryStats(UObject* WorldContextObject, APlayerController* PlayerController);
    
};

