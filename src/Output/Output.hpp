#pragma once

#include <stdint.h>
#include "pico/time.h"
#include "../State/ControllerState.hpp"

class Output {
protected:
    uint32_t delayMilliseconds = 100;
    absolute_time_t lastOutput = nil_time;

    virtual void outputHandler(ControllerState state);

    bool shouldOutput();

public:
    void output(ControllerState state);
};