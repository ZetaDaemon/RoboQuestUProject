#pragma once
#include "CoreMinimal.h"
#include "AInteractive.h"
#include "ArtefactRowHandle.h"
#include "AInteractiveGadget.generated.h"

class URotatingMovementComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AAInteractiveGadget : public AAInteractive {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FArtefactRowHandle ArtefactRow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAlreadyUnlocked;
    
    AAInteractiveGadget(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    URotatingMovementComponent* GetRotatingMovementComponent() const;
    
};

