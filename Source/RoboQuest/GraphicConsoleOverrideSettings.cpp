#include "GraphicConsoleOverrideSettings.h"

FGraphicConsoleOverrideSettings::FGraphicConsoleOverrideSettings() {
    this->bOverrideTextureQuality = false;
    this->Texture = ESettingsQuality::Low;
    this->bOverrideAnistropy = false;
    this->Anisotropy = EAnisotropy::Off;
    this->bOverrideAntiAlliasing = false;
    this->AntiAliasing = EAntiAlliasing::Off;
    this->bOverrideFXAAQuality = false;
    this->FXAA = 0;
    this->bOverrideTemporalAAQuality = false;
    this->TemporalAA = 0;
    this->bOverrideShadowQuality = false;
    this->Shadow = ESettingsQualityWithOff::Off;
    this->bOverrideOcclusionQuality = false;
    this->Occlusion = ESettingsQuality::Low;
    this->bOverrideEffectQuality = false;
    this->Effect = ESettingsQuality::Low;
    this->bOverridePostProcessQuality = false;
    this->PostProcess = ESettingsQuality::Low;
    this->bOverrideRagdoll = false;
    this->Ragdoll = ESettingsQualityWithOff::Off;
}

