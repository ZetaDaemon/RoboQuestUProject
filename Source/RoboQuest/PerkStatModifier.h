#pragma once
#include "CoreMinimal.h"
#include "ModifierValue.h"
#include "PerkStatModifier.generated.h"

USTRUCT(BlueprintType)
struct FPerkStatModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FModifierValue BaseModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FModifierValue AdditiveModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SuperFeedback;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MegaFeedback;
    
    ROBOQUEST_API FPerkStatModifier();
};

