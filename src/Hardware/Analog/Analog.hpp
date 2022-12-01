#pragma once

#include <map>
#include "hardware/adc.h"

class Analog {
    static std::map <uint16_t, uint16_t> pinMap;

public:
    static const uint32_t shortSample = 16;
    static const uint32_t longSample = 2048;

    bool init();

    static uint16_t samplePin(uint16_t pin, uint32_t sampleCount = shortSample);

    static uint16_t sampleChannel(uint16_t channel, uint32_t sampleCount = shortSample);

    // TODO: Sample n pins at once to minimize noise effects on one channel
    // Method to sample i.e. Channel A & channel B at the same time (round robin)
};