#pragma once

#include "pico/stdlib.h"
#include "pico/multicore.h"

#include "../State/ControllerState.hpp"
#include "../Hardware/CAN/Can.hpp"
#include "../Hardware/Analog/Analog.hpp"
#include "../Hardware/DAC/Dac.hpp"
#include "../Hardware/Relay/Relay.hpp"

#include "../Output/CanOutput.hpp"
#include "../Output/SerialOutput.hpp"

#include <iostream>

class Orchestrator {
protected:
    ControllerState *state;
    Can *interface;
    Analog *adc;
    Dac *dac;
    Relay *relay;

public:
    Orchestrator(ControllerState *state, Can *interface, Analog *adc, Dac *dac, Relay *relay);

    bool init();

    void handleCommunication();

    void handleMainTasks();
};