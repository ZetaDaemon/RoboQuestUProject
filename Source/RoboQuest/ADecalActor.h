#pragma once
#include "CoreMinimal.h"
#include "Engine/DecalActor.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DecalActor -FallbackName=DecalActor
#include "Engine/DecalActor.h"
#include "ADecalActor.generated.h"

class UCustomDecalComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AADecalActor : public ADecalActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCustomDecalComponent* RootCustomDecalComponent;
    
    AADecalActor(const FObjectInitializer& ObjectInitializer);

};

