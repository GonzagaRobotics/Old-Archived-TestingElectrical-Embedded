/*
Title: MotorController.h
Author: Christine Cabero, Ben Pauka, Matthew VonWahlde, Cameron Zheng
Date Created: 11/12/22
Date Modified: 11/12/22
Description: Header file for MotorController

*/

#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include <Arduino.h>


/*
Function: MotorController class definition
Input:
Output:
Description:

*/

class MotorController{
    public:
        MotorController(int pin1, int pin2, int pinEn, char side);

        void motorForwards(double speed);
        void motorBackwards(double speed);
        void motorStop();

        void getSide();
    private:
        int pin1;
        int pin2;
        int pinEn;
        char side;

        const int freq = 500;
        const int pwmChannel = 0;
        const int resolution = 8;
        const int maxDutyCycle = 1;
};

#endif


