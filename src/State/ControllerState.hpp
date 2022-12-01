#pragma once

#include "ControlMode.hpp"

class ControllerState {
protected:

    // Operating state
    bool active;
    ControlMode mode;

    // Torque
    float commandedTorque;
    float driverTorque;

    // Angle
    float commandedAngle;
    float currentAngle;

    // Vehicle general
    float vehicleSpeed;
};