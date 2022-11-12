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

#endif