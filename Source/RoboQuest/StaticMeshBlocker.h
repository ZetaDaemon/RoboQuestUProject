#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshActor -FallbackName=StaticMeshActor
#include "Engine/StaticMeshActor.h"
#include "StaticMeshBlocker.generated.h"

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AStaticMeshBlocker : public AStaticMeshActor {
    GENERATED_BODY()
public:
    AStaticMeshBlocker(const FObjectInitializer& ObjectInitializer);

};

