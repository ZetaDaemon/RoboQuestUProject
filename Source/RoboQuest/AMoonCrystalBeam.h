#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "CrystalRow.h"
#include "CrystalRowHandle.h"
#include "AMoonCrystalBeam.generated.h"

class AAGameState;
class UAGameInstance;
class USceneComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AAMoonCrystalBeam : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCrystalRowHandle CrystalRow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* Beam;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsCrystalActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FCrystalRow CrystalDataRow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAGameInstance* GameInstanceRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAGameState* GameStateRef;
    
public:
    AAMoonCrystalBeam(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintFoundCrystalRow();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnBeamMaterialLoaded();
    
};

