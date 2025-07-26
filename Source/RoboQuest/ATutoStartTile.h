#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "AStartTile.h"
#include "EDoorState.h"
#include "Templates/SubclassOf.h"
#include "ATutoStartTile.generated.h"

class AAChest;
class AADoor;
class AActor;
class ACharacter_Player;
class UPrimitiveComponent;
class USpecialTriggerBoxComponent;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AATutoStartTile : public AAStartTile {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AADoor> SpecialDoorClass;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> InteriorClassToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* InteriorTileRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USpecialTriggerBoxComponent*> TriggerBoxes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AADoor* TutoSpecialDoor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAChest*> PendingChests;
    
public:
    AATutoStartTile(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void RegisterChest(AAChest* Chest);
    
private:
    UFUNCTION(BlueprintCallable)
    void OpenNextChest();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnSpecialDoorOpened(AADoor* Door, EDoorState NewState);
    
    UFUNCTION(BlueprintCallable)
    void OnSpecialDoorCrossedByPlayer(AADoor* Door, ACharacter_Player* Player, const FVector& ExitingForward);
    
    UFUNCTION(BlueprintCallable)
    void OnSpecialDoorClosed(AADoor* Door, EDoorState NewState);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintValidateTile();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSpecialDoorOpened();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnBeginTriggerOverlap(UPrimitiveComponent* OverlappedComp, AActor* OverlappingActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AADoor* GetTutoSpecialDoor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetInteriorTile() const;
    
};

