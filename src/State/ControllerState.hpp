#pragma once

#include "ControlMode.hpp"

class ControllerState {
public:

    // Operating state
    bool active;
    bool suspendRequested;

    // Control mode
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