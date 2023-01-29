// File used to test library functionality
/*
#include "src/MotorController/MotorController.h"

  int motor1Pin1 = 27;
  int motor1Pin2 = 26;
  int motor1PinEn = 14;
  int motor1PwmChannel = 0;
  char motor1Side = 'r';

  int motor2Pin1 = 23;
  int motor2Pin2 = 19;
  int motor2PinEn = 22;
  int motor2PwmChannel = 1;
  char motor2Side = 'r';

  //MotorController* motors = new MotorController(motor1Pin1, motor1Pin2, motor1PinEn, motor1PwmChannel, motor1Side);
  MotorController* motors = new MotorController(motor2Pin1, motor2Pin2, motor2PinEn, motor2PwmChannel, motor2Side);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  motors->motorForwards(1);
  delay(1000);

  motors->motorStop();
  delay(1000);

  motors->motorBackwards(1);
  delay(1000);

  motors->motorStop();
  delay(1000);
}
*/
#include "src/CPPGPIO/CPPGPIO.h"

void setup(){
    Serial.begin(9600);
    setOutputPin(27);
}

void loop(){
  digitalOutput(27, 1);
  delay(1000);

  digitalWrite(27, 0);
  delay(1000);
}