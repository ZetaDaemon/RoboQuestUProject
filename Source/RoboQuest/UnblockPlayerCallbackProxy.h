#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=OnlineBlueprintCallProxyBase -FallbackName=OnlineBlueprintCallProxyBase
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "BlueprintRQUnblockPlayerDelegateDelegate.h"
#include "UnblockPlayerCallbackProxy.generated.h"

class APlayerController;
class UObject;
class UUnblockPlayerCallbackProxy;

UCLASS(Blueprintable)
class ROBOQUEST_API UUnblockPlayerCallbackProxy : public UOnlineBlueprintCallProxyBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintRQUnblockPlayerDelegate OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintRQUnblockPlayerDelegate OnFailure;
    
    UUnblockPlayerCallbackProxy();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UUnblockPlayerCallbackProxy* RQUnblockPlayer(UObject* WorldContextObject, APlayerController* LocalPlayerController, const FString& EOSUserIdToUnblock);
    
};

