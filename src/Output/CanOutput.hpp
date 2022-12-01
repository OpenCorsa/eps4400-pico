#pragma once

#include "Output.hpp"
#include "../Hardware/CAN/Can.hpp"

class CanOutput : public Output {
protected:
    Can interface;

    void outputHandler(ControllerState state);

public:
    CanOutput(Can);
};