#include "CalibrationData.hpp"

/**
 * @return
 */
uint32_t CalibrationData::generateChecksum() {
    // Size of object without checksum
    const uint32_t byteCount = sizeof(*this) - sizeof(uint32_t);
    const int arraySize = ceil(byteCount / sizeof(uint32_t));

    uint32_t tempData[arraySize] = {};
    std::memcpy(&tempData, this, byteCount);

    uint32_t checksum = 0;
    for (auto i = 0; i < arraySize; i++) {
        checksum += tempData[i] xor CalibrationData::secret;
    }

    return checksum;
}

/**
 *
 * @return
 */
bool CalibrationData::isValid() {
    return this->checksum == generateChecksum();
}
