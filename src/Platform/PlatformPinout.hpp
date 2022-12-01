#pragma once

#include "boards/pico.h"

enum PlatformPinout {
    GPIO_RELAY_PIN = 8,

    CAN_INT_1_PIN = 9,
    CAN_INT_0_PIN = 10,
    CAN_INT_PIN = 11,
    CAN_TX_PIN = 12,
    CAN_CS_PIN = 13,
    CAN_SCK_PIN = 14,
    CAN_RX_PIN = 15,

    DAC_CS_PIN = 17,
    DAC_SCK_PIN = 18,
    DAC_TX_PIN = 19,
    DAC_LDAC_PIN = 20,

    ADC_TORQUE_A_PIN = 26,
    ADC_TORQUE_B_PIN = 27,
    ADC_TORQUE_VREF_PIN = 28,

    LED_PIN = PICO_DEFAULT_LED_PIN
};