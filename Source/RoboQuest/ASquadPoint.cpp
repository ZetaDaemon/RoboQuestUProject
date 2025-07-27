#include "ASquadPoint.h"

AASquadPoint::AASquadPoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PointType = ESquadPointType::Normal;
    this->bForceCenterEncounter = false;
    this->PointTag = ESquadPointTag::LastIndex;
    this->bIsInConnector = true;
    this->ConnectorDirection = EDirection::LastIndex;
}


