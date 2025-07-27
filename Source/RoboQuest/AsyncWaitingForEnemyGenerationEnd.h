#pragma once
#include "CoreMinimal.h"

//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintAsyncActionBase -FallbackName=BlueprintAsyncActionBase
#include "Kismet/BlueprintAsyncActionBase.h"
#include "OnEnemyGenerationEndCompletePinDelegate.h"
#include "AsyncWaitingForEnemyGenerationEnd.generated.h"

class AALevelGenerator;
class UAsyncWaitingForEnemyGenerationEnd;
class UObject;

UCLASS(Blueprintable)
class ROBOQUEST_API UAsyncWaitingForEnemyGenerationEnd : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnEnemyGenerationEndCompletePin Complete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* WorldContextObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AALevelGenerator* LevelGeneratorRef;
    
public:
    UAsyncWaitingForEnemyGenerationEnd();

private:
    UFUNCTION(BlueprintCallable)
    void OnEnemyGenerationEnd();
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UAsyncWaitingForEnemyGenerationEnd* AsyncWaitingForEnemyGenerationEnd(UObject* NewWorldContextObject, AALevelGenerator* LevelGenerator);
    
};

