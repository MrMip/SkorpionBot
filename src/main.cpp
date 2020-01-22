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
  bool turbo = false;
  while (true) {

    if(Controller.ButtonA.pressing()){
      turbo = true;
    }
    if (turbo == true){

          int sign = Controller.Axis3.position() >= 0.0f ? -1 : 1;
    Brain.Screen.setCursor(1, 1);
    if(sign == 1) {
      Left.spin(vex::directionType::fwd, pow(-Controller.Axis3.position() / 100.0, 3) * 100, velocityUnits::pct);
    } else {
      Left.spin(vex::directionType::rev, pow(Controller.Axis3.position() / 100.0, 3) * 100, velocityUnits::pct);
    }

    sign = Controller.Axis2.position() >= 0.0f ? -1 : 1;
    if(sign == 1) {
      Right.spin(vex::directionType::rev, pow(-Controller.Axis2.position() / 100.0, 3) * 100, velocityUnits::pct);
    } else {
      Right.spin(vex::directionType::fwd, pow(Controller.Axis2.position() / 100.0, 3) * 100, velocityUnits::pct);
    }
    
    wait(200, msec);
    Brain.Screen.clearScreen();

    }else{

          int sign = Controller.Axis3.position() >= 0.0f ? -1 : 1;
    Brain.Screen.setCursor(1, 1);
    if(sign == 1) {
      Left.spin(vex::directionType::fwd, pow(-Controller.Axis3.position() / 100.0, 3) * 50, velocityUnits::pct);
    } else {
      Left.spin(vex::directionType::rev, pow(Controller.Axis3.position() / 100.0, 3) * 50, velocityUnits::pct);
    }

    sign = Controller.Axis2.position() >= 0.0f ? -1 : 1;
    if(sign == 1) {
      Right.spin(vex::directionType::rev, pow(-Controller.Axis2.position() / 100.0, 3) * 50, velocityUnits::pct);
    } else {
      Right.spin(vex::directionType::fwd, pow(Controller.Axis2.position() / 100.0, 3) * 50, velocityUnits::pct);
    }
    
    wait(200, msec);
    Brain.Screen.clearScreen();

    }


  }
}
