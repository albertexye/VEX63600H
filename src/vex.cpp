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

namespace Global {
    vex::competition competition{};
    vex::brain brain{};
    vex::motor left_motor1{ 0, vex::gearSetting::ratio18_1, false };
    vex::motor left_motor2{ 0, vex::gearSetting::ratio18_1, false };
    vex::motor left_motor3{ 0, vex::gearSetting::ratio18_1, false };
    vex::motor right_motor1{ 0, vex::gearSetting::ratio18_1, false };
    vex::motor right_motor2{ 0, vex::gearSetting::ratio18_1, false };
    vex::motor right_motor3{ 0, vex::gearSetting::ratio18_1, false };
}
