#pragma once
#include "CoreMinimal.h"
#include "APoint.h"
#include "Components/ArrowComponent.h"
#include "ACameraPoint.generated.h"

class UArrowComponent;
class UCameraComponent;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AACameraPoint : public AAPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraComponent* Camera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UArrowComponent* SpawnDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CameraPitchOffset;
    
    AACameraPoint(const FObjectInitializer& ObjectInitializer);

};

