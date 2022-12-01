#pragma once

#include "hardware/gpio.h"

class Relay {
protected:
    uint8_t pin;
    bool state;

public:
    Relay(uint8_t pin);

    void init();

    void setState(bool enabled);

    bool getState();
};