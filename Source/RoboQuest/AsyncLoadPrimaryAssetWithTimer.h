#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=PrimaryAssetId -FallbackName=PrimaryAssetId

//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintAsyncActionBase -FallbackName=BlueprintAsyncActionBase
#include "Kismet/BlueprintAsyncActionBase.h"
#include "LoadPrimaryAssetCompletePinDelegate.h"
#include "AsyncLoadPrimaryAssetWithTimer.generated.h"

class UAsyncLoadPrimaryAssetWithTimer;
class UObject;

UCLASS(Blueprintable)
class ROBOQUEST_API UAsyncLoadPrimaryAssetWithTimer : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLoadPrimaryAssetCompletePin Complete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* WorldContextObject;
    
public:
    UAsyncLoadPrimaryAssetWithTimer();

private:
    UFUNCTION(BlueprintCallable)
    void OnDataAssetLoaded();
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UAsyncLoadPrimaryAssetWithTimer* AsyncLoadPrimaryAssetWithTimer(UObject* NewWorldContextObject, FPrimaryAssetId PrimaryAsset, const TArray<FName>& LoadBundles);
    
};

