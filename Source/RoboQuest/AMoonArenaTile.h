#pragma once
#include "CoreMinimal.h"
#include "AArenaTile.h"
#include "AMoonArenaTile.generated.h"

class AATrap;

UCLASS(Abstract, Blueprintable)
class ROBOQUEST_API AAMoonArenaTile : public AAArenaTile {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AATrap*> Traps;
    
public:
    AAMoonArenaTile(const FObjectInitializer& ObjectInitializer);

};

