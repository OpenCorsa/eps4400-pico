#pragma once

#include "Output.hpp"

#define FMT_HEADER_ONLY
#include "../../lib/fmt/include/fmt/format.h"

class JsonFormatter : public Output {
protected:

    /**
     *
     * @param state
     * @return
     */
    std::string formatJson(ControllerState state) {
        return fmt::format(
                "{{ \"active\": {}, \"suspendRequested\": {}, \"mode\": {}, \"commandedTorque\": {:.2f}, \"driverTorque\": {:.2f}, \"commandedAngle\": {:.4f}, \"currentAngle\": {:.4f}, \"vehicleSpeed\": {:.2f} }}",
                state.active,
                state.suspendRequested,
                this->modeToString(state.mode),
                state.commandedTorque,
                state.driverTorque,
                state.commandedAngle,
                state.currentAngle,
                state.vehicleSpeed
        );
    }

    /**
     *
     * @param mode
     * @return
     */
    std::string modeToString(ControlMode mode) {
        if (mode == ControlMode::MODE_ANGLE) {
            return "MODE_ANGLE";
        }

        if (mode == ControlMode::MODE_TORQUE) {
            return "MODE_TORQUE";
        }

        return "MODE_UNKNOWN";
    }
};