#pragma once
#include "CoreMinimal.h"
#include "APoint.h"
#include "EEncounterType.h"
#include "ALookAtPoint.generated.h"

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AALookAtPoint : public AAPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEncounterType Type;
    
    AALookAtPoint(const FObjectInitializer& ObjectInitializer);

};

