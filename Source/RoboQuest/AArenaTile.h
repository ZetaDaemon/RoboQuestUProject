#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "ATile.h"
#include "EArenaSpawnerType.h"
#include "EDoorState.h"
#include "EStat.h"
#include "RQDamageInfo.h"
#include "AArenaTile.generated.h"

class AADoor;
class AActor;
class ACharacter_Enemy;
class ACharacter_Player;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AAArenaTile : public AATile {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateOnArenaValidated);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateEnteringArena);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateArenaValidationTimeLeftChanged, float, ValidationTimeLeft);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDelegateArenaHealthChanged, float, currentValue, float, FullValue);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsSecondArenaMoon;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateArenaValidationTimeLeftChanged DelegateArenaValidationTimeLeftChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateArenaHealthChanged DelegateArenaHealthChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnArenaValidated DelegateOnArenaValidated;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ACharacter_Enemy*> InvulnerableEnemies;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateEnteringArena DelegateEnteringArena;
    
    AAArenaTile(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnValidatedDoorCrossedByPlayer(AADoor* Door, ACharacter_Player* Player, const FVector& Forward);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnInvulnerableEnemyDestroyed(AActor* Actor);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnExitingArenaDoorStateChanged(AADoor* Door, EDoorState NewState);
    
    UFUNCTION(BlueprintCallable)
    void OnEnteringArenaDoorOpened(AADoor* Door, EDoorState NewState);
    
    UFUNCTION(BlueprintCallable)
    void OnEnteringArenaDoorClosed(AADoor* Door, EDoorState NewState);
    
    UFUNCTION(BlueprintCallable)
    void OnEnemyStatChanged(EStat Stat, float currentValue, float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnEnemyDeath(const FRQDamageInfo& DamageInfo);
    
    UFUNCTION(BlueprintCallable)
    void OnArenaSpawnerAvailabilityChanged(bool bIsAvailable, EArenaSpawnerType SpawnerType);
    
    UFUNCTION(BlueprintCallable)
    void CheckArenaTimerValidation();
    
    UFUNCTION(BlueprintCallable)
    void BindEventsOnEnemyEndInitialization(ACharacter_Enemy* Enemy);
    
    UFUNCTION(BlueprintCallable)
    void ActivateReinforcementEnemy();
    
};

