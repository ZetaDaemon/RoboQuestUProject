#pragma once
#include "CoreMinimal.h"
#include "CompendiumData.h"
#include "CompendiumDataCategory.h"
#include "CompendiumDataCategoryPerk.generated.h"

USTRUCT(BlueprintType)
struct FCompendiumDataCategoryPerk : public FCompendiumDataCategory {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCompendiumData> CommonPerks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCompendiumData> GuardianPerks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCompendiumData> ReconPerks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCompendiumData> EngineerPerks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCompendiumData> CommandoPerks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCompendiumData> SentinelPerks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCompendiumData> MagusPerks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCompendiumData> SuperbotPerks;
    
    ROBOQUEST_API FCompendiumDataCategoryPerk();
};

