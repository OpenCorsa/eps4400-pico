#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "pico/time.h"
#include "pico/stdlib.h"
#include "boards/pico.h"
#include "mcp_can_fd.h"



/*********************************************************************************************************
** Function name:           MCP_CAN_1
** Descriptions:            Constructor
*********************************************************************************************************/
MCP_CAN_1::MCP_CAN_1(uint8_t _CS)
{
    pSPI = spi0;
    init_CS(_CS);
}

/*********************************************************************************************************
** Function name:           init_CS
** Descriptions:            init CS pin and set UNSELECTED
*********************************************************************************************************/
void MCP_CAN_1::init_CS(uint8_t _CS)
{
    if (_CS == 0)
    {
        return;
    }
    SPICS = _CS;

    gpio_init(SPICS);
    gpio_set_dir(SPICS, GPIO_OUT);  
    gpio_put(SPICS, 1);

    //pinMode(SPICS, OUTPUT);
    //digitalWrite(SPICS, HIGH);
}

void MCP_CAN_1::setSPI(spi_inst_t *_pSPI)
{
    pSPI = _pSPI; // define SPI port to use before begin()
}
