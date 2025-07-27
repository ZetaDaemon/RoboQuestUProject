#pragma once
#include "CoreMinimal.h"

//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintAsyncActionBase -FallbackName=BlueprintAsyncActionBase
#include "Kismet/BlueprintAsyncActionBase.h"
#include "LoadObjectFromPathCompletePinDelegate.h"
#include "AsyncLoadObjectFromPathWithTimer.generated.h"

class UAsyncLoadObjectFromPathWithTimer;
class UObject;

UCLASS(Blueprintable)
class ROBOQUEST_API UAsyncLoadObjectFromPathWithTimer : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLoadObjectFromPathCompletePin Complete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* WorldContextObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName AssetPath;
    
public:
    UAsyncLoadObjectFromPathWithTimer();

private:
    UFUNCTION(BlueprintCallable)
    void OnObjectLoaded();
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UAsyncLoadObjectFromPathWithTimer* AsyncLoadObjectFromPathWithTimer(UObject* NewWorldContextObject, FName ObjectPath, int32 AsyncLoadPriority);
    
};

