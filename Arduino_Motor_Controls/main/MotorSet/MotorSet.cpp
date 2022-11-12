#include "MotorSet.h"


MotorSet::MotorSet(){
    numMotors = 0;
}

MotorSet::~MotorSet(){
    numMotors = 0;
}

void MotorSet::addMotor(int pin1, int pin2, int pinEn, char side{
    if(numMotors < 8){
        set[numMotors] = new MotorController(pin1, pin2, pinEn, side);
        numMotors++;
    }
}

void MotorSet::driveForwards(){

}

void MotorSet::driveBackwards(){

}

void MotorSet::stop(){
    
}