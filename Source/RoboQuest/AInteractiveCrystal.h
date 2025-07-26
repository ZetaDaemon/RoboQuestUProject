#pragma once
#include "CoreMinimal.h"
#include "AInteractiveEndLevel.h"
#include "CrystalRow.h"
#include "AInteractiveCrystal.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API AAInteractiveCrystal : public AAInteractiveEndLevel {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWasCrystalFound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWasCrystalFoundByAllPlayers;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FCrystalRow LevelCrystalRow;
    
public:
    AAInteractiveCrystal(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetFoundState(bool bWasFound);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FName GetLevelName() const;
    
private:
    UFUNCTION(BlueprintCallable)
    FCrystalRow GetCrystalDataFromLevel();
    
};

