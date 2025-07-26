#include "AInteractiveWidget.h"

AAInteractiveWidget::AAInteractiveWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CurveDistance = NULL;
}

void AAInteractiveWidget::SetWidgetDisplay_Implementation(bool bIsDisplay) {
}

UWidgetComponent* AAInteractiveWidget::GetWidgetComponent_Implementation() const {
    return NULL;
}


