#include "ActionPriority.h"

FActionPriority::FActionPriority() {
    this->currentAction = EAction::PrimaryFire;
    this->havePriority = false;
    this->CancelAction = false;
}

