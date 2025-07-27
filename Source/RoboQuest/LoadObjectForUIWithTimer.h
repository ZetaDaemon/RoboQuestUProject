#pragma once
#include "CoreMinimal.h"

//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintAsyncActionBase -FallbackName=BlueprintAsyncActionBase
#include "Kismet/BlueprintAsyncActionBase.h"
#include "LoadObjectForUICompletePinDelegate.h"
#include "LoadObjectForUIWithTimer.generated.h"

class ULoadObjectForUIWithTimer;
class UObject;

UCLASS(Blueprintable)
class ROBOQUEST_API ULoadObjectForUIWithTimer : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLoadObjectForUICompletePin Complete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* WorldContextObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UObject> AssetPtr;
    
public:
    ULoadObjectForUIWithTimer();

private:
    UFUNCTION(BlueprintCallable)
    void OnObjectLoaded();
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static ULoadObjectForUIWithTimer* LoadObjectForUIWithTimer(UObject* NewWorldContextObject, TSoftObjectPtr<UObject> ObjectPtr, int32 AsyncLoadPriority);
    
};

