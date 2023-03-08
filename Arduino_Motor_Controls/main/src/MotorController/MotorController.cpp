/*
Title: MotorController.cpp
Author: Christine Cabero, Ben Pauka, Matthew VonWahlde, Cameron Zheng
Date Created: 11/12/22
Date Modified: 2/2/23
Description: Functions for Motorcontroller

*/

#include "MotorController.h"
#include "../CPPGPIO/CPPGPIO.h"


/*
Function: MotorController()
Input: pin1, pin2, pinEn, pwm channel, side the motor is on (left = 'l', right = 'r')
Output: N/A
Description: Sets up the pins for the motorcontroller and tells which side 
             motors to communicate with

*/
MotorController::MotorController(int pin1, int pwmChannel1, char side){
    // Setting up pin 1
    setOutputPin(pin1, 1);
    this->pin1 = pin1;

    // Declaring pwm channel 1
    this->pwmChannel1 = pwmChannel1;

    // Setting the side
    this->side = side;

    // Setting up the pwm channel 1 and attaching to pin 1
    setUpPWMChannel(pin1, pwmChannel1, freq, resolution);
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
        writePWMChannel(pwmChannel1, calcDutyCycleForwards(speed));
    } else if(side == 'l'){
        writePWMChannel(pwmChannel1, calcDutyCycleBackwards(speed));
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

    // Setting pin 1 and pin 2 to spin the motor backwards
    // Note: Backwards is dependent on which side the motor is on
    if(side == 'r'){
        writePWMChannel(pwmChannel1, calcDutyCycleBackwards(speed));
    } else if(side == 'l'){
        writePWMChannel(pwmChannel1, calcDutyCycleForwards(speed));
    }
}


/*
Function: motorStop()
Input: N/A
Output: Sends a signal to motor to stop spinning
Description: 
*/
void MotorController::motorStop(){
    // Stop the motor
    writePWMChannel(pwmChannel1, calcDutyCycleForwards(0));
}


/*
Function: calcDutyCycleForwards()
Input: float - a value of speed between 0(stopped) and 1(full speed)
Output: int - duty cycle 
Description: calculates the duty cycle based on the inputted speed
            for the Talon SRX motor controllers
*/
int MotorController::calcDutyCycleForwards(float speed){
    // Desired time sending high signal per period
    float highTime = restVeloHigh + speed*(maxVeloHigh - restVeloHigh);
    
    // Current period based on frequency
    float period = 1.0 / (float)freq * 1000;
    
    // Duty cycle as a float between 0 and 1
    float duty = highTime / period;
 
    // Returning duty cycle as an int between 0 and 255
    return duty * maxDutyCycle;
}


/*
Function: calcDutyCycleBackwards()
Input: float - a value of speed between 0(stopped) and 1(full speed)
Output: int - duty cycle 
Description: calculates the duty cycle based on the inputted speed
            for the Talon SRX motor controllers
*/
int MotorController::calcDutyCycleBackwards(float speed){
    // Desired time sending high signal per period
    float highTime = restVeloHigh - speed*(restVeloHigh - minVeloHigh);

    // Current period based on frequency
    float period = 1.0 / freq * 1000;
    
    // Duty cycle as a float between 0 and 1
    float duty = highTime / period;

    // Returning duty cycle as an int between 0 and 255
    return duty * maxDutyCycle;
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

/*
float returnAbs(float num){
    if(num >= 0)
        return num;
    else
        return -1*num;

}
*/