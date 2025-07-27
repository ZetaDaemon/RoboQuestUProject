#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
#include "APickup.h"
#include "APickup_Ticket.generated.h"

class UParticleSystemComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AAPickup_Ticket : public AAPickup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* IdleFXComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D RandomRotation;
    
    AAPickup_Ticket(const FObjectInitializer& ObjectInitializer);

};

