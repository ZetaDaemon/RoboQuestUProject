#include "PostProcessSubsettings.h"

FPostProcessSubsettings::FPostProcessSubsettings() {
    this->BlurGBuffer = 0;
    this->AmbientOcclusionLevels = 0;
    this->AmbientOcclusionRadiusScale = 0.00f;
    this->DepthOfFieldQuality = 0.00f;
    this->RenderTargetPoolMin = 0;
    this->LensFlareQuality = 0;
    this->SceneColorFringeQuality = 0;
    this->EyeAdaptationQuality = 0;
    this->BloomQuality = 0;
    this->FastBlurThreshold = 0;
    this->UpscaleQuality = 0;
    this->TonemapperGrainQuantization = 0;
}

