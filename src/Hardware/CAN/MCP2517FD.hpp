#pragma once

#include "Can.hpp"
#include "hardware/spi.h"
#include "mcp2518fd/mcp2518fd_can.h"

class MCP2517FD : public Can {
protected:
    spi_inst_t *spi;
    uint32_t spiClock;

    uint8_t cs;
    uint8_t rx;
    uint8_t tx;
    uint8_t sck;

    // TODO: Rewrite functionalities & remove dependency
    mcp2518fd *instance;

public:
    MCP2517FD(
            spi_inst_t *spi = spi0,
            uint8_t cs = PICO_DEFAULT_SPI_CSN_PIN,
            uint8_t rx = PICO_DEFAULT_SPI_RX_PIN,
            uint8_t tx = PICO_DEFAULT_SPI_TX_PIN,
            uint8_t sck = PICO_DEFAULT_SPI_SCK_PIN,
            uint32_t spiClock = 10 * 1000 * 1000 // TODO: Test 40mhz crystal & 20MHz SPI
    );

    bool init();

    bool begin(uint32_t speed);

    bool read(can_frame *rx);

    bool send(can_frame *tx);
};