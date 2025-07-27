#include "AShockPodAnimInstance.h"

UAShockPodAnimInstance::UAShockPodAnimInstance() {
    this->bDeployed = false;
    this->bOpeningToOpen = false;
    this->bOpenToClosing = false;
    this->bClosingToClose = false;
}

void UAShockPodAnimInstance::OnUsePrimaryFireSkill(UASkill* Skill, bool bIsStarting) {
}

void UAShockPodAnimInstance::OnPrimaryFireSkillAreaDelay() {
}

void UAShockPodAnimInstance::OnEndInitialization() {
}


