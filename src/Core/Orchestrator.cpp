#include "Orchestrator.hpp"

/*
 *
 */
bool Orchestrator::init() {
    return true;
}

/*
 *
 */
void Orchestrator::handleCommunication() {
    // TODO: Figure out how to share hardware pointers between cores
    multicore_launch_core1([]() {
        while (true) {
            std::cout << "Running from lambda on other core\n";
            sleep_ms(1000);
        }
    });
}

/**
 *
 */
void Orchestrator::handleMainTasks() {
    while (true) {
        std::cout << "Main thread!\n";
        sleep_ms(500);
    }
}