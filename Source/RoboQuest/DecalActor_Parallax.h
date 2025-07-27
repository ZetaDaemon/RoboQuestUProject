#pragma once
#include "CoreMinimal.h"
#include "ADecalActor.h"
#include "DecalActor_Parallax.generated.h"

class UMaterialInterface;

UCLASS(Blueprintable)
class ROBOQUEST_API ADecalActor_Parallax : public AADecalActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* Material;
    
    ADecalActor_Parallax(const FObjectInitializer& ObjectInitializer);

};

