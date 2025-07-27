#pragma once
#include "CoreMinimal.h"

//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintAsyncActionBase -FallbackName=BlueprintAsyncActionBase
#include "Kismet/BlueprintAsyncActionBase.h"
#include "WeaponInitializedCompletePinDelegate.h"
#include "AsyncWaitingForWeaponInitialization.generated.h"

class AAWeapon;
class UAsyncWaitingForWeaponInitialization;
class UObject;

UCLASS(Blueprintable)
class ROBOQUEST_API UAsyncWaitingForWeaponInitialization : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeaponInitializedCompletePin Complete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* WorldContextObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAWeapon* WeaponRef;
    
public:
    UAsyncWaitingForWeaponInitialization();

private:
    UFUNCTION(BlueprintCallable)
    void OnWeaponInitialized(AAWeapon* Weapon);
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UAsyncWaitingForWeaponInitialization* AsyncWaitingForWeaponInitialization(UObject* NewWorldContextObject, AAWeapon* Weapon);
    
};

