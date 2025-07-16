#include "RQDamageInfo.h"

FRQDamageInfo::FRQDamageInfo() {
    this->Actor = NULL;
    this->Damage = 0.00f;
    this->ImpactForce = 0.00f;
    this->FalloffRatio = 0.00f;
    this->DamageType = EDamageType::Bullet;
    this->RagdollType = EKillRagdollType::Low;
    this->BoneType = EBonesType::None;
    this->Skill = NULL;
    this->Instigator = NULL;
    this->GameplayTags = 0;
    this->SuperFeedbackAmount = 0;
    this->MegaFeedbackAmount = 0;
    this->FloatingTextAmount = 0;
    this->bAutoCritical = false;
    this->bHaveElementalResistance = false;
    this->IceRatio = 0.00f;
    this->ShockRatio = 0.00f;
    this->BumpIntensity = EBumpIntensity::None;
}

