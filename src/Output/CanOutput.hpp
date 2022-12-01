#pragma once

#include "Output.hpp"
#include "../Hardware/CAN/Can.hpp"

class CanOutput : public Output {
protected:
    Can interface;

public:
    CanOutput(Can);

    void output(ControllerState state) override;
};