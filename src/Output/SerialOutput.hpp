#pragma once

#include <iostream>
#include "Output.hpp"

class SerialOutput : public Output {
protected:
    void outputHandler(ControllerState state);
};