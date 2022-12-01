#include "CalibrationProvider.hpp"

const uint8_t* CalibrationProvider::flashContents = reinterpret_cast<const uint8_t *>(XIP_BASE + flashOffset);

/**
 * Casts raw memory pointer into CalibrationData instance
 *
 * @return Calibration data
 */
CalibrationData CalibrationProvider::getCalibrationData() {
    return *reinterpret_cast<CalibrationData *>(
            const_cast<uint8_t *>(CalibrationProvider::flashContents)
    );
}

/**
 * @param data
 * @return success / failure
 */
bool CalibrationProvider::updateCalibrationData(CalibrationData data) {
    // Create empty flash page
    uint8_t page[FLASH_PAGE_SIZE] = {};

    // Copy calibration data
    std::memcpy(&page, &data, sizeof(data));

    // Disable interrupts to prevent corrupting flash
    uint32_t ints = save_and_disable_interrupts();

    // Erase flash sector (4096 bytes)
    flash_range_erase(CalibrationProvider::flashOffset, 1 * FLASH_SECTOR_SIZE);

    // Program flash page (256 bytes)
    flash_range_program(CalibrationProvider::flashOffset, page, FLASH_PAGE_SIZE);

    // Restore interrupts
    restore_interrupts(ints);

    // Verify save
    return std::memcmp(page, CalibrationProvider::flashContents, FLASH_PAGE_SIZE) == 0;
}