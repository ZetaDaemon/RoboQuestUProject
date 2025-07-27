#include "SkillDataAsset.h"

USkillDataAsset::USkillDataAsset() {
    this->DT_PlayerSkills = NULL;
    this->DT_EnemySkill = NULL;
    this->DT_AllySkill = NULL;
    this->DT_ModSkills = NULL;
    this->ExplosionFXQueueDuration = 0.20f;
    this->DefaultExplosionFXQueueRadius = 100.00f;
    this->ExplosionFXQueueCurve = NULL;
    this->ExplosionByElement[0] = NULL;
    this->ExplosionByElement[1] = NULL;
    this->ExplosionByElement[2] = NULL;
    this->TrailByElement[0] = NULL;
    this->TrailByElement[1] = NULL;
    this->TrailByElement[2] = NULL;
    this->ProjectileParticleByElement[0] = NULL;
    this->ProjectileParticleByElement[1] = NULL;
    this->ProjectileParticleByElement[2] = NULL;
    this->ProjectileTrailByElement[0] = NULL;
    this->ProjectileTrailByElement[1] = NULL;
    this->ProjectileTrailByElement[2] = NULL;
    this->BashByElement[0] = NULL;
    this->BashByElement[1] = NULL;
    this->BashByElement[2] = NULL;
    this->CurveFallOffDamage = NULL;
    this->CurveFallOffImpactForce = NULL;
    this->CurveAreaBoneFallOff = NULL;
}


