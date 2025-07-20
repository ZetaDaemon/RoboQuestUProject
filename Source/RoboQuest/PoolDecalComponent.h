#pragma once
#include "CoreMinimal.h"
#include "Components/DecalComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DecalComponent -FallbackName=DecalComponent
#include "PoolDecalComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROBOQUEST_API UPoolDecalComponent : public UDecalComponent {
    GENERATED_BODY()
public:
    UPoolDecalComponent(const FObjectInitializer& ObjectInitializer);

};

