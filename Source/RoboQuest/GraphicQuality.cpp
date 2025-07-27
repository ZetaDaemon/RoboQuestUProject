#include "GraphicQuality.h"

FGraphicQuality::FGraphicQuality() {
    this->Texture = ESettingsQuality::Low;
    this->Anisotropy = EAnisotropy::Off;
    this->AntiAliasing = EAntiAlliasing::Off;
    this->FXAA = 0;
    this->TemporalAA = 0;
    this->Shadow = ESettingsQualityWithOff::Off;
    this->Occlusion = ESettingsQuality::Low;
    this->Effect = ESettingsQuality::Low;
    this->PostProcess = ESettingsQuality::Low;
    this->Ragdoll = ESettingsQualityWithOff::Off;
}

