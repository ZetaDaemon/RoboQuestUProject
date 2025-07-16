#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "AWeaponAffix.generated.h"

class AAWeapon;

UCLASS(Blueprintable)
class ROBOQUEST_API UAWeaponAffix : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAWeapon* WeaponRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> CustomFloatProperties;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BaseRandomSeed;
    
    UAWeaponAffix();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnRemove();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnApply();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCustomFloatProperties(FName Name);
    
};

