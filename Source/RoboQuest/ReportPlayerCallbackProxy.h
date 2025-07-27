#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=OnlineBlueprintCallProxyBase -FallbackName=OnlineBlueprintCallProxyBase
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "BlueprintRQReportPlayerDelegateDelegate.h"
#include "EBPReportPlayerReason.h"
#include "ReportPlayerCallbackProxy.generated.h"

class APlayerController;
class APlayerState;
class UObject;
class UReportPlayerCallbackProxy;

UCLASS(Blueprintable)
class ROBOQUEST_API UReportPlayerCallbackProxy : public UOnlineBlueprintCallProxyBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintRQReportPlayerDelegate OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintRQReportPlayerDelegate OnFailure;
    
    UReportPlayerCallbackProxy();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UReportPlayerCallbackProxy* RQReportPlayer(UObject* WorldContextObject, APlayerController* LocalPlayerController, APlayerState* PlayerToReport, EBPReportPlayerReason ReportReason, const FString& Message);
    
};

