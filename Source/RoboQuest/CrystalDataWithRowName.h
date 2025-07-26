#pragma once
#include "CoreMinimal.h"
#include "CrystalRow.h"
#include "CrystalDataWithRowName.generated.h"

USTRUCT(BlueprintType)
struct FCrystalDataWithRowName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RowName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCrystalRow CrystalRow;
    
    ROBOQUEST_API FCrystalDataWithRowName();
};

