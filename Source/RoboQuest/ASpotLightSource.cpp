#include "ASpotLightSource.h"
#include "Components/SpotLightComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SpotLightComponent -FallbackName=SpotLightComponent

AASpotLightSource::AASpotLightSource(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<USpotLightComponent>(TEXT("LightSource"))) {
}


