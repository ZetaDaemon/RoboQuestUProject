#pragma once
#include "CoreMinimal.h"
#include "AInteractiveLootable.h"
#include "AInteractiveItem.generated.h"

UCLASS(Blueprintable)
class ROBOQUEST_API AAInteractiveItem : public AAInteractiveLootable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ItemRowName;
    
    AAInteractiveItem(const FObjectInitializer& ObjectInitializer);

};

