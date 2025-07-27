#pragma once
#include "CoreMinimal.h"
#include "AInteractive.h"
#include "AInteractiveStory.generated.h"

class UParticleSystemComponent;

UCLASS(Blueprintable)
class ROBOQUEST_API AAInteractiveStory : public AAInteractive {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName StoryRowName;
    
    AAInteractiveStory(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetStoryRowName(const FName& RowName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlueprintSetStoryRowName(const FName& RowName, bool bStoryAlreadyUnlocked);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintPure)
    UParticleSystemComponent* GetParticleSystemComponent() const;
    
};

