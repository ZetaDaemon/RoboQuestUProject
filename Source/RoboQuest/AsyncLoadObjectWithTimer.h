#pragma once
#include "CoreMinimal.h"

//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintAsyncActionBase -FallbackName=BlueprintAsyncActionBase
#include "Kismet/BlueprintAsyncActionBase.h"
#include "LoadObjectCompletePinDelegate.h"
#include "AsyncLoadObjectWithTimer.generated.h"

class UAsyncLoadObjectWithTimer;
class UObject;

UCLASS(Blueprintable)
class ROBOQUEST_API UAsyncLoadObjectWithTimer : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLoadObjectCompletePin Complete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* WorldContextObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UObject> AssetPtr;
    
public:
    UAsyncLoadObjectWithTimer();

private:
    UFUNCTION(BlueprintCallable)
    void OnObjectLoaded();
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UAsyncLoadObjectWithTimer* AsyncLoadObjectWithTimer(UObject* NewWorldContextObject, TSoftObjectPtr<UObject> ObjectPtr, int32 AsyncLoadPriority);
    
};

