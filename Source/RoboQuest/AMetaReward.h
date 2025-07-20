#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "AMetaReward.generated.h"

class AAPlayerController;
class ACharacter_Player;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API UAMetaReward : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ACharacter_Player* PlayerRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AAPlayerController* ControllerRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, float> CustomFloatProperties;
    
    UAMetaReward();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnBuy();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnApply();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCustomFloatValue(FName PropertyName);
    
};

