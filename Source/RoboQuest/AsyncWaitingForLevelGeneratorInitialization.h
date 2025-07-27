#pragma once
#include "CoreMinimal.h"

//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintAsyncActionBase -FallbackName=BlueprintAsyncActionBase
#include "Kismet/BlueprintAsyncActionBase.h"
#include "LevelGeneratorInitializedCompletePinDelegate.h"
#include "AsyncWaitingForLevelGeneratorInitialization.generated.h"

class AALevelGenerator;
class UAsyncWaitingForLevelGeneratorInitialization;
class UObject;

UCLASS(Blueprintable)
class ROBOQUEST_API UAsyncWaitingForLevelGeneratorInitialization : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelGeneratorInitializedCompletePin Complete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* WorldContextObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AALevelGenerator* LevelGeneratorRef;
    
public:
    UAsyncWaitingForLevelGeneratorInitialization();

private:
    UFUNCTION(BlueprintCallable)
    void OnGeneratorDataAssetLoaded();
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UAsyncWaitingForLevelGeneratorInitialization* AsyncWaitingForLevelGeneratorInitialization(UObject* NewWorldContextObject, AALevelGenerator* LevelGenerator);
    
};

