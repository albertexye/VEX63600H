/**
 * @file drivetrain.cpp
 * @author Alex Ye (albertexye@gmail.com)
 * @brief The implementation of the drivetrain
 * @version 0.1
 * @date 2024-09-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "drivetrain.h"

#ifdef ENABLE_AUTO_MOTOR_DISABLING
int TankDrive::loop() {
    // get the global instance, it's just a shortcut
    TankDrive& self{ TankDrive::getInstance() };

    while (true) {
        // make sure no changes are happening when reading the speed
        self.speed_value_lock.lock();

        // read the values
        const double left{ self.left };
        const double right{ self.right };

        // release the lock
        self.speed_value_lock.unlock();

        // first row of motors
        if (Global::left_motor1.installed() && Global::right_motor1.installed()) {
            // both connected
            Global::left_motor1.spin(vex::directionType::fwd, left, vex::velocityUnits::pct);
            Global::right_motor1.spin(vex::directionType::fwd, right, vex::velocityUnits::pct);
        } else {
            // one or both disconnected, stop them
            Global::left_motor1.spin(vex::directionType::fwd, 0.0, vex::velocityUnits::pct);
            Global::right_motor1.spin(vex::directionType::fwd, 0.0, vex::velocityUnits::pct);
        }

        // second row of motors
        if (Global::left_motor2.installed() && Global::right_motor2.installed()) {
            // both connected
            Global::left_motor2.spin(vex::directionType::fwd, left, vex::velocityUnits::pct);
            Global::right_motor2.spin(vex::directionType::fwd, right, vex::velocityUnits::pct);
        } else {
            // one or both disconnected, stop them
            Global::left_motor2.spin(vex::directionType::fwd, 0.0, vex::velocityUnits::pct);
            Global::right_motor2.spin(vex::directionType::fwd, 0.0, vex::velocityUnits::pct);
        }

        // third row of motors
        if (Global::left_motor3.installed() && Global::right_motor3.installed()) {
            // both connected
            Global::left_motor3.spin(vex::directionType::fwd, left, vex::velocityUnits::pct);
            Global::right_motor3.spin(vex::directionType::fwd, right, vex::velocityUnits::pct);
        } else {
            // one or both disconnected, stop them
            Global::left_motor3.spin(vex::directionType::fwd, 0.0, vex::velocityUnits::pct);
            Global::right_motor3.spin(vex::directionType::fwd, 0.0, vex::velocityUnits::pct);
        }

        // sleep for 10 ms so the robot is responsive
        vex::wait(10, vex::timeUnits::msec);
    }

    return 0;
}
#endif

void TankDrive::drive(const double left, const double right) {
#ifdef ENABLE_AUTO_MOTOR_DISABLING

    // make sure the motor control thread isn't reading the speed values
    this->speed_value_lock.lock();

    // set the values
    this->left = left;
    this->right = right;

    // release the lock
    this->speed_value_lock.unlock();

#else

    // left motors
    Global::left_motor1.spin(vex::directionType::fwd, left, vex::velocityUnits::pct);
    Global::left_motor2.spin(vex::directionType::fwd, left, vex::velocityUnits::pct);
    Global::left_motor3.spin(vex::directionType::fwd, left, vex::velocityUnits::pct);

    // right motors
    Global::right_motor1.spin(vex::directionType::fwd, right, vex::velocityUnits::pct);
    Global::right_motor2.spin(vex::directionType::fwd, right, vex::velocityUnits::pct);
    Global::right_motor3.spin(vex::directionType::fwd, right, vex::velocityUnits::pct);

#endif
}
