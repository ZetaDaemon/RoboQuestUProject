#include "Request_Game.h"

FRequest_Game::FRequest_Game() {
    this->Time = 0.00f;
    this->PlayerLevel = 0;
    this->Kill = 0;
    this->Victory = false;
    this->CenterCrosshair = false;
    this->SprintMode = 0;
    this->Sensitivity = 0.00f;
    this->GamepadSensitivity = 0.00f;
    this->Volume = 0.00f;
    this->DeathType = 0;
    this->rank = 0;
    this->Multiplayer = false;
}

