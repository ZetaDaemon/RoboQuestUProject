#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshActor -FallbackName=StaticMeshActor
#include "Engine/StaticMeshActor.h"
#include "EActe.h"
#include "ActStaticMeshActor.generated.h"

class UMaterialInterface;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AActStaticMeshActor : public AStaticMeshActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EActe CurrentAct;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* MaterialByAct[4];
    
    AActStaticMeshActor(const FObjectInitializer& ObjectInitializer);

};

