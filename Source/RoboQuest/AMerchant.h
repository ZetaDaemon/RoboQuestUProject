#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "IOrderableActor.h"
#include "AMerchant.generated.h"

class AAGameMode;
class AAGameState;
class AALevelGenerator;
class AAPlayerController;
class ACharacter_Player;
class UAGameInstance;
class UBoxComponent;
class USkeletalMeshComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AAMerchant : public AActor, public IIOrderableActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* BoundingBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* MerchantMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> UROVisibleDistanceFactorThesholds;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AALevelGenerator* LevelGeneratorRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAGameState* GameStateRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAGameMode* GameModeRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAGameInstance* GameInstanceRef;
    
public:
    AAMerchant(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetTickEnabled(bool bEnable);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnUnloadPreviousLevel();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintTeleported();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocalInteraction();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACharacter_Player* GetLocalPlayerRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAPlayerController* GetLocalPlayerControllerRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AALevelGenerator* GetLevelGeneratorRef();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAGameState* GetGameStateRef();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAGameMode* GetGameModeRef();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAGameInstance* GetGameInstanceRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FString GetDisplayName();
    

    // Fix for true pure virtual functions not being implemented
};

