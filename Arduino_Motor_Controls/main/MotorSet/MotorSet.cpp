/*
Title: MotorSet.CPP
Author: 
Date Created: 11/12/22
Date Modified: 11/12/22
Description: Function file for MotorSet

*/

#include "MotorSet.h"

/*
Function: MotorSet constructor
Input: N/A
Output: N/A
Description:
*/
MotorSet::MotorSet(){
    numMotors = 0;
}

/*
Function: MotorSet destructor
Input: N/A
Output: N/A
Description:
*/
MotorSet::~MotorSet(){
    numMotors = 0;
}

/*
Function: addMotor
Input: N/A
Output: N/A
Description:
*/
void MotorSet::addMotor(int pin1, int pin2, int pinEn, char side{
    if(numMotors < 8){
        set[numMotors] = new MotorController(pin1, pin2, pinEn, side);
        numMotors++;
    }
}

/*
Function: driveForwards
Input: N/A
Output: N/A
Description: Spins the wheels forwards
*/
void MotorSet::driveForwards(){

}

/*
Function: driveBackwards
Input: N/A
Output: N/A
Description:
*/
void MotorSet::driveBackwards(){

}

/*
Function: stop
Input: N/A
Output: N/A
Description: Stops motors
*/
void MotorSet::stop(){
    
}