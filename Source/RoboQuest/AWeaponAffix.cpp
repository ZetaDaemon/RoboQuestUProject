#include "AWeaponAffix.h"

UAWeaponAffix::UAWeaponAffix() {
    this->WeaponRef = NULL;
    this->BaseRandomSeed = 0;
}

void UAWeaponAffix::OnRemove_Implementation() {
}

void UAWeaponAffix::OnApply_Implementation() {
}

float UAWeaponAffix::GetCustomFloatProperties(FName Name) {
    return 0.0f;
}


