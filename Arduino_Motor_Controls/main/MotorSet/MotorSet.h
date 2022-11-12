/*
Title: MotorSet.h
Author: Christine Cabero, Ben Pauka, Matthew VonWahlde, Cameron Zheng
Date Created: 11/12/22
Date Modified: 11/12/22
Description: Header file for MotorSet

*/
#ifndef MOTOR_SET_H
#define MOTOR_SET_H

#include "MotorController.h"
#include <Arduino.h>


#define maxMotors 8

/*
Function: MotorSet
Input: None
Output: None
Description: Declares an instance of a set of motors (all wheels in a rover)
*/
class MotorSet{
    public:
        MotorSet();
        ~MotorSet();

        void driveForwards(double speed);
        void driveBackwards(double speed);
        void stop();
        void spinLeft(double speed);
        void spinRight(double speed);

        void addMotor(int pin1, int pin2, int pinEn, char side);
    private:
        MotorController* set[maxMotors];
        numMotors;
        
}

#endif