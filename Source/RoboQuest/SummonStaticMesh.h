#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshActor -FallbackName=StaticMeshActor
#include "Engine/StaticMeshActor.h"
#include "SummonStaticMesh.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class ROBOQUEST_API ASummonStaticMesh : public AStaticMeshActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* DynamicMaterial;
    
public:
    ASummonStaticMesh(const FObjectInitializer& ObjectInitializer);

};

