#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshActor -FallbackName=StaticMeshActor
#include "Engine/StaticMeshActor.h"
#include "LevelRowHandle.h"
#include "LevelStaticMeshActor.generated.h"

class ULevelStaticMeshComponent;
class UMaterialInterface;

UCLASS(Blueprintable)
class ROBOQUEST_API ALevelStaticMeshActor : public AStaticMeshActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULevelStaticMeshComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelRowHandle LevelToVisualizeInEditor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FLevelRowHandle, UMaterialInterface*> MaterialByLevel;
    
    ALevelStaticMeshActor(const FObjectInitializer& ObjectInitializer);

};

