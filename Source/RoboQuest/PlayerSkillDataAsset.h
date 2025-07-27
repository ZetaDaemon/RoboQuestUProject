#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=PrimaryDataAsset -FallbackName=PrimaryDataAsset
#include "PlayerSkillDataAsset.generated.h"

class UDataTable;

UCLASS(Blueprintable)
class ROBOQUEST_API UPlayerSkillDataAsset : public UPrimaryDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_ElementalParticle;
    
    UPlayerSkillDataAsset();

};

