// File used to test library functionality
/*
#include "src/MotorController/MotorController.h"
#include "src/MotorSet/MotorSet.h"

  int motor1Pin1 = 27;
  int motor1Pin2 = 26;
  int motor1PinEn = 14;
  int motor1PwmChannel = 0;
  char motor1Side = 'r';

  int motor2Pin1 = 23;
  int motor2Pin2 = 19;
  int motor2PinEn = 22;
  int motor2PwmChannel = 1;
  char motor2Side = 'l';

  MotorSet* motors = new MotorSet();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  motors->addMotor(motor1Pin1, motor1Pin2, motor1PinEn, motor1PwmChannel, motor1Side);
  motors->addMotor(motor2Pin1, motor2Pin2, motor2PinEn, motor2PwmChannel, motor2Side);
}

void loop() {
  // put your main code here, to run repeatedly:
  motors->driveForwards(1);
  delay(1000);

  motors->stop();
  delay(1000);

  motors->driveBackwards(1);
  delay(1000);

  motors->stop();
  delay(1000);

  motors->spinRight(1);
  delay(1000);

  motors->stop();
  delay(1000);

  motors->spinLeft(1);
  delay(1000);

  motors->stop();
  delay(1000);
}
*/