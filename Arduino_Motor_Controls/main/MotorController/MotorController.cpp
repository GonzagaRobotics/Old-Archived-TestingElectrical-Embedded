/*
Title:
Author:
Date Created:
Date Modified:
Description:

*/

#include "MotorController.h"


/*
Description:
Input:
Output:

*/

MotorController::MotorController(int pin1, int pin2, int pinEn, char side){
    pinMode(pin1, OUTPUT);
    this->pin1 = pin1;
    
    pinMode(pin2, OUTPUT);
    this->pin2 = pin2;

    pinMode(pinEn, OUTPUT);
    this->pinEn = pinEn;

    this->side = side;

    ledcSetup(pwmChannel, freq, resolution);
    ledcAttachPin(this->pinEn, pwmChannel);
}

/*
Description:
Input:
Output:

*/
void MotorController::motorForwards(double speed){
    if(speed > 1)
        speed = 1;

    if(speed < 0)
        speed = 0;

    ledcWrite(pwmChannel, maxDutyCycle * speed);

    if(side == 'r'){
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
    } else if(side == 'l'){
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
    }
}

/*
Description:
Input:
Output:

*/
void MotorController::motorBackwards(double speed){
    if(speed > 1)
        speed = 1;

    if(speed < 0)
        speed = 0;

    ledcWrite(pwmChannel, maxDutyCycle * speed);

    if(side == 'r'){
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
    } else if(side == 'l'){
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
    }
}

/*
Description:
Input:
Output:

*/
void MotorController::motorStop(){
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
}


