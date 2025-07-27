#pragma once
#include "CoreMinimal.h"
#include "ASlot.h"
#include "StoryCapsuleRowHandle.h"
#include "AStorySlot.generated.h"

class AActor;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AAStorySlot : public AASlot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStoryCapsuleRowHandle StoryCapsuleRow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> InteractiveStoryClass;
    
    AAStorySlot(const FObjectInitializer& ObjectInitializer);

};

