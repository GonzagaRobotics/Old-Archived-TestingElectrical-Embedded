/*
Title: MotorSet.h
Author: Christine Cabero, Ben Pauka, Matthew VonWahlde, Cameron Zheng
Date Created: 11/12/22
Date Modified: 11/12/22
Description: Header file for MotorSet
*/
#ifndef MOTOR_SET_H
#define MOTOR_SET_H

#include "../MotorController/MotorController.h"


#define maxMotors 8

/*
Function: MotorSet
Input: None
Output: None
Description: Declares an instance of a set of motors (all wheels in a rover)
*/
class MotorSet{
    public:
        ~MotorSet();

        void driveForwards(double);
        void driveBackwards(double);
        void stop();
        void spinLeft(double);
        void spinRight(double);
        void turn(double);
        void turn(double, double);

        void addMotor(int, int, int, int, char);
    private:
        MotorController* set[maxMotors];
        int numMotors = 0;
        
};

#endif