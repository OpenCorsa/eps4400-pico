#pragma once

#include <iostream>
#include "JsonFormatter.hpp"

class SerialOutput : public JsonFormatter {
protected:

    /**
     * Output JSON format to serial
     *
     * @param state
     */
    void outputHandler(ControllerState state) {
        std::cout << this->formatJson(state) << "\n" << std::flush;
    }
};