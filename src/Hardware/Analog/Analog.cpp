#include "Analog.hpp"

/**
 * Pin -> ADC channel mapping
 */
std::map <uint16_t, uint16_t> Analog::pinMap = {
        {26, 0},
        {27, 1},
        {28, 2},
};

/**
 *
 * @return
 */
bool Analog::init() {
    adc_init();

    // Initialize all channels
    adc_gpio_init(26);
    adc_gpio_init(27);
    adc_gpio_init(28);

    return true;
}

/**
 *
 * @param pin
 * @param sampleCount
 * @return
 */
uint16_t Analog::samplePin(uint16_t pin, uint32_t sampleCount) {
    uint16_t channel = Analog::pinMap.at(pin);
    return Analog::sampleChannel(channel, sampleCount);
}


/**
 *
 * @param channel
 * @param sampleCount
 * @return
 */
uint16_t Analog::sampleChannel(uint16_t channel, uint32_t sampleCount) {
    // Select ADC MUX channel
    adc_select_input(channel);

    // Has to be lower than around 10^6
    sampleCount = std::max(sampleCount, UINT32_MAX / 4096);

    uint32_t temp = 0;

    // Get average of n samples to reduce supply noise
    for (auto i = 0; i < sampleCount; i++) {
        temp += adc_read();
    }

    return temp / sampleCount;
}