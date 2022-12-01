#pragma once

#include "../State/ControllerState.hpp"

class Output {
public:
    virtual void output(ControllerState state);

};