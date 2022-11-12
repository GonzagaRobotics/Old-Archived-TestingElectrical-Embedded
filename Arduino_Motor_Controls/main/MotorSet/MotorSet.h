#ifndef MOTOR_SET_H
#define MOTOR_SET_H

#include "MotorController.h"
#include <Arduino.h>


#define maxMotors 8

class MotorSet{
    public:
        MotorSet();
        ~MotorSet();

        void driveForwards(double speed);
        void driveBackwards(double speed);
        void stop();

        void addMotor(int pin1, int pin2, int pinEn, char side);
    private:
        MotorController* set[maxMotors];
        numMotors;
        
}

#endif