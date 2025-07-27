#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase -FallbackName=TableRowBase
#include "Engine/DataTable.h"
#include "ArtefactRow.h"
#include "SArtefact.generated.h"

USTRUCT(BlueprintType)
struct FSArtefact : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FArtefactRow Artefact;
    
    ROBOQUEST_API FSArtefact();
};

