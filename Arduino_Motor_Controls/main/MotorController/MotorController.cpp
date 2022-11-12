/*
Title: MotorController.cpp
Author:
Date Created: 11/12/22
Date Modified: 11/12/22
Description: Functions for Motorcontroller

*/

#include "MotorController.h"

/*
Function: MotorSet constructor
Input:
Output:
Description:

*/

MotorSet::MotorSet(){

}

/*
Function:
Input:
Output:
Description:

*/
MotorSet::~MotorSet(){

}

/*
Function:
Input:
Output:
Description:

*/
MotorSet::driveForwards(){

}

/*
Function:
Input:
Output:
Description:

*/
MotorSet::driveBackwards(){

}

/*
Function:
Input:
Output:
Description:

*/
MotorSet::stop(){
    
}

/*
Function: Constructor for the Motorcontroller class
Input: pin1, pin2, pinEn, side 
Output: N/A
Description: Sets up the pins for the motorcontroller and tells which side motors to communicate with

*/

MotorController::MotorController(int pin1, int pin2, int pinEn, char side){
    pinMode(pin1, OUTPUT);
    this->pin1 = pin1;
    
    pinMode(pin2, OUTPUT);
    this->pin2 = pin2;

    pinMode(pinEn, OUTPUT);
    this->pinEn = pinEn;

    this->side = side;

    ledcSetup(pwmChannel, freq, resolution);
    ledcAttachPin(this->pinEn, pwmChannel);
}

/*
Function: Spins the wheel forwards
Input: speed for the wheels
Output: N/A
Description: sends a signal to the motor to spin the right or left wheel forwards

*/
void MotorController::motorForwards(double speed){
    if(speed > 1)
        speed = 1;

    if(speed < 0)
        speed = 0;

    ledcWrite(pwmChannel, maxDutyCycle * speed);

    if(side == 'r'){
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
    } else if(side == 'l'){
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
    }
}

/*
Function: Spins the wheel backwards
Input: speed for the wheel
Output: N/A
Description: sends a signal to the motor to spin the right or left wheel backwards

*/
void MotorController::motorBackwards(double speed){
    if(speed > 1)
        speed = 1;

    if(speed < 0)
        speed = 0;

    ledcWrite(pwmChannel, maxDutyCycle * speed);

    if(side == 'r'){
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
    } else if(side == 'l'){
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
    }
}

/*
Function: Stops the motor from spinning
Input: N/A
Output: Sends a signal to motor to stop spinning
Description: 

*/
void MotorController::motorStop(){
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
}


