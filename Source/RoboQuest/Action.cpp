#include "Action.h"

FAction::FAction() {
    this->RecordType = EInputRecordType::None;
    this->RecordTime = 0.00f;
    this->pressedAction = EAction::PrimaryFire;
}

