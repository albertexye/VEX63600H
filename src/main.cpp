/**
 * @file main.cpp
 * @author Alex Ye (albertexye@gmail.com)
 * @brief Program entry
 * @version 0.1
 * @date 2024-09-11
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "vex.h"

/**
 * @brief This function gets called at start up.
 * @details It sets up the hardware to a certain state before match.
 */
void setup() {
}

/**
 * @brief This function gets called when autonomous starts.
 * @details It controls the robot to score in autonomous period.
 */
void autonomous() {
}

/**
 * @brief This function gets called when drivercontrol starts
 * @details It receives the driver's input and controls the robot.
 */
void drivercontrol() {
    while (true) {
        vex::wait(20, vex::timeUnits::msec);
    }
}

/**
 * @brief Setup the competition and callbacks
 *
 * @return always 0
 */
int main() {
    // Set up callbacks for autonomous and driver control periods.
    Global::competition.autonomous(autonomous);
    Global::competition.drivercontrol(drivercontrol);

    // Run the pre-autonomous function.
    setup();

    // Prevent main from exiting with an infinite loop.
    while (true) {
        vex::wait(100, vex::timeUnits::msec);
    }

    // unreachable
    return 0;
}
