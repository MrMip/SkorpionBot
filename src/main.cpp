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
  int bit0 = 100;
  int bit1 = 200;
  while (true) {

    if(Controller.ButtonA.pressing()){
      turbo = true;
    }

    if(Controller.ButtonB.pressing()){
      turbo = false;
    }

    //Turbo toggle  
    if(turbo == true){ bit0 = 200; bit1 = 200;}else{bit0 = 100; bit1 = 100;}

     

  

    //Handbrake stuffs lul 
    if(Controller.ButtonL1.pressing() || Controller.ButtonL2.pressing()){ bit0 = 0; }else if(turbo){ bit0 = 200; } else{bit0 = 100;}
    if(Controller.ButtonR1.pressing() || Controller.ButtonR2.pressing()){ bit1 = 0; }else if (turbo){bit1 = 200;} else {bit1 = 100;}
    
    int sign = Controller.Axis3.position() >= 0.0f ? -1 : 1;
    Brain.Screen.setCursor(1, 1);

    if(sign == 1) {
      Left.spin(vex::directionType::fwd, pow(-Controller.Axis3.position() / 100.0, 3) * bit0, velocityUnits::rpm);
    } else {
      Left.spin(vex::directionType::rev, pow(Controller.Axis3.position() / 100.0, 3) * bit0, velocityUnits::rpm);
    }

    sign = Controller.Axis2.position() >= 0.0f ? -1 : 1;
    if(sign == 1) {
      Right.spin(vex::directionType::rev, pow(-Controller.Axis2.position() / 100.0, 3) * bit1, velocityUnits::rpm);
    } else {
      Right.spin(vex::directionType::fwd, pow(Controller.Axis2.position() / 100.0, 3) * bit1, velocityUnits::rpm);
    }
    
    wait(200, msec);
    Brain.Screen.clearScreen();

  
}
}
