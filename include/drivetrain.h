/**
 * @file drivetrain.h
 * @author Alex Ye (albertexye@gmail.com)
 * @brief the abstraction of the drivetrain
 * @version 0.1
 * @date 2024-09-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once

#include "vex.h"
#include "config.h"

/**
 * @brief The tank drive interface with built-in motor disabling
 *
 */
class TankDrive {
private:
    /* avoid creating more instances */
    /**
     * @brief Construct a new Tank Drive object, 
     * and start the motor control thread if auto motor disabling is enabled
     *
     */
    TankDrive() = default;
    TankDrive(const TankDrive&) = delete;
    TankDrive& operator=(const TankDrive&) = delete;

#ifdef ENABLE_AUTO_MOTOR_DISABLING

    /* the motor control thread */
    vex::task motor_control{ TankDrive::loop };

    /* thread safety */
    vex::mutex speed_value_lock{};

    /* speed values */
    double left{ 0.0 }, right{ 0.0 };

    /**
     * @brief The function for the motor control thread
     *
     * @return 0
     */
    static int loop();

#endif

public:
    /**
     * @brief Get the global instance
     *
     * @return The global instance
     */
    static TankDrive& getInstance() {
        static TankDrive instance{};
        return instance;
    }

    /**
     * @brief Set the left and right speed of the tank drive
     *
     * @param left
     * @param right
     */
    void drive(double left, double right);
};
