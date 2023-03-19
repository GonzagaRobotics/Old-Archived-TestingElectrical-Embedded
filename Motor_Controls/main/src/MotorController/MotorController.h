/*
Title: MotorController.h
Author: Christine Cabero, Ben Pauka, Matthew VonWahlde, Cameron Zheng
Date Created: 11/12/22
Date Modified: 2/2/23
Description: Header file for MotorController
*/

#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

//#include <Arduino.h>


/*
Class: MotorController
Input: pin 1, pin 2, pwm channel 1, pwm channel 2, and the side the motor is on (left = 'l', right = 'r')
Output: N/A
Description: This class represents one motor controller on the board. MotorSet uses and instance of this class for each of its motors

*/

class MotorController{
    public:
        MotorController(int, int, char);

        void motorForwards(float);
        void motorBackwards(float);
        //void motorMove(float speed);
        void motorStop();

        char getSide();
    private:
        int pin1;
        int pwmChannel1;
        char side;

        int freq = 333;
        int resolution = 8;
        int maxDutyCycle = 255;

        const float maxVeloHigh = 1.65; // forwards
        const float restVeloHigh = 1.5; // stopped
        const float minVeloHigh = 1.35; // max backwards

        int calcDutyCycleForwards(float);
        int calcDutyCycleBackwards(float);

        //float returnAbs(float);
};

#endif
