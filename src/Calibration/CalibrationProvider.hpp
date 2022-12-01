#pragma once

#include <cstring>
#include <hardware/flash.h>
#include <hardware/sync.h>
#include "CalibrationData.hpp"

class CalibrationProvider {
protected:
    static const uint32_t flashOffset = 1792 * 1024; // The last 1.8MB out of 2MB flash total
    static const uint8_t *flashContents;

public:
    static CalibrationData getCalibrationData();

    static bool updateCalibrationData(CalibrationData data);

    // TODO: Provide fallback data

    // TODO: Method for getting either valid calibration or fallback
};