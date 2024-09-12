/**
 * @file vex.cpp
 * @author Alex Ye (albertexye@gmail.com)
 * @brief Instantiating the vex devices
 * @version 0.1
 * @date 2024-09-11
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "vex.h"
#include "config.h"

namespace Global {
    vex::competition competition{};
    vex::brain brain{};
    /* the motors' port numbers are 1 greater than the port indexes */
    vex::motor left_motor1{ LEFT_MOTOR_1_PORT - 1, vex::gearSetting::ratio18_1, false };
    vex::motor left_motor2{ LEFT_MOTOR_2_PORT - 1, vex::gearSetting::ratio18_1, false };
    vex::motor left_motor3{ LEFT_MOTOR_3_PORT - 1, vex::gearSetting::ratio18_1, false };
    vex::motor right_motor1{ RIGHT_MOTOR_1_PORT - 1, vex::gearSetting::ratio18_1, false };
    vex::motor right_motor2{ RIGHT_MOTOR_2_PORT - 1, vex::gearSetting::ratio18_1, false };
    vex::motor right_motor3{ RIGHT_MOTOR_3_PORT - 1, vex::gearSetting::ratio18_1, false };
}
