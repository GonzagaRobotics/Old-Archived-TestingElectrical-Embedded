// File used to test library functionality

#include <MotorController.h>

  int motor1Pin1 = 27;
  int motor1Pin2 = 26;
  int motor1PinEn = 14;

  MotorController motor(motor1Pin1, motor1Pin2, motor1PinEn, 'r');

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  motor.motorForwards(1);
  delay(1000);
  motor.motorStop();
  delay(1000);
  motor.motorBackwards(1);
  delay(1000);
  motor.motorStop();
  delay(1000);
}
