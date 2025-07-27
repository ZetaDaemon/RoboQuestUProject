#pragma once
#include "CoreMinimal.h"
#include "StaticMeshBlocker.h"
#include "StaticMeshBlocker_Cylinder.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API AStaticMeshBlocker_Cylinder : public AStaticMeshBlocker {
    GENERATED_BODY()
public:
    AStaticMeshBlocker_Cylinder(const FObjectInitializer& ObjectInitializer);

};

