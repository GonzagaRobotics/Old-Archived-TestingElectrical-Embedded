#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include <Arduino.h>


class MotorSet{
    public:
        MotorSet();
        ~MotorSet();

        void driveForwards(double speed);
        void driveBackwards(double speed);
        void stop();
    private:

}


class MotorController{
    public:
        MotorController(int pin1, int pin2, int pinEn, char side);

        void motorForwards(double speed);
        void motorBackwards(double speed);
        void motorStop();
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
