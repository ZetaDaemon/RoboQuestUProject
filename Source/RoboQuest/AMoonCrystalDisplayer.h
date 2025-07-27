#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "AMoonCrystalDisplayer.generated.h"

class AAGameState;
class AAPlayerController;
class ACharacter_Player;
class UAGameInstance;
class USceneComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AAMoonCrystalDisplayer : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* Mesh;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAPlayerController* LocalPlayerControllerRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacter_Player* LocalPlayerCharacterRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAGameInstance* GameInstanceRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAGameState* GameStateRef;
    
public:
    AAMoonCrystalDisplayer(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAPlayerController* GetLocalPlayerControllerRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACharacter_Player* GetLocalPlayerCharacterRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AAGameState* GetGameStateRef() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UAGameInstance* GetGameInstanceRef() const;
    
};

