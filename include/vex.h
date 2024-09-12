/**
 * @file vex.h
 * @author Alex Ye (albertexye@gmail.com)
 * @brief VEX headers and devices
 * @version 0.1
 * @date 2024-09-11
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

/* include the vex library */
#include "v5.h"
#include "v5_vcs.h"

/* vex hardware */
namespace Global {
    /* competition instance, must be here to legally compete */
    extern vex::competition competition;
    /* the vex brain, for SDCard IO, the timer and battery info */
    extern vex::brain brain;
    /* the motors */
    extern vex::motor left_motor1;
    extern vex::motor left_motor2;
    extern vex::motor left_motor3;
    extern vex::motor right_motor1;
    extern vex::motor right_motor2;
    extern vex::motor right_motor3;
}
