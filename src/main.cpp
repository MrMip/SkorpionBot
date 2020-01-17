/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Programming                                      */
/*    Created:      Wed Jan 15 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
//vex::motor name = new vex::motor(PORT)

vex::motor Left = vex::motor(19);
vex::motor Right = vex::motor(18);

vex::controller Controller = vex::controller();

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while (true) {
    Left.spin(vex::directionType::rev, Controller.Axis3.position(), velocityUnits::rpm);
    Right.spin(vex::directionType::fwd, Controller.Axis2.position(), velocityUnits::rpm);
  }
}