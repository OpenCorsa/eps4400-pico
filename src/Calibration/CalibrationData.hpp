#pragma once

#include <stdint.h>
#include <cmath>
#include <cstring>

/**
 * Overall class size has to be lower than FLASH_PAGE_SIZE (256 bytes)
 */
class CalibrationData {
protected:
    // Random static value used for checksum calculation
    const static uint32_t secret = 0x57CFA1D7;

public:
    // Power steering voltages
    uint32_t epsVoltageChannelA;
    uint32_t epsVoltageChannelB;
    uint32_t epsVoltageRef;

    // TODO: Determine controller & variables
//    // PID controller coefficients
//    float pidCoefficientKp;
//    float pidCoefficientKi;
//    float pidCoefficientKd;

    // Object checksum
    uint32_t checksum;

    uint32_t generateChecksum();

    bool isValid();
};

