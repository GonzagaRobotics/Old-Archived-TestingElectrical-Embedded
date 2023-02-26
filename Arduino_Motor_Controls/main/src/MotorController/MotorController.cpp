/*
Title: MotorController.cpp
Author: Christine Cabero, Ben Pauka, Matthew VonWahlde, Cameron Zheng
Date Created: 11/12/22
Date Modified: 2/2/23
Description: Functions for Motorcontroller

*/

#include "MotorController.h"
#include "../CPPGPIO/CPPGPIO.h"


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
MotorController::MotorController(int pin1, int pwmChannel1, char side){
    // Setting up pin 1
    //setPinMode(pin1, 1);
    this->pin1 = pin1;
    
    // Setting up pin 2
    //setPinMode(pin2, 1);
    //this->pin2 = pin2;

    // Declaring pwm channel 1
    this->pwmChannel1 = pwmChannel1;

    // Setting the pwm channel 2
    //this->pwmChannel2 = pwmChannel2;

    // Setting the side
    this->side = side;

    // Setting up the pwm channel 1 and attaching to pin 1
    setUpPWMChannel(pin1, pwmChannel1, freq, resolution);

    // Setting up the pwm channel 2 and attaching to pin 2
    //setUpPWMChannel(pin2, pwmChannel2, freq, resolution);
}

/*
Function: motorForwards()
Input: speed for the wheels (value between 0 and 1, non-inclusive)
Output: N/A
Description: sends a signal to the motor to spin the right or left wheel forwards

*/
void MotorController::motorForwards(float speed){
    // Making sure speed is between 0 and 1, inclusive
    if(speed > 1)
        speed = 1;
    else if(speed < 0)
        speed = 0;
    
    // Setting pin 1 and pin 2 to spin the motor forwards
    // Note: Forwards is dependent on which side the motor is on
    if(side == 'r'){

        writePWMChannel(pwmChannel1, maxDutyCycle * speed);
        //digitalOutput(pin1, 0);
        //digitalOutput(pin2, 1);
    } else if(side == 'l'){
        writePWMChannel(pwmChannel1, maxDutyCycle * speed);
        //digitalOutput(pin1, 1);
        //digitalOutput(pin2, 0);
    }
}

/*
Function: motorBackwards()
Input: speed for the wheel (between 0 and 1)
Output: N/A
Description: sends a signal to the motor to spin the right or left wheel backwards

*/
void MotorController::motorBackwards(float speed){
    // Making sure speed is between 0 and 1, inclusive
    if(speed > 1)
        speed = 1;
    else if(speed < 0)
        speed = 0;

    // Adjusting the pwm channel to the inputted speed
    // writePWMChannel(pwmChannel, maxDutyCycle * speed);

    // Setting pin 1 and pin 2 to spin the motor backwards
    // Note: Backwards is dependent on which side the motor is on
    if(side == 'r'){
        // digitalOutput(pin1, 1);
        writePWMChannel(pwmChannel1, maxDutyCycle * speed);
    } else if(side == 'l'){
        // digitalOutput(pin2, 1);
        writePWMChannel(pwmChannel1, maxDutyCycle * speed);
    }
}

/* I don't think this function is necessary
Function: motorMove()
Input: speed for the wheel (between -1 and 1)
Output: N/A
Description: sends a signal to the motor at a speed between -1 and 1,
             -1 is backwards, 1 is forwards, 0 is stop

void MotorController::motorMove(double speed){
    // Making sure speed is between -1 and 1, inclusive
    if(speed > 1)
        speed = 1;
    else if(speed < -1)
        speed = -1;

    // Adjusting the pwm channel to the inputted speed
    writePWMChannel(pwmChannel, maxDutyCycle * returnAbs(speed));


    if (speed == 0) { // If speed is 0, set both to low
        digitalOutput(pin1, 0);
        digitalOutput(pin2, 0);
    } else if ((side == 'r' && speed > 0) || (side == 'l' && speed < 0)) {
        digitalOutput(pin1, 0); // If speed is positive, and right side,
        digitalOutput(pin2, 1); // or speed is negative, and left side
    } else {
        digitalOutput(pin1, 1); // If speed is positive, and left side,
        digitalOutput(pin2, 0); // or speed is negative, and right side
    }
}
*/

/*
Function: motorStop()
Input: N/A
Output: Sends a signal to motor to stop spinning
Description: 
*/
void MotorController::motorStop(){
    // Writing low to pin 1 and pin 2 will cause the motor to stop
    //digitalOutput(pin1, 0);
    //digitalOutput(pin2, 0);
    writePWMChannel(pwmChannel1, 0);
    //writePWMChannel(pwmChannel2, 0);
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


float returnAbs(float num){
    if(num >= 0)
        return num;
    else
        return -1*num;

}
