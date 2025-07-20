#pragma once
#include "CoreMinimal.h"
#include "ArtefactRow.h"
#include "ArtefactDataWithRowName.generated.h"

USTRUCT(BlueprintType)
struct FArtefactDataWithRowName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RowName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FArtefactRow ArtefactRow;
    
    ROBOQUEST_API FArtefactDataWithRowName();
};

