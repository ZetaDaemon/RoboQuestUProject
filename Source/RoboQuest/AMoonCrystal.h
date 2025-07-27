#pragma once
#include "CoreMinimal.h"
#include "AMoonCrystalBeam.h"
#include "AMoonCrystal.generated.h"

class UStaticMeshComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AAMoonCrystal : public AAMoonCrystalBeam {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* BaseTop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* BaseBottom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* Crystal;
    
    AAMoonCrystal(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnCrystalMeshLoaded();
    
};

