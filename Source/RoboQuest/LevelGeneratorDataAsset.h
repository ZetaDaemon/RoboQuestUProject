#pragma once
#include "CoreMinimal.h"
#include "CommonGeneratorDataAsset.h"
#include "FirstTimeMaxText.h"
#include "LootRowHandle.h"
#include "MaxTextRowHandle.h"
#include "Templates/SubclassOf.h"
#include "LevelGeneratorDataAsset.generated.h"

class AAInteractiveStory;
class AATile;
class AActor;
class ACharacter_Enemy;
class UDataTable;

UCLASS(Blueprintable)
class ROBOQUEST_API ULevelGeneratorDataAsset : public UCommonGeneratorDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AAInteractiveStory> InteractiveStoryClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ACharacter_Enemy> KeyBotClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OasisCorruptedDoorTimeLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FieldsCorruptedPortalSpawnPercentChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLootRowHandle FieldsCorruptedPortalRow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CorruptedRuinsArenaHealthPercentModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CorruptedRuinsArenaImpactPercentModifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> CorruptedQuarrySpecialTilesPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NasaDoorTimeLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AATile> MoonBossTileClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ACharacter_Enemy> MoonBossClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* DT_MaxTexts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFirstTimeMaxText> FirstTimeTexts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMaxTextRowHandle> LooseTextsPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMaxTextRowHandle> RandomTextsPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMaxTextRowHandle> RandomBossTextsPool;
    
    ULevelGeneratorDataAsset();

};

