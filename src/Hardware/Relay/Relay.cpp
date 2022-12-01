#include "Relay.hpp"

/**
 *
 * @param pin
 */
Relay::Relay(uint8_t pin) {
    this->pin = pin;
}

/**
 *
 */
void Relay::init() {
    gpio_init(this->pin);
    gpio_set_dir(this->pin, GPIO_OUT);

    this->setState(false);
}

/**
 *
 * @param enabled
 */
void Relay::setState(bool enabled) {
    gpio_put(this->pin, enabled);
}

/**
 *
 * @return
 */
bool Relay::getState() {
    return this->pin;
}