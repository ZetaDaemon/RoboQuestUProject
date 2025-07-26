#pragma once
#include "CoreMinimal.h"
#include "AArenaTile.h"
#include "EDoorState.h"
#include "ACorruptedArenaTile.generated.h"

class AADoor;
class AAInteractiveCrystal;
class AATrap;
class AActor;
class ALevelSequenceActor;
class ULevelSequence;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AACorruptedArenaTile : public AAArenaTile {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AATrap*> Traps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<ULevelSequence> ArenaSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ALevelSequenceActor* LevelSequenceActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> TeleportPoints;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAInteractiveCrystal* InteractiveCrystalRef;
    
    AACorruptedArenaTile(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void StartSequence();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSequenceLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnSequenceFinished();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnSafeZoneDoorStateChanged(AADoor* Door, EDoorState NewState);
    
    UFUNCTION(BlueprintCallable)
    void OnCorruptedArenaDoorOpened(AADoor* Door, EDoorState NewState);
    
};

