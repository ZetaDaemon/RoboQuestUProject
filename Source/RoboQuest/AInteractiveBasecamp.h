#pragma once
#include "CoreMinimal.h"
#include "AInteractive.h"
#include "AInteractiveBasecamp.generated.h"

class ACameraActor;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AAInteractiveBasecamp : public AAInteractive {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACameraActor* Camera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPrimitiveComponent*> PrimitiveComponents;
    
public:
    AAInteractiveBasecamp(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdatePrimitiveComponents();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    FString GetMeshesPrefix() const;
    
};

