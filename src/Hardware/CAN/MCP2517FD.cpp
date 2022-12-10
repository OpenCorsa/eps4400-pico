#include "MCP2517FD.hpp"

/**
 *
 * @param spi
 * @param cs
 * @param rx
 * @param tx
 * @param sck
 * @param spiClock
 */
MCP2517FD::MCP2517FD(spi_inst_t *spi, uint8_t cs, uint8_t rx, uint8_t tx, uint8_t sck, uint32_t spiClock) {
    this->spi = spi;
    this->cs = cs;
    this->rx = rx;
    this->tx = tx;
    this->sck = sck;
    this->spiClock = spiClock;
}

/**
 *
 */
bool MCP2517FD::init() {
    spi_init(this->spi, this->spiClock);
    gpio_set_function(this->rx, GPIO_FUNC_SPI);
    gpio_set_function(this->tx, GPIO_FUNC_SPI);
    gpio_set_function(this->sck, GPIO_FUNC_SPI);
    gpio_set_function(this->cs, GPIO_FUNC_SPI);
    spi_set_format(this->spi, 8, SPI_CPOL_0, SPI_CPHA_0, SPI_MSB_FIRST);

    // TODO: Replace with proper impl
    this->instance = new mcp2518fd(this->cs);
    this->instance->setSPI(this->spi);

    return true;
}


/**
 *
 * @param speed
 * @return
 */
bool MCP2517FD::begin(uint32_t speed) {
    return this->instance->begin(speed) == CAN_OK; // Implicit 20MHZ Osc declaration
}

/**
 *
 * @param rx
 * @return
 */
bool MCP2517FD::read(can_frame *rx) {
    if (this->instance->checkReceive() != CAN_MSGAVAIL) {
        return false;
    }

    // TODO: Replace with proper impl
    this->instance->readMsgBufID((long unsigned int *) &rx->can_id, &rx->can_dlc, rx->data);

    return true;
}

/**
 *
 * @param tx
 * @return
 */
bool MCP2517FD::send(can_frame *tx) {
    return this->instance->sendMsgBuf(tx->can_id, false, tx->can_dlc, tx->data);
}