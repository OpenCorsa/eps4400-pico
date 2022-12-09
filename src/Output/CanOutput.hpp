#pragma once

#include "Output.hpp"
#include "../Hardware/CAN/Can.hpp"

class CanOutput : public Output {
protected:
    Can interface;

    /**
     *
     * @param state
     */
    void outputHandler(ControllerState state) {
        // Create new frame

        // Send
        //this->interface->send()
    };
    
public:

    /**
     *
     * @param interface
     */
    CanOutput(Can interface) {
        this->interface = interface;
    };
};