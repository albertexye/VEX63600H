#include "vex.h"

using namespace vex;
competition Competition;

const auto DRIVE_SETUP = ZERO_TRACKER_NO_ODOM;
const auto LeftMotors = motor_group(Left1, Left2, Left3);
const auto RightMotors = motor_group(Right1, Right2, Right3);
const auto INERTIAL_PORT = PORT1;

// how many rounds the wheel turns after the motor completes a full round
// FIXME: to be measured
const auto EXTERNAL_RATIO = 1.4;

// FIXME: to be measured
const auto WHEEL_DIAMETER = 2.75; // in inches

// gyro read after a 360-degree turn
// FIXME: to be measured
const auto GYRO_SCALE = 360; //  in degrees

// robot center to right motors
// FIXME: to be measured
const auto FWD_TRACKER_CENTER_DISTANCE = 0; // in inches

Drive chassis(DRIVE_SETUP,
  LeftMotors,
  RightMotors,
  INERTIAL_PORT,
  WHEEL_DIAMETER,
  EXTERNAL_RATIO,
  GYRO_SCALE,
  //If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

  //FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
  //LF:      //RF:    
  PORT1, -PORT2,

  //LB:      //RB: 
  PORT3, -PORT4,

  //If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
  //If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
  //If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
  3,

  //Input the Forward Tracker diameter (reverse it to make the direction switch):
  2.75,

  //Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
  //For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
  //This distance is in inches:
  FWD_TRACKER_CENTER_DISTANCE,

  //Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
  1,

  //Sideways tracker diameter (reverse to make the direction switch):
  -2.75,

  //Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
  5.5

);

int current_auton_selection = 0;
bool auto_started = false;


void pre_auton() {
  default_constants();

  while (!auto_started) {
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5, 40, "Battery:");
    Brain.Screen.printAt(5, 60, "%d", Brain.Battery.capacity());
    Brain.Screen.printAt(5, 80, "Chassis Heading Reading:");
    Brain.Screen.printAt(5, 100, "%f", chassis.get_absolute_heading());
    Brain.Screen.printAt(5, 120, "Selected Auton:");
    switch (current_auton_selection) {
    case 0:
      Brain.Screen.printAt(5, 140, "Auton 1");
      break;
    case 1:
      Brain.Screen.printAt(5, 140, "Auton 2");
      break;
    case 2:
      Brain.Screen.printAt(5, 140, "Auton 3");
      break;
    case 3:
      Brain.Screen.printAt(5, 140, "Auton 4");
      break;
    case 4:
      Brain.Screen.printAt(5, 140, "Auton 5");
      break;
    case 5:
      Brain.Screen.printAt(5, 140, "Auton 6");
      break;
    case 6:
      Brain.Screen.printAt(5, 140, "Auton 7");
      break;
    case 7:
      Brain.Screen.printAt(5, 140, "Auton 8");
      break;
    }
    if (Brain.Screen.pressing()) {
      while (Brain.Screen.pressing()) {}
      current_auton_selection++;
    } else if (current_auton_selection == 8) {
      current_auton_selection = 0;
    }
    task::sleep(10);
  }
}

void autonomous(void) {
  auto_started = true;
  switch (current_auton_selection) {
  case 0:
    drive_test();
    break;
  case 1:
    drive_test();
    break;
  case 2:
    turn_test();
    break;
  case 3:
    swing_test();
    break;
  case 4:
    full_test();
    break;
  case 5:
    odom_test();
    break;
  case 6:
    tank_odom_test();
    break;
  case 7:
    holonomic_odom_test();
    break;
  }
}

void usercontrol(void) {
  while (true) {
    chassis.control_tank();
    wait(20, msec);
  }
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) wait(1000, msec);
}
