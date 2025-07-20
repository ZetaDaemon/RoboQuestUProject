#include "CollectableRowBase.h"

FCollectableRowBase::FCollectableRowBase() {
    this->Type = ECollectableType::Key;
    this->Reward = EPermanentReward::KeyBot;
}

