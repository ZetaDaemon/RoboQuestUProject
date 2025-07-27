#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=IntPoint -FallbackName=IntPoint
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=GameModeBase -FallbackName=GameModeBase
//CROSS-MODULE INCLUDE V2: -ModuleName=OnlineSubsystemUtils -ObjectName=BlueprintSessionResult -FallbackName=BlueprintSessionResult
#include "GameFramework/GameModeBase.h"
#include "EGameModeType.h"
#include "EMultiplayerLoot.h"
#include "ERandomSeedID.h"
#include "EWeaponCategory.h"
#include "EWeaponMetaRewardModifier.h"
#include "PlayerClassRow.h"
#include "PlayerData.h"
#include "Templates/SubclassOf.h"
#include "WeaponRow.h"
#include "AGameMode.generated.h"

class AAGameState;
class AAInteractiveWeapon;
class AAPlayerController;
class AAWeapon;
class ACharacter_Player;
class AController;
class APlayerController;
class UAGameInstance;
class UDataTable;

UCLASS(Blueprintable, NonTransient)
class ROBOQUEST_API AAGameMode : public AGameModeBase {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDelegateSessionDestroyed);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnPlayerDisconnected, AController*, ExitingPlayer);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnPlayerConnected, APlayerController*, NewPlayer);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnPause, bool, bIsPaused);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateOnNewPlayerCharacterSpawned, FPlayerData, PlayerData);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameModeType GameModeType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LevelTemp;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnPlayerConnected DelegateOnPlayerConnected;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateOnPlayerDisconnected DelegateOnPlayerDisconnected;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasOnlineSession;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegateSessionDestroyed DelegateOnSessionDestroyed;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<int32> MaxLevelWeaponPickupValues;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_Weapons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FWeaponRow> WeaponRowsArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TSoftClassPtr<AAWeapon>, TSubclassOf<AAWeapon>> WeaponClassLoaded;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AAWeapon> WeaponClassOnError;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAsyncLoadDataTable;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDataTable* DT_PlayerClasses;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RandomSeed;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAGameInstance* GameInstanceRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAGameState* GameStateRef;
    
public:
    AAGameMode(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    FPlayerClassRow SyncGetPlayerClassRow(const FName& RowName);
    
    UFUNCTION(BlueprintCallable)
    AAInteractiveWeapon* SpawnPickupWeaponByPowerLevel(const FIntPoint& LootRange, const FVector& Location, const FRotator& Rotation, EMultiplayerLoot MultiplayerLoot, int32 WeaponLevel, TArray<TSubclassOf<AAWeapon>> ExcludedWeapons);
    
    UFUNCTION(BlueprintCallable)
    AAInteractiveWeapon* SpawnPickupWeapon(const FVector& Location, const FRotator& Rotation, AAWeapon* WeaponRef, TSubclassOf<AAWeapon> WeaponClass, bool bStartDeactivate, int32 BaseRandomSeed, EMultiplayerLoot MultiplayerLoot, int32 WeaponLevel, int32 AffixAmount, bool bInitialWeapon, bool bSnapToGround, EWeaponMetaRewardModifier MetaRewardModifier, TSubclassOf<AAInteractiveWeapon> OverrideClass, TSoftClassPtr<AAWeapon> WeaponClassSoftPtr);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldSetNetworkModeMulti() const;
    
    UFUNCTION(BlueprintCallable)
    void SetNewPlayerData(const FPlayerData& NewPlayerData);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnWeaponsDataTableLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnWeaponLoaded();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnPlayerReadyForNextLevel(AController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerDisconnectedDuringEndLevel(AController* Controller);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnPlayerClassesDataTableLoaded(const FString& UniqueIdString, FName ClassRowName, FTransform SpawnTransform);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnEndLevel(const FName& NextLevelName);
    
    UFUNCTION(BlueprintCallable)
    void OnEndGame(bool bVictory);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnCommonWeaponDataAssetLoaded();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintPostLogin(APlayerController* NewPlayer);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintLogout(AController* ExitingPlayer);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintLevelGenerationStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintLevelGenerationEnd();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintEndLevel();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool OnBlueprintAllowPreLogin(FString& ErrorMessage);
    
    UFUNCTION(BlueprintCallable)
    void LoadCommonWeaponDataAsset();
    
    UFUNCTION(BlueprintCallable)
    TSubclassOf<AAWeapon> GetWeaponClassLoaded(TSoftClassPtr<AAWeapon> WeaponClassPtr);
    
    UFUNCTION(BlueprintCallable)
    TSubclassOf<AAWeapon> GetRandomWeaponClassByCategory(const FIntPoint& LootRange, EWeaponCategory Category, ACharacter_Player* PlayerRef, TArray<TSubclassOf<AAWeapon>> ExcludedWeapons, ERandomSeedID SeedID);
    
    UFUNCTION(BlueprintCallable)
    TSubclassOf<AAWeapon> GetRandomWeaponClass(const FIntPoint& LootRange, ACharacter_Player* PlayerRef, TArray<TSubclassOf<AAWeapon>> ExcludedWeapons, ERandomSeedID SeedID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FPlayerData> GetPlayersDataArray() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMaxLevelWeaponPickupValue();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAPlayerController* GetLocalPlayerControllerRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAGameState* GetGameStateRef() const;
    
    UFUNCTION(BlueprintCallable)
    void ExtractWeaponData();
    
};

