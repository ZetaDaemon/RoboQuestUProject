#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "Components/BoxComponent.h"
#include "ALaserTrap.h"
#include "ADoubleLaserTrap.generated.h"

class UBoxComponent;
class USceneComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AADoubleLaserTrap : public AALaserTrap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root_TriggerBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root_SecondTriggerBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* SecondTriggerBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector SecondRadiusOffset;
    
    AADoubleLaserTrap(const FObjectInitializer& ObjectInitializer);

};

