#include "ReplicationParameters.h"

FReplicationParameters::FReplicationParameters() {
    this->NetUpdateFrequency = 0.00f;
    this->MinNetUpdateFrequency = 0.00f;
    this->NetPriority = 0.00f;
    this->bReplicateMovement = false;
    this->NetDormancy = DORM_Never;
    this->bAlwaysRelevant = false;
}

