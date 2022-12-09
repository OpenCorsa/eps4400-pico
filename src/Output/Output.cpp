#include "Output.hpp"

/**
 *
 * @return
 */
bool Output::shouldOutput() {
    auto us = absolute_time_diff_us(this->lastOutput, get_absolute_time());
    auto ms = us / 1000;
    return ms >= this->delayMilliseconds;
}

/**
 *
 * @param state
 */
void Output::output(ControllerState state) {
    // Check whether output is necessary
    if(this->shouldOutput() == false) {
        return;
    }

    this->lastOutput = get_absolute_time();
    this->outputHandler(state);
}