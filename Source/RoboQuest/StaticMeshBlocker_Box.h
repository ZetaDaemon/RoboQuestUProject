#pragma once
#include "CoreMinimal.h"
#include "StaticMeshBlocker.h"
#include "StaticMeshBlocker_Box.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API AStaticMeshBlocker_Box : public AStaticMeshBlocker {
    GENERATED_BODY()
public:
    AStaticMeshBlocker_Box(const FObjectInitializer& ObjectInitializer);

};

