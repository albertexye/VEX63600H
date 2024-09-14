#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

brain Brain;

motor Left1 = motor(PORT1, ratio6_1, false);
motor Left2 = motor(PORT2, ratio6_1, false);
motor Left3 = motor(PORT3, ratio6_1, false);
motor Right1 = motor(PORT4, ratio6_1, false);
motor Right2 = motor(PORT5, ratio6_1, false);
motor Right3 = motor(PORT6, ratio6_1, false);
