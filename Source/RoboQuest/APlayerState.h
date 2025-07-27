#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=PlayerState -FallbackName=PlayerState
#include "EStorePlatform.h"
#include "APlayerState.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API AAPlayerState : public APlayerState {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_PlayerNameSuffix, meta=(AllowPrivateAccess=true))
    FString NameSuffixPrivate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_StorePlatform, meta=(AllowPrivateAccess=true))
    EStorePlatform StorePlatform;
    
public:
    AAPlayerState(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void OnRep_StorePlatform();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_PlayerNameSuffix();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EStorePlatform GetStorePlatform() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetPlayerNameSuffix() const;
    
};

