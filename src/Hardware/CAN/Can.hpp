#pragma once

#include "CanFrame.h"

class Can {
public:

    virtual bool init();

    virtual bool begin(uint32_t speed);

    virtual bool read(can_frame *rx);

    virtual bool send(can_frame *tx);

};