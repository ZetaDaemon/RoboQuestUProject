#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "EPermanentReward.h"
#include "ACodeScreen.generated.h"

class AAGameState;
class AALevelGenerator;
class AAPlayerController;
class ACharacter_Player;

UCLASS(Blueprintable)
class ROBOQUEST_API AACodeScreen : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPermanentReward SecretDoor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DigitsCount;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAGameState* GameStateRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AALevelGenerator* LevelGeneratorRef;
    
public:
    AACodeScreen(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetSuccessState();
    
    UFUNCTION(BlueprintCallable)
    void SetErrorState();
    
    UFUNCTION(BlueprintCallable)
    void SetDigit(uint8 Digit, int32 Order);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetSuccessState();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetErrorState();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetDigit(uint8 Digit, int32 Order);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    int32 OnBlueprintGetCode();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintDisable(int32 Code);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintClear();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACharacter_Player* GetLocalPlayerRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAPlayerController* GetLocalPlayerControllerRef() const;
    
    UFUNCTION(BlueprintCallable)
    int32 GetCode();
    
    UFUNCTION(BlueprintCallable)
    void Disable(int32 Code);
    
    UFUNCTION(BlueprintCallable)
    void Clear();
    
};

