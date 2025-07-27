#pragma once
#include "CoreMinimal.h"

//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintAsyncActionBase -FallbackName=BlueprintAsyncActionBase
#include "Kismet/BlueprintAsyncActionBase.h"
#include "LoadObjectWithDelayCompletePinDelegate.h"
#include "AsyncLoadObjectWithDelay.generated.h"

class UAsyncLoadObjectWithDelay;
class UObject;

UCLASS(Blueprintable)
class ROBOQUEST_API UAsyncLoadObjectWithDelay : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLoadObjectWithDelayCompletePin Complete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* WorldContextObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UObject> AssetPtr;
    
public:
    UAsyncLoadObjectWithDelay();

private:
    UFUNCTION(BlueprintCallable)
    void OnObjectLoaded();
    
    UFUNCTION(BlueprintCallable)
    void CompleteLoading();
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UAsyncLoadObjectWithDelay* AsyncLoadObjectWithDelay(UObject* NewWorldContextObject, TSoftObjectPtr<UObject> ObjectPtr, float DelayBeforeComplete, int32 AsyncLoadPriority);
    
};

