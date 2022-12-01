#include "Platform/PlatformPinout.hpp"
#include "Hardware/Analog/Analog.hpp"
#include "Hardware/Relay/Relay.hpp"
#include "Hardware/DAC/MCP4922.hpp"
#include "State/ControllerState.hpp"
#include "Core/Orchestrator.hpp"

int main() {
    /**
     * Initialize hardware
     */

    // Pico
    stdio_init_all();

    // CAN
    // TODO: Implement interface


    // Analog
    Analog adc;
    adc.init();

    // DAC
    MCP4922 dac(spi0, PlatformPinout::DAC_CS_PIN, PlatformPinout::DAC_TX_PIN, PlatformPinout::DAC_SCK_PIN, PlatformPinout::DAC_LDAC_PIN);
    dac.init();

    // Relay
    Relay relay(PlatformPinout::GPIO_RELAY_PIN);
    relay.init();

    // LED
    Relay led(PlatformPinout::LED_PIN);
    led.init();
    led.setState(true);

    /**
     * Global variables
     */

    // Controller State
    ControllerState state;

    // Error handler

    /**
     * Orchestrator
     */

    // Initialize orchestrator
    Orchestrator orchestrator;
    orchestrator.init();

    // Run auxiliary orchestrator thread (CAN + USB communication)
    orchestrator.handleCommunication();

    // Run main orchestrator thread (calculations, safety, outputs)
    orchestrator.handleMainTasks();

    return 0;
}