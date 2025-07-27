#pragma once
#include "CoreMinimal.h"

//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintAsyncActionBase -FallbackName=BlueprintAsyncActionBase
#include "Kismet/BlueprintAsyncActionBase.h"
#include "LocalPlayerInitializationInBasecampCompletePinDelegate.h"
#include "AsyncWaitingForLocalPlayerInitializationInBasecamp.generated.h"

class AAGameState;
class UAsyncWaitingForLocalPlayerInitializationInBasecamp;
class UObject;

UCLASS(Blueprintable)
class ROBOQUEST_API UAsyncWaitingForLocalPlayerInitializationInBasecamp : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocalPlayerInitializationInBasecampCompletePin Complete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* WorldContextObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAGameState* GameStateRef;
    
public:
    UAsyncWaitingForLocalPlayerInitializationInBasecamp();

private:
    UFUNCTION(BlueprintCallable)
    void OnLocalPlayerInitializationInBasecamp();
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UAsyncWaitingForLocalPlayerInitializationInBasecamp* AsyncWaitingForLocalPlayerInitializationInBasecamp(UObject* NewWorldContextObject, AAGameState* GameState);
    
};

