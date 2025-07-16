#include "Stat.h"

FStat::FStat() {
    this->StatEnum = EStat::Health;
    this->InitialCurrentValue = ECurrentValueStat::Full;
    this->Value = 0.00f;
    this->Reliquat = 0.00f;
}

