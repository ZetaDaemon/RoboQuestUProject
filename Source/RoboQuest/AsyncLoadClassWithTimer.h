#pragma once
#include "CoreMinimal.h"

//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintAsyncActionBase -FallbackName=BlueprintAsyncActionBase
#include "Kismet/BlueprintAsyncActionBase.h"
#include "LoadClassCompletePinDelegate.h"
#include "AsyncLoadClassWithTimer.generated.h"

class UAsyncLoadClassWithTimer;
class UObject;

UCLASS(Blueprintable)
class ROBOQUEST_API UAsyncLoadClassWithTimer : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLoadClassCompletePin Complete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* WorldContextObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<UObject> AssetClassPtr;
    
public:
    UAsyncLoadClassWithTimer();

private:
    UFUNCTION(BlueprintCallable)
    void OnClassLoaded();
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UAsyncLoadClassWithTimer* AsyncLoadClassWithTimer(UObject* NewWorldContextObject, TSoftClassPtr<UObject> AssetClass, int32 AsyncLoadPriority);
    
};

