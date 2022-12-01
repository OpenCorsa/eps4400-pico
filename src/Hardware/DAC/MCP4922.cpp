#include "MCP4922.hpp"

/**
 *
 * @param spi
 * @param cs
 * @param tx
 * @param sck
 * @param latch
 * @param spiClock
 */
MCP4922::MCP4922(spi_inst_t *spi, uint8_t cs, uint8_t tx, uint8_t sck, uint8_t latch, uint32_t spiClock) {
    this->spi = spi;
    this->cs = cs;
    this->tx = tx;
    this->sck = sck;
    this->latch = latch;
    this->spiClock = spiClock;
}

/**
 *
 */
bool MCP4922::init() {
    spi_init(this->spi, this->spiClock);
    gpio_set_function(this->tx, GPIO_FUNC_SPI);
    gpio_set_function(this->sck, GPIO_FUNC_SPI);
    gpio_set_function(this->cs, GPIO_FUNC_SPI);
    spi_set_format(this->spi, 8, SPI_CPOL_1, SPI_CPHA_1, SPI_MSB_FIRST);

    gpio_init(this->latch);
    gpio_set_dir(this->latch, GPIO_OUT);
    gpio_put(this->latch, 1); // Set high

    return true;
}

/**
 *
 * @param channelA
 * @param channelB
 */
void MCP4922::set(uint16_t channelA, uint16_t channelB) {
    uint8_t data[2];

    // Set channel A, Buffered, 1x Gain, Enabled
    channelA = std::min(channelA, (uint16_t) 4095);
    data[0] = (uint8_t)(0b01110000 | (channelA & 0xF00) >> 8);
    data[1] = (uint8_t)(channelA & 0xFF);
    spi_write_blocking(this->spi, data, 2);

    // Set channel B, Buffered, 1x Gain, Enabled
    channelB = std::min(channelB, (uint16_t) 4095);
    data[0] = (uint8_t)(0b11110000 | (channelB & 0xF00) >> 8);
    data[1] = (uint8_t)(channelB & 0xFF);
    spi_write_blocking(this->spi, data, 2);

    // Trigger synchronous output update
    gpio_put(this->latch, 0);
    sleep_us(1); // 100ns required, 1000ns provided
    gpio_put(this->latch, 1);
}