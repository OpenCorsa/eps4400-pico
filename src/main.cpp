#include "Platform/PlatformPinout.hpp"
#include "Hardware/CAN/Can.hpp" // Replace with implementation
#include "Hardware/Analog/Analog.hpp"
#include "Hardware/Relay/Relay.hpp"
#include "Hardware/DAC/MCP4922.hpp"
#include "State/StateManager.hpp"

#include "Output/CanOutput.hpp"
#include "Output/SerialOutput.hpp"

#include "pico/multicore.h"

#include <iostream>

// Define main worker functions
void handleCommunication();

void handleMainTasks();

// Define global variables
Can can;
Analog adc;
MCP4922 dac(spi0, PlatformPinout::DAC_CS_PIN, PlatformPinout::DAC_TX_PIN, PlatformPinout::DAC_SCK_PIN, PlatformPinout::DAC_LDAC_PIN);
Relay relay(PlatformPinout::GPIO_RELAY_PIN);
Relay led(PlatformPinout::LED_PIN);
StateManager manager;

/**
 *
 * @return
 */
int main() {
    /**
     * Initialize hardware
     */

    // Pico
    stdio_init_all();

   // CAN
   // TODO

   // Analog
   adc.init(); // TODO: Refactor & make generic interface

   // DAC
   dac.init();

   // Relay
   relay.init();

   // LED
   Relay led(PlatformPinout::LED_PIN);
   led.init();
   led.setState(true);

   /**
    * Global variables
    */

   // Controller State
   // TODO

   // Error handler
   // TODO: Implement

    /**
     * Orchestration
     */

    // Run auxiliary orchestrator on Core #1 (CAN + USB communication)
    multicore_launch_core1(handleCommunication);

    // Run main orchestrator on Core #0 (calculations, safety, outputs)
    handleMainTasks();

    return 0;
}

/**
 * Main orchestrator (calculations, safety, outputs)
 */
void handleMainTasks() {
    // Infinite worker loop
    while (true) {
        // Get state
        auto state = manager.getStateSnapshot();

        // Monitor driver's torque
        // TODO: Future

        // Calculations
        // TODO: Implement in the future angle to torque converter

        // Safety features
        // TODO: Future

        // Dac control
        // TODO

        // Relay
        // TODO

        // Watchdog?
        // TODO: Future
    }
}

/**
 * Auxiliary orchestrator (CAN + USB communication)
 */
void handleCommunication() {
    // Register output handlers
    CanOutput canOutput(can);
    SerialOutput serialOutput;

    // Infinite worker loop
    while (true) {
        // Get state
        auto state = manager.getStateSnapshot();

        // Read CAN

        // Handle frame

        //      (update state - active/mode/setpoint)

        //      (firmware update - call reset_usb_boot(0, 0) )

        //      (calibrate)

        //      (frame safety analysis)

        // Outputs (Serial, CAN)
        canOutput.output(state);
        serialOutput.output(state);
    }
}