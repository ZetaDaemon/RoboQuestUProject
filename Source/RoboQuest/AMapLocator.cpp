#include "AMapLocator.h"

UAMapLocator::UAMapLocator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->WidgetClass = NULL;
    this->Icon = NULL;
    this->Status = EMapLocatorStatus::Both;
    this->OffsetAngle = 0.00f;
    this->bIsStatic = false;
    this->bAbsoluteRotation = false;
    this->bAutoRegister = true;
    this->ZOrder = 0;
    this->bPersistOnDestroy = false;
    this->Widgets[0] = NULL;
    this->Widgets[1] = NULL;
    this->OwningActor = NULL;
    this->LocalController = NULL;
}

void UAMapLocator::UpdateIcon(UTexture2D* NewIcon, FLinearColor NewTintColor, bool bNewAbsoluteRotation, const FVector2D& NewMapSize, const FVector2D& NewMiniMapSize, float NewOffsetAngle, int32 NewZOrder) {
}

void UAMapLocator::UnregisterFromController(bool bIsPermanent) {
}

void UAMapLocator::RegisterToController() {
}

void UAMapLocator::OnOwningActorEndPlay(AActor* Actor, const TEnumAsByte<EEndPlayReason::Type> EndPlayReason) {
}


