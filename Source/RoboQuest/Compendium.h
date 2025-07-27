#pragma once
#include "CoreMinimal.h"
#include "CompendiumDataCategoryCinematic.h"
#include "CompendiumDataCategoryEnemy.h"
#include "CompendiumDataCategoryGadget.h"
#include "CompendiumDataCategoryItem.h"
#include "CompendiumDataCategoryLevel.h"
#include "CompendiumDataCategoryPerk.h"
#include "CompendiumDataCategoryStory.h"
#include "CompendiumDataCategoryWeapon.h"
#include "CompendiumHistory.h"
#include "Compendium.generated.h"

USTRUCT(BlueprintType)
struct FCompendium {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCompendiumDataCategoryWeapon WeaponDatas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCompendiumDataCategoryEnemy EnemyDatas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCompendiumDataCategoryItem ItemDatas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCompendiumDataCategoryPerk PerkDatas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCompendiumDataCategoryCinematic CinematicDatas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCompendiumDataCategoryGadget GadgetDatas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCompendiumDataCategoryLevel LevelDatas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCompendiumDataCategoryStory StoryDatas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCompendiumHistory HistoryDatas;
    
    ROBOQUEST_API FCompendium();
};

