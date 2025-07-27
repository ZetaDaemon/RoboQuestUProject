#include "ALightSource.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=PointLightComponent -FallbackName=PointLightComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "Components/StaticMeshComponent.h"

AALightSource::AALightSource(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AALightSource::SetLightScenario(const FName& LightScenarioName) {
}


