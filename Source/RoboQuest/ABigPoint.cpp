#include "ABigPoint.h"

AABigPoint::AABigPoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->SelfIcon = NULL;
    this->IndieIcon = NULL;
    this->Type = EBigPointType::LevelGeneratorOnly;
}


