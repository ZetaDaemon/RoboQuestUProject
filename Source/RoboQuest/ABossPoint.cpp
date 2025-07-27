#include "ABossPoint.h"

AABossPoint::AABossPoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAutoDestroyOnClient = false;
    this->SelfIcon = NULL;
    this->IndieIcon = NULL;
}


