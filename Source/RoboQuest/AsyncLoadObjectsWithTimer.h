#pragma once
#include "CoreMinimal.h"

//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintAsyncActionBase -FallbackName=BlueprintAsyncActionBase
#include "Kismet/BlueprintAsyncActionBase.h"
#include "LoadObjectsCompletePinDelegate.h"
#include "AsyncLoadObjectsWithTimer.generated.h"

class UAsyncLoadObjectsWithTimer;
class UObject;

UCLASS(Blueprintable)
class ROBOQUEST_API UAsyncLoadObjectsWithTimer : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLoadObjectsCompletePin Complete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* WorldContextObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UObject>> AssetsPtrArray;
    
public:
    UAsyncLoadObjectsWithTimer();

private:
    UFUNCTION(BlueprintCallable)
    void OnObjectsLoaded();
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UAsyncLoadObjectsWithTimer* AsyncLoadObjectsWithTimer(UObject* NewWorldContextObject, const TArray<TSoftObjectPtr<UObject>>& ObjectsPtrArray, int32 AsyncLoadPriority);
    
};

