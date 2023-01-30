/*
Title: MotorSet.cpp
Author: Christine Cabero, Ben Pauka, Matthew VonWahlde, Cameron Zheng
Date Created: 11/12/22
Date Modified: 11/12/22
Description: Function file for MotorSet, controls the motors on one side of the
            rover (i.e. the right set of motors or the left set)
*/

#include "MotorSet.h"


/*
Function: ~MotorSet()
Input: N/A
Output: N/A
Description: Constructor for MotorSet, initializes variables
*/
MotorSet::MotorSet(char motorSide){
    // Setting the side the motors are on (left/right when facing the same direction as the rover)
    this->motorSide = motorSide;
}


/*
Function: ~MotorSet()
Input: N/A
Output: N/A
Description: Destructor for MotorSet, deletes all variables and objects used
*/
MotorSet::~MotorSet(){
    // Deleting all MotorController instances that each element of set is pointing to
    for(int i = 0; i < numMotors; i++){
        delete[] motorSet[i];
    }

    // Deleting the set
    delete[] motorSet;
}


/*
Function: addMotor()
Input: pin 1, pin 2, enable pin, and enable pin
Output: N/A
Description: Adds an instance of MotorController to the motorSet array
*/
void MotorSet::addMotor(int pin1, int pin2, int pinEn, int pwmChannel){
    // If the max number of motors has not been reached
    if(numMotors < maxMotors){
        // increment the number of motors
        numMotors++;

        // add a new motor to the set
        motorSet[numMotors - 1] = new MotorController(pin1, pin2, pinEn, pwmChannel, motorSide);
    }
}


/*
Function: driveForwards()
Input: A speed to go forwards
Output: Changes all motors to the value
Description: Spins the wheels forwards
*/
void MotorSet::driveForwards(double speed){
    for (int i = 0; i < numMotors; i++) {
        // In set[] from 0 to numMotors, set each motor to backwards at the same speed
        motorSet[i]->motorForwards(speed); 
    }
}

/*
Function: driveBackwards()
Input: A speed to go backwards
Output: Changes all motors to the value
Description:
*/
void MotorSet::driveBackwards(double speed){
    for (int i = 0; i < numMotors; i++) {
        // In set[] from 0 to numMotors, set each motor to backwards at the same speed
        motorSet[i]->motorBackwards(speed); 
    }
}

/*
Function: stop()
Input: N/A
Output: N/A
Description: Stops motors
*/
void MotorSet::stop(){
    for (int i = 0; i < numMotors; i++) {
        // In set[] from 0 to numMotors, set each motor to stop
        motorSet[i]->motorStop(); 
    }
}

/*
Function: spinLeft()
Input: Turning speed
Output: Rover spins left
Description: Spins left
*/
void MotorSet::spinLeft(double speed){
    for (int i = 0; i < numMotors; i++) {
        // If the motor is on the left
        if (motorSet[i]->getSide() == 'l') { 
            // Then move backwards
            motorSet[i]->motorBackwards(speed); 
        } else {
            // Else motor is on the right, so move forwards
            motorSet[i]->motorForwards(speed); 
        }
    }
}

/*
Function: spinRight()
Input: Turning speed
Output: Rover spins right
Description: Spins right
*/
void MotorSet::spinRight(double speed){
    for (int i = 0; i < numMotors; i++) {
        // If the motor is on the right
        if (motorSet[i]->getSide() == 'r') { 
            // Then move backwards
            motorSet[i]->motorBackwards(speed); 
        } else {
            // Else motor is on the right, so move forwards
            motorSet[i]->motorForwards(speed); 
        }
    }
}