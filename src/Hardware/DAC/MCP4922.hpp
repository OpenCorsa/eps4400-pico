#pragma once

#include <algorithm>
#include "Dac.hpp"
#include "hardware/spi.h"
#include "pico/time.h"
#include "pico/stdlib.h"
#include "boards/pico.h"

class MCP4922 : public Dac {

public:
    MCP4922(
            spi_inst_t *spi = spi0,
            uint8_t cs = PICO_DEFAULT_SPI_CSN_PIN,
            uint8_t tx = PICO_DEFAULT_SPI_TX_PIN,
            uint8_t sck = PICO_DEFAULT_SPI_SCK_PIN,
            uint8_t latch = 20,
            uint32_t spiClock = 1 * 1000 * 1000 // TODO: Test higher speeds
    );

    bool init();

    void set(uint16_t channelA, uint16_t channelB);

private:
    spi_inst_t *spi;
    uint32_t spiClock;

    uint8_t cs;
    uint8_t tx;
    uint8_t sck;
    uint8_t latch;
};
