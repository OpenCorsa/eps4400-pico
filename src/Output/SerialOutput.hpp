#pragma once

#include <iostream>
#include "Output.hpp"

class SerialOutput : public Output {

public:
    void output(ControllerState state);

};