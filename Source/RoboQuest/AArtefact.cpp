#include "AArtefact.h"

UAArtefact::UAArtefact(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RandomSeed = 0;
    this->bShouldTick = false;
}







void UAArtefact::OnRemove_Implementation() {
}


