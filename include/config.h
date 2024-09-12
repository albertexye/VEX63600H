/**
 * @file config.h
 * @author Alex Ye (albertexye@gmail.com)
 * @brief Project configuration file
 * @version 0.1
 * @date 2024-09-11
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

/* drivetrain motor ports */
const int LEFT_MOTOR_1_PORT{ 1 };
const int LEFT_MOTOR_2_PORT{ 2 };
const int LEFT_MOTOR_3_PORT{ 3 };
const int RIGHT_MOTOR_1_PORT{ 4 };
const int RIGHT_MOTOR_2_PORT{ 5 };
const int RIGHT_MOTOR_3_PORT{ 6 };

/* auto motor disabling */
// this feature disables the corresponding motor on the other side if a motor disconnects
// however, it may introduce a small delay to the drivetrain
#define ENABLE_AUTO_MOTOR_DISABLING // comment this to disable
