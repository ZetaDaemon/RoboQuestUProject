#include "AMetaReward.h"

UAMetaReward::UAMetaReward() {
    this->PlayerRef = NULL;
    this->ControllerRef = NULL;
}

void UAMetaReward::OnBuy_Implementation() {
}

void UAMetaReward::OnApply_Implementation() {
}

float UAMetaReward::GetCustomFloatValue(FName PropertyName) {
    return 0.0f;
}


