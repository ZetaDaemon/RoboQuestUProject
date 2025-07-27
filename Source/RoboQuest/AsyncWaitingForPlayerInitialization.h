#pragma once
#include "CoreMinimal.h"

//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintAsyncActionBase -FallbackName=BlueprintAsyncActionBase
#include "Kismet/BlueprintAsyncActionBase.h"
#include "PlayerInitializedCompletePinDelegate.h"
#include "AsyncWaitingForPlayerInitialization.generated.h"

class AAPlayerController;
class UAsyncWaitingForPlayerInitialization;
class UObject;

UCLASS(Blueprintable)
class ROBOQUEST_API UAsyncWaitingForPlayerInitialization : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerInitializedCompletePin Complete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* WorldContextObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAPlayerController* PlayerControllerRef;
    
public:
    UAsyncWaitingForPlayerInitialization();

private:
    UFUNCTION(BlueprintCallable)
    void OnPlayerInitialized();
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerAssigned();
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UAsyncWaitingForPlayerInitialization* AsyncWaitingForPlayerInitialization(UObject* NewWorldContextObject, AAPlayerController* PlayerController);
    
};

