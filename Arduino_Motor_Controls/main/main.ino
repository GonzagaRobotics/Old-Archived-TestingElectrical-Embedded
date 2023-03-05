// File used to test library functionality

#include "src/CPPGPIO/CPPGPIO.h"
#include "src/DataProcess/DataProcess.h"
#include "src/MotorSet/MotorSet.h"

MotorSet* leftMotors = NULL;
MotorSet* rightMotors = NULL;

float controlData[5]; 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  leftMotors = addPinsToLeftMotorSet();
  rightMotors = addPinsToRightMotorSet();
  delay(1000);
}

void loop() {
  //Serial.print("code");
  
  // put your main code here, to run repeatedly:
  // Go forwards full speed
  controlData[0] = -0.96;
  controlData[1] = -0.96;
  controlData[2] = 0;
  controlData[3] = 0;
  controlData[4] = 0;
  //Serial.print("HERE");
  dataHandling(controlData, leftMotors, rightMotors);
  //Serial.print("Full speed forwards.   ");
  delay(5000);
/*
  // Slow Down to half speed
  //Serial.print("Slowing Down.   ");
  for(int i = 1; i < 50; i++){
    controlData[0] = -1 + (float)i / 50.0;
    controlData[1] = -1 + (float)i / 50.0;

    dataHandling(controlData, leftMotors, rightMotors);
    delay(50);
  }

  //Serial.print("Half speed forwards.   ");
  delay(5000);
/*  
  // Turn Left
  controlData[0] = 0;
  controlData[1] = -0.99999;

  dataHandling(controlData, leftMotors, rightMotors);
  Serial.print("Turning left.   ");
  delay(5000);

  // Turn Right
  controlData[0] = -0.99999;
  controlData[1] = 0;

  dataHandling(controlData, leftMotors, rightMotors);
  Serial.print("Turning right.   ");
  delay(5000);

  // Backwards
  controlData[0] = 0.99999;
  controlData[1] = 0.99999;
  controlData[2] = 1;
  controlData[3] = 1;

  dataHandling(controlData, leftMotors, rightMotors);
  Serial.print("Backwards.   ");
  delay(5000);

  // Left Side backwards
  controlData[2] = 1;
  controlData[3] = 0;

  dataHandling(controlData, leftMotors, rightMotors);
  Serial.print("Left side backwards.   ");
  delay(5000);

  // Left Side backwards, right side forwards
  controlData[1] = -0.99999;

  dataHandling(controlData, leftMotors, rightMotors);
  Serial.print("Left side backwards, right side forwards.   ");
  delay(5000);

  // Right Side backwards
  controlData[0] = 0.99999;
  controlData[1] = 0.99999;
  controlData[2] = 0;
  controlData[3] = 1;

  dataHandling(controlData, leftMotors, rightMotors);
  Serial.print("Right side backwards.   ");
  delay(5000);

  // Right Side backwards, left side  forwards
  controlData[0] = -0.99999;

  dataHandling(controlData, leftMotors, rightMotors);
  Serial.print("Right side backwards, left side forwards.   ");
  delay(5000);

  // Spinning left 
  controlData[0] = 0.99999;
  controlData[1] = 0.99999;
  controlData[2] = 0;
  controlData[3] = 0;
  controlData[4] = 1;

  dataHandling(controlData, leftMotors, rightMotors);
  Serial.print("Spin left.   ");
  delay(5000);

  // Spinning Right 
  controlData[4] = -1;

  dataHandling(controlData, leftMotors, rightMotors);
  Serial.print("Spin right.   ");
  delay(5000);

  // Stop 
  controlData[0] = 0.99999;
  controlData[1] = 0.99999;
  controlData[2] = 0;
  controlData[3] = 0;
  controlData[4] = 0;

  dataHandling(controlData, leftMotors, rightMotors);
  Serial.print("Stopping.   ");
  delay(5000);
  */
}
