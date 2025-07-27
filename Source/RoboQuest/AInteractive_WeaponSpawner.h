#pragma once
#include "CoreMinimal.h"
#include "AInteractive.h"
#include "AInteractive_WeaponSpawner.generated.h"

class AAWeapon;
class ACharacter_Player;
class UBillboardComponent;
class USceneComponent;
class USkeletalMeshComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AAInteractive_WeaponSpawner : public AAInteractive {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* MeshRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SkeletalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* CollisionMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* LockedMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBillboardComponent* SpawnLocation;
    
    AAInteractive_WeaponSpawner(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SpawnWeapon(const TSoftClassPtr<AAWeapon>& WeaponClass, ACharacter_Player* PlayerRef);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetSpawnFeedbackActivate(bool bActivate);
    
};

