#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=OnlineBlueprintCallProxyBase -FallbackName=OnlineBlueprintCallProxyBase
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "BlueprintRQBlockPlayerDelegateDelegate.h"
#include "BlockPlayerCallbackProxy.generated.h"

class APlayerController;
class APlayerState;
class UBlockPlayerCallbackProxy;
class UObject;

UCLASS(Blueprintable)
class ROBOQUEST_API UBlockPlayerCallbackProxy : public UOnlineBlueprintCallProxyBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintRQBlockPlayerDelegate OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintRQBlockPlayerDelegate OnFailure;
    
    UBlockPlayerCallbackProxy();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UBlockPlayerCallbackProxy* RQBlockPlayer(UObject* WorldContextObject, APlayerController* LocalPlayerController, APlayerState* PlayerToBlock);
    
};

