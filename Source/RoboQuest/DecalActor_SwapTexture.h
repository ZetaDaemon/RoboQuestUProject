#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DecalActor -FallbackName=DecalActor
#include "Engine/DecalActor.h"
#include "DecalActor_SwapTexture.generated.h"

class UDecalComponent_SwapTexture;
class UMaterialInstanceDynamic;
class UMaterialInterface;

UCLASS(Blueprintable)
class ROBOQUEST_API ADecalActor_SwapTexture : public ADecalActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDecalComponent_SwapTexture* DecalComponentSwapTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* DynMaterial;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* Material;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 TextureIndex;
    
    ADecalActor_SwapTexture(const FObjectInitializer& ObjectInitializer);

};

