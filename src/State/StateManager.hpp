#pragma once

#include "ControllerState.hpp"

class StateManager {
protected:
    static ControllerState state;

public:

    /**
     *
     * @return
     */
    ControllerState getStateSnapshot() {
        return this->state;
    }

    /**
     *
     * @param active
     */
    void setActive(bool active) {
        this->state.active = active;
    }

    /**
     *
     */
    void requestSuspend() {
        this->state.suspendRequested = true;
    }

    /**
     *
     * @param mode
     */
    void setMode(ControlMode mode) {
        this->state.mode = mode;
    }

    /**
     *
     * @param torque
     */
    void setCommandedTorque(float torque) {
        this->state.commandedTorque = torque;
    }

    /**
     *
     * @param torque
     */
    void setDriverTorque(float torque) {
        this->state.driverTorque = torque;
    }

    /**
     *
     * @param angle
     */
    void setCommandedAngle(float angle) {
        this->state.commandedAngle = angle;
    }

    /**
     *
     * @param angle
     */
    void setCurrentAngle(float angle) {
        this->state.currentAngle = angle;
    }

    /**
     *
     * @param speed
     */
    void setVehicleSpeed(float speed) {
        this->state.vehicleSpeed = speed;
    }
};