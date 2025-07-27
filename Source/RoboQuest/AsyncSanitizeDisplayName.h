#pragma once
#include "CoreMinimal.h"

//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintAsyncActionBase -FallbackName=BlueprintAsyncActionBase
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncSanitizeDisplayName.generated.h"

class UAsyncSanitizeDisplayName;
class UObject;

UCLASS(Blueprintable)
class ROBOQUEST_API UAsyncSanitizeDisplayName : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAsyncSanitizeDisplayNameCompletePin, const FString&, SanitizedName);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAsyncSanitizeDisplayNameCompletePin Complete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* WorldContextObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FString DisplayNameToSanitize;
    
public:
    UAsyncSanitizeDisplayName();

private:
    UFUNCTION(BlueprintCallable)
    void OnNameSanitized(bool Success, const FString& SanitizedName);
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UAsyncSanitizeDisplayName* AsyncSanitizeDisplayName(UObject* NewWorldContextObject, const FString& DisplayName);
    
};

