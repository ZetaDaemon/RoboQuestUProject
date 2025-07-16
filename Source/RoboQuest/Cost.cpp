#include "Cost.h"

FCost::FCost() {
    this->TargetStat = EStat::Health;
    this->targetType = ETargetType::Player;
    this->Cost = 0.00f;
    this->minimalCost = 0.00f;
    this->threshold = 0.00f;
}

