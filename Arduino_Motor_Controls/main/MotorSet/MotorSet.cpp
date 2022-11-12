/*
Title: MotorSet.cpp
Author: Christine Cabero, Ben Pauka, Matthew VonWahlde, Cameron Zheng
Date Created: 11/12/22
Date Modified: 11/12/22
Description: Function file for MotorSet

*/

#include "MotorSet.h"

/*
Function: MotorSet constructor
Input: N/A
Output: N/A
Description: Constructor for MotorSet, initializes variables
*/
MotorSet::MotorSet(){
    numMotors = 0;
}

/*
Function: MotorSet destructor
Input: N/A
Output: N/A
Description: Destructor for MotorSet, deletes all variables and objects used
*/
MotorSet::~MotorSet(){
    for(int i = 0; i < numMotors){
        delete set[i];
    }

    delete[] set;
    delete numMotors;
}

/*
Function: addMotor
Input: N/A
Output: N/A
Description:
*/
void MotorSet::addMotor(int pin1, int pin2, int pinEn, char side{
    if(numMotors < 8){
        numMotors++;
        set[numMotors - 1] = new MotorController(pin1, pin2, pinEn, side);
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