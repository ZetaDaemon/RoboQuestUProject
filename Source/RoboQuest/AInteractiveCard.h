#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "AInteractiveLootable.h"
#include "AInteractiveCard.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API AAInteractiveCard : public AAInteractiveLootable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RowName;
    
    AAInteractiveCard(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ResetCardText();
    
    UFUNCTION(BlueprintCallable)
    void LootedByMerchant(const FVector& LootLocation, const FRotator& LootRotation);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void InitCard(const FName& InRowName);
    
};

