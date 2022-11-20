/*
Title: MotorController.cpp
Author: Christine Cabero, Ben Pauka, Matthew VonWahlde, Cameron Zheng
Date Created: 11/12/22
Date Modified: 11/12/22
Description: Functions for Motorcontroller

*/

#include "MotorController.h"
#include <stdlib.h>

// TO DO
/*
pinMode
ledcSetup
ledcAttachPin
ledcWrite
digitalWrite
*/

/*
Function: MotorController()
Input: pin1, pin2, pinEn, pwm channel, side the motor is on (left = 'l', right = 'r')
Output: N/A
Description: Sets up the pins for the motorcontroller and tells which side 
             motors to communicate with

*/
MotorController::MotorController(int pin1, int pin2, int pinEn, int pwmChannel, char side){
    // Setting up pin 1
    pinMode(pin1, OUTPUT);
    this->pin1 = pin1;
    
    // Setting up pin 2
    pinMode(pin2, OUTPUT);
    this->pin2 = pin2;

    // Setting up enable pin
    pinMode(pinEn, OUTPUT);
    this->pinEn = pinEn;

    // Setting the side
    this->side = side;

    // Setting the pwmChannel
    this->pwmChannel = pwmChannel;

    // Setting up the pwm channel and attaching to the enable pin
    ledcSetup(pwmChannel, freq, resolution);
    ledcAttachPin(this->pinEn, pwmChannel);
}

/*
Function: motorForwards()
Input: speed for the wheels (value between 0 and 1, inclusive)
Output: N/A
Description: sends a signal to the motor to spin the right or left wheel forwards

*/
void MotorController::motorForwards(double speed){
    // Making sure speed is between 0 and 1, inclusive
    if(speed > 1)
        speed = 1;
    else if(speed < 0)
        speed = 0;

    // Adjusting the pwm channel to the inputted speed
    ledcWrite(pwmChannel, maxDutyCycle * speed);

    // Setting pin 1 and pin 2 to spin the motor forwards
    // Note: Forwards is dependent on which side the motor is on
    if(side == 'r'){
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
    } else if(side == 'l'){
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
    }
}

/*
Function: motorBackwards()
Input: speed for the wheel (between 0 and 1)
Output: N/A
Description: sends a signal to the motor to spin the right or left wheel backwards

*/
void MotorController::motorBackwards(double speed){
    // Making sure speed is between 0 and 1, inclusive
    if(speed > 1)
        speed = 1;
    else if(speed < 0)
        speed = 0;

    // Adjusting the pwm channel to the inputted speed
    ledcWrite(pwmChannel, maxDutyCycle * speed);

    // Setting pin 1 and pin 2 to spin the motor backwards
    // Note: Backwards is dependent on which side the motor is on
    if(side == 'r'){
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
    } else if(side == 'l'){
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
    }
}

/*
Function: motorMove()
Input: speed for the wheel (between -1 and 1)
Output: N/A
Description: sends a signal to the motor at a speed between -1 and 1,
             -1 is backwards, 1 is forwards, 0 is stop
*/
void MotorController::motorMove(double speed){
    // Making sure speed is between -1 and 1, inclusive
    if(speed > 1)
        speed = 1;
    else if(speed < -1)
        speed = -1;

    // Adjusting the pwm channel to the inputted speed
    ledcWrite(pwmChannel, maxDutyCycle * abs(speed));


    if (speed == 0) { // If speed is 0, set both to low
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, LOW);
    } else if ((side == 'r' && speed > 0) || (side == 'l' && speed < 0)) {
        digitalWrite(pin1, LOW); // If speed is positive, and right side,
        digitalWrite(pin2, HIGH); // or speed is negative, and left side
    } else {
        digitalWrite(pin1, HIGH); // If speed is positive, and left side,
        digitalWrite(pin2, LOW); // or speed is negative, and right side
    }
}

/*
Function: motorStop()
Input: N/A
Output: Sends a signal to motor to stop spinning
Description: 

*/
void MotorController::motorStop(){
    // Writing low to pin 1 and pin 2 will cause the motor to stop
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
}

/*
Function: getSide()
Input: N/A
Output: The side the motor is on 'l' or 'r'
Description: Getter for the side variable

*/
char MotorController::getSide(){
    // returns what side the motor is on
    return side;
}
