#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=CharacterMovementComponent -FallbackName=CharacterMovementComponent
#include "GameFramework/CharacterMovementComponent.h"
#include "ClientAuthorativeCMC.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROBOQUEST_API UClientAuthorativeCMC : public UCharacterMovementComponent {
    GENERATED_BODY()
public:
    UClientAuthorativeCMC(const FObjectInitializer& ObjectInitializer);

};

