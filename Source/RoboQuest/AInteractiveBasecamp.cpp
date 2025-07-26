#include "AInteractiveBasecamp.h"

AAInteractiveBasecamp::AAInteractiveBasecamp(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Camera = NULL;
}

void AAInteractiveBasecamp::UpdatePrimitiveComponents() {
}

FString AAInteractiveBasecamp::GetMeshesPrefix_Implementation() const {
    return TEXT("");
}


