#pragma once
#include "CoreMinimal.h"
#include "ASasTile.h"
#include "ACorruptedSasTile.generated.h"

class AATrap;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AACorruptedSasTile : public AASasTile {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AATrap*> Traps;
    
public:
    AACorruptedSasTile(const FObjectInitializer& ObjectInitializer);

};

