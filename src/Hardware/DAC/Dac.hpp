#pragma once

class Dac {
public:
    virtual bool init();

    virtual void set(uint16_t channelA, uint16_t channelB);
};