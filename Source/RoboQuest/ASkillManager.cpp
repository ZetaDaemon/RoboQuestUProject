#include "ASkillManager.h"
#include "Templates/SubclassOf.h"

UASkillManager::UASkillManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CharacterOwner = NULL;
    this->bAutoLoadSkill = true;
}

void UASkillManager::SwapSkillInput(EAction Action1, EAction Action2) {
}

void UASkillManager::RemoveSkillInput(EAction Action) {
}

void UASkillManager::RemoveSkill(TSubclassOf<UASkill> NewSkill) {
}

void UASkillManager::OnNotifySkillUsed(UASkill* Skill, bool bIsStarting) {
}

void UASkillManager::OnNotifySkillTagUpdate(UASkill* Skill) {
}

void UASkillManager::OnNotifySkillStackUpdate(EAction TargetAction, int32 CurrentStack) {
}

void UASkillManager::OnNotifySkillPostUsed(UASkill* Skill) {
}

void UASkillManager::OnNotifySkillNoCost(EAction TargetAction) {
}

void UASkillManager::OnNotifySkillCancel(EAction TargetAction) {
}

void UASkillManager::OnNotifySkillAvailable(EAction TargetAction) {
}

void UASkillManager::OnNotifySkillAnimNotify() {
}

void UASkillManager::OnEndLoadSkillAsset(EAction Action, TSoftClassPtr<UASkill> SoftClass) {
}

void UASkillManager::LoadSkillAssets(const TMap<EAction, TSoftClassPtr<UASkill>>& SkillAssets) {
}

bool UASkillManager::CanPressedSkill(UASkill* Skill) const {
    return false;
}

void UASkillManager::AddSkillInput(FSkillInputBP SkillInput) {
}

void UASkillManager::AddSkill(TSubclassOf<UASkill> NewSkill) {
}


