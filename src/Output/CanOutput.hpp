#pragma once

#include "Output.hpp"
#include "../Hardware/CAN/Can.hpp"

class CanOutput : public Output {
protected:
    Can *interface;
    uint32_t delayMilliseconds = 100;

    /**
     *
     * @param state
     */
    void outputHandler(ControllerState state) {
        // Create new frame
        can_frame frame = {
                0x400,
                8,
                {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07}
        };

        this->interface->send(&frame);
    };

public:

    /**
     *
     * @param interface
     */
    CanOutput(Can *interface) {
        this->interface = interface;
    };
};