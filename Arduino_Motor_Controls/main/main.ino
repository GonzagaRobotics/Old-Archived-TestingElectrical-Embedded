// File used to test library functionality

#include "src/MotorController/MotorController.h"
#include "src/MotorSet/MotorSet.h"

  int motor1Pin1 = 19;
  int motor1Pin2 = 22;
  int motor1PinEn = 21;
  int motor1PwmChannel = 0;
  char motor1Side = 'r';

  int motor2Pin1 = 18;
  int motor2Pin2 = 23;
  int motor2PinEn = 5;
  int motor2PwmChannel = 1;
  char motor2Side = 'r';

  int motor3Pin1 = 27;
  int motor3Pin2 = 33;
  int motor3PinEn = 14;
  int motor3PwmChannel = 2;
  char motor3Side = 'r';

  int motor4Pin1 = 32;
  int motor4Pin2 = 26;
  int motor4PinEn = 25;
  int motor4PwmChannel = 3;
  char motor4Side = 'l';

  int motor5Pin1 = 15;
  int motor5Pin2 = 13;
  int motor5PinEn = 12;
  int motor5PwmChannel = 4;
  char motor5Side = 'l';

  int motor6Pin1 = 4;
  int motor6Pin2 = 2;
  int motor6PinEn = 0;
  int motor6PwmChannel = 5;
  char motor6Side = 'l';

  MotorSet* motors = new MotorSet();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  motors->addMotor(motor1Pin1, motor1Pin2, motor1PinEn, motor1PwmChannel, motor1Side);
  motors->addMotor(motor2Pin1, motor2Pin2, motor2PinEn, motor2PwmChannel, motor2Side);
  motors->addMotor(motor3Pin1, motor3Pin2, motor3PinEn, motor3PwmChannel, motor3Side);
  motors->addMotor(motor4Pin1, motor4Pin2, motor4PinEn, motor4PwmChannel, motor4Side);
  motors->addMotor(motor5Pin1, motor5Pin2, motor5PinEn, motor5PwmChannel, motor5Side);
  motors->addMotor(motor6Pin1, motor6Pin2, motor6PinEn, motor6PwmChannel, motor6Side);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Forwards!");
  motors->driveForwards(1);
  delay(2000);

  Serial.print("Stopping!");
  motors->stop();
  delay(2000);

  Serial.print("Backwards!");
  motors->driveBackwards(1);
  delay(2000);

  Serial.print("Stopping!");
  motors->stop();
  delay(2000);

  Serial.print("Spinning Right!");
  motors->spinRight(1);
  delay(2000);

  Serial.print("Stopping!");
  motors->stop();
  delay(2000);

  Serial.print("Spinning Left!");
  motors->spinLeft(1);
  delay(2000);

  Serial.print("Stopping!");
  motors->stop();
  delay(2000);
}
