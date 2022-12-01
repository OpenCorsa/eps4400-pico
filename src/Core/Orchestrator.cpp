#include "Orchestrator.hpp"

/**
 *
 * @param state
 * @param interface
 * @param adc
 * @param dac
 * @param relay
 */
Orchestrator::Orchestrator(ControllerState *state, Can *interface, Analog *adc, Dac *dac, Relay *relay) {
    this->state = state;
    this->interface = interface;
    this->adc = adc;
    this->dac = dac;
    this->relay = relay;
}

/*
 *
 */
bool Orchestrator::init() {
    return true;
}

/*
 *
 */
void Orchestrator::handleCommunication() {
    // TODO: Figure out how to share hardware pointers between cores
    multicore_launch_core1([]() {
        // Infinite worker loop
        while (true) {
            // Read CAN

            // Handle frame

            //      (update state - active/mode/setpoint)

            //      (calibrate)

            //      (frame safety analysis)

            // Outputs (Serial & CAN)

            std::cout << "Running from lambda on other core\n";
            sleep_ms(1000);
        }
        1
    });
}

/**
 *
 */
void Orchestrator::handleMainTasks() {
    // Infinite worker loop
    while (true) {

        // Calculations

        // Safety features

        // Dac control

        // Relay

        // Watchdog?

        // Print for now
        std::cout << "Main thread!\n";
        sleep_ms(500);
    }
}