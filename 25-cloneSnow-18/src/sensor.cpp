#include "vex.h"
#include "sensor.h"
#include "robot-config.h"
#include "utils/util.h"



void Sensor::aiGetXPos( ){
  // aiVision1.takeSnapshot(colors[index]);
  aiVision1.takeSnapshot(aivision::ALL_COLORS );

  // Brain.Screen.clearScreen();
  Brain.Screen.setCursor(2, 1);
  Brain.Screen.print("x pos: %d", aiVision1.objects[0].centerX);
  // the AI Vision Sensor automatically sorts objects by size. The largest object is assigned index 0, 
  //with smaller objects receiving higher index numbers.
  if (aiVision1.objectCount > 0) {
      double wid = aiVision1.objects[0].width; // unit in pixels
      int angle = aiVision1.objects[0].angle;
      double disValue = Distance1.objectDistance(mm);

    if (aiVision1.objects[0].id == 1){ // or == redRing 

      // Controller1.Screen.clearScreen();
      Controller1.Screen.setCursor(1,1);
      Controller1.Screen.print(" Largest OBJ: redRing") ;
      // Controller1.Screen.clearScreen();
      Controller1.Screen.setCursor(2,1);
      // Controller1.Screen.print("angle: %d, angle"， angle) ;
      // width is: %.1f, angle: %d", wid, angle );
    } 


    else if (aiVision1.objects[0].id == 2){ // or == blueRing 

      // Controller1.Screen.clearScreen();
      Controller1.Screen.setCursor(1,1);
      Controller1.Screen.print(" Largest OBJ: blueRing");
      // Controller1.Screen.clearScreen();
      Controller1.Screen.setCursor(2,1);
      // Controller1.Screen.print("distance Value: %.1f mm "，disValue);
      // , width is: %.1f, angle: %d, distan: %.1f", wid, angle, distan);
    } 
  }
  else{
    // Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1,1);
    Controller1.Screen.print("no obj found");
  }


  // void setArmToHighest(){
  //   Arm.spinToPosition(440.0, degrees, true);
  //   Arm.setStopping(hold);
  // }

}

int Sensor::redAveCount(){
  int sum = 0;
  int numSamples = 10; // Number of snapshots to average

  for (int i = 0; i < numSamples; i++) {
      aiVision1.takeSnapshot(redRing);
      sum += aiVision1.objectCount;
      vex::task::sleep(50); // Small delay to prevent blocking
  }

  int averageCount = sum / numSamples;
  double height = aiVision1.objects[0].width;
  // Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(3, 1);
  Controller1.Screen.print("redA: %d. h:%.1f", averageCount,height);

  
  return averageCount;
}

//skills is blue above red ring
bool Sensor::isBlueAbove(){
  aiVision1.takeSnapshot(aivision::ALL_COLORS );
  //blue position, height specificly

  //red position

  //if blue height > red height, and around same size pixel wise

  return true;

}

int Sensor::redSinCount(){
  aiVision1.takeSnapshot(redRing); // Use redRing directly here
  // Controller1.Screen.clearScreen();
  int count = aiVision1.objectCount;
  Controller1.Screen.setCursor(2, 1);
  double height = aiVision1.objects[0].width;
  Controller1.Screen.print("redS: %d, h: %.1f", count,height);
  return count;
}

int Sensor::getDistance(){
  if (Distance1.isObjectDetected()){
    return Distance1.objectDistance(distanceUnits::cm);
  }
  return 0;
}

int Sensor::ringInStack(){
  if (getDistance() == 5){
    return 1;
  }

  return 0;
}
