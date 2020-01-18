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
#include<cmath>

using namespace vex;
//vex::motor name = new vex::motor(PORT)

vex::motor Left = vex::motor(19);
vex::motor Right = vex::motor(18);

vex::controller Controller = vex::controller();

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  while (true) {
    if (Controller.Axis3.position() < 0){
      Left.spin(vex::directionType::rev, (pow(Controller.Axis3.position(), 2) * -1), velocityUnits::rpm);
    }else{
      Left.spin(vex::directionType::rev, pow(Controller.Axis3.position(), 2), velocityUnits::rpm);
    }

    if (Controller.Axis3.position() < 0){
      Right.spin(vex::directionType::rev, (pow(Controller.Axis2.position(), 2) * -1), velocityUnits::rpm);
    }else{
      Right.spin(vex::directionType::rev, pow(Controller.Axis2.position(), 2), velocityUnits::rpm);
    }
    
  }
}
