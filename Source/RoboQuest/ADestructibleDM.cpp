#include "ADestructibleDM.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=ApexDestruction -ObjectName=DestructibleComponent -FallbackName=DestructibleComponent

AADestructibleDM::AADestructibleDM(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AADestructibleDM::OnDestroy() {
}

void AADestructibleDM::OnComponentCollisionSettingsChangedEvent(UPrimitiveComponent* ChangedComponent) {
}


