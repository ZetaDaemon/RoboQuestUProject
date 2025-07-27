#include "MaxAnimation.h"

FMaxAnimation::FMaxAnimation() {
    this->Type = EMaxTextType::Busy;
    this->IdleAnimation = NULL;
    this->AIM = NULL;
    this->bHandTablette = false;
    this->DialogBoxOffset = 0;
}

