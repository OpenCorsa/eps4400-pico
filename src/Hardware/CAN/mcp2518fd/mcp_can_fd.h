#ifndef _MCP_CAN_H_
#define _MCP_CAN_H_

#include <inttypes.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "pico/time.h"
#include "pico/stdlib.h"
#include "boards/pico.h"


#define CAN_OK              (0)
#define CAN_FAILINIT        (1)
#define CAN_FAILTX          (2)
#define CAN_MSGAVAIL        (3)
#define CAN_NOMSG           (4)
#define CAN_CTRLERROR       (5)
#define CAN_GETTXBFTIMEOUT  (6)
#define CAN_SENDMSGTIMEOUT  (7)
#define CAN_FAIL            (0xff)

// clock
typedef enum {
    MCP_NO_MHz,
    /* apply to MCP2515 */
    MCP_16MHz,
    MCP_8MHz,
    /* apply to MCP2518FD */
    MCP2518FD_40MHz = MCP_16MHz /* To compatible MCP2515 shield */,
    MCP2518FD_20MHz,
    MCP2518FD_10MHz,
} MCP_CLOCK_T;

typedef enum {
    CAN_NOBPS,
    CAN20_5KBPS,
    CAN20_10KBPS,
    CAN20_20KBPS,
    CAN20_25KBPS,
    CAN20_31K25BPS,
    CAN20_33KBPS  ,
    CAN20_40KBPS  ,
    CAN20_50KBPS  ,
    CAN20_80KBPS  ,
    CAN20_83K3BPS ,
    CAN20_95KBPS  ,
    CAN20_100KBPS ,
    CAN20_125KBPS ,
    CAN20_200KBPS ,
    CAN20_250KBPS ,
    CAN20_500KBPS ,
    CAN20_666KBPS ,
    CAN20_800KBPS ,
    CAN20_1000KBPS
} MCP_BITTIME_SETUP;


class MCP_CAN_1
{
public:
    virtual void enableTxInterrupt(bool enable = true) = 0;                             // enable transmit interrupt
    virtual void reserveTxBuffers(uint8_t nTxBuf = 0) = 0;
    virtual uint8_t getLastTxBuffer() = 0;
    /*
     * speedset be in MCP_BITTIME_SETUP
     * clockset be in MCP_CLOCK_T
     */
    virtual uint8_t begin(uint32_t speedset, const uint8_t clockset) = 0;                     // init can
    virtual void setSleepWakeup(uint8_t enable) = 0;                                       // Enable or disable the wake up interrupt
                                         // (If disabled the MCP2515 will not be woken up by CAN bus activity, making it send only)
    virtual uint8_t sleep() = 0;                                                           // Put the MCP2515 in sleep mode
    virtual uint8_t wake() = 0;                                                            // Wake MCP2515 manually from sleep
    virtual uint8_t __setMode(uint8_t opMode) = 0;                                              // Set operational mode
    virtual uint8_t getMode() = 0;                                                         // Get operational mode
    virtual uint8_t checkError(uint8_t* err_ptr = NULL) = 0;                               // if something error

    /* ---- receiving ---- */
    virtual uint8_t checkReceive(void) = 0;                                                // if something received
    virtual uint8_t readMsgBufID(uint8_t status,
                              volatile unsigned long *id, volatile uint8_t *ext, volatile uint8_t *rtr,
                              volatile uint8_t *len, volatile uint8_t *buf) = 0;              // read buf with object ID
    /* wrapper */
    virtual uint8_t readMsgBufID(unsigned long *ID, uint8_t *len, uint8_t *buf) = 0;
    virtual uint8_t readMsgBuf(uint8_t *len, uint8_t *buf) = 0;
    
    /* could be called after a successful readMsgBufID() */
    unsigned long getCanId(void) { return can_id; }
    uint8_t isRemoteRequest(void)   { return rtr;    }
    uint8_t isExtendedFrame(void)   { return ext_flg;}

    /* ---- sending ---- */
    virtual uint8_t trySendMsgBuf(unsigned long id, uint8_t ext, uint8_t rtr,
                               uint8_t len, const uint8_t *buf, uint8_t iTxBuf = 0xff) = 0;      // as sendMsgBuf, but does not have any wait for free buffer
    virtual uint8_t sendMsgBuf(uint8_t status, unsigned long id, uint8_t ext, uint8_t rtr,
                               uint8_t len, volatile const uint8_t *buf) = 0;                 // send message buf by using parsed buffer status
    virtual uint8_t sendMsgBuf(unsigned long id, uint8_t ext, uint8_t rtrBit,
                               uint8_t len, const uint8_t *buf, bool wait_sent = true) = 0;   // send message with wait

    virtual void clearBufferTransmitIfFlags(uint8_t flags = 0) = 0;                        // Clear transmit flags according to status
    virtual uint8_t readRxTxStatus(void) = 0;                                              // read has something send or received
    virtual uint8_t checkClearRxStatus(uint8_t *status) = 0;                                  // read and clear and return first found rx status bit
    virtual uint8_t checkClearTxStatus(uint8_t *status, uint8_t iTxBuf = 0xff) = 0;              // read and clear and return first found or buffer specified tx status bit
    virtual bool mcpPinMode(const uint8_t pin, const uint8_t mode) = 0;                       // switch supported pins between HiZ, interrupt, output or input
    virtual bool mcpDigitalWrite(const uint8_t pin, const uint8_t mode) = 0;                  // write HIGH or LOW to RX0BF/RX1BF
    virtual uint8_t mcpDigitalRead(const uint8_t pin) = 0;                                    // read HIGH or LOW from supported pins

public:
    MCP_CAN_1(uint8_t _CS);
    void init_CS(uint8_t _CS); // define CS after construction before begin()
    void setSPI(spi_inst_t *_pSPI);

protected:
    uint8_t ext_flg; // identifier xxxID
    // either extended (the 29 LSB) or standard (the 11 LSB)
    unsigned long can_id; // can id
    uint8_t rtr;             // is remote frame
    uint8_t SPICS;
    spi_inst_t *pSPI;
    uint8_t mcpMode;     // Current controller mode
};

#endif
