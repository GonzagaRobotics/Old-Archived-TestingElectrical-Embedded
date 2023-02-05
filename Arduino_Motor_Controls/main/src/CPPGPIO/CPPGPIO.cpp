/*
Title: CPPGPIO.cpp
Author: Christine Cabero, Ben Pauka, Matthew VonWahlde, Cameron Zheng
Date Created: 12/3/22
Date Modified: 2/2/23
Description: Function file for ESP32 GPIO in C++
*/

#include "CPPGPIO.h"


// This function adds motors to the left microcontroller
// Inputs: None
// Outputs: pointer to the left MotorSet
MotorSet* addPinsToLeftMotorSet(){
    // All directions are from the perspective of the rover's POV
    
    // Left microcontroller (motors 1 - 3)
    // Pins for the first motor (front left)
    int motor1Pin1 = -1;
    int motor1Pin2 = -1;
    int motor1PinEn = -1;
    int motor1PWMChannel = 0;
    char motor1Side = 'l';

    // Pins for the second motor (middle left)
    int motor2Pin1 = -1;
    int motor2Pin2 = -1;
    int motor2PinEn = -1;
    int motor2PWMChannel = 1;
    char motor2Side = 'l';

    // Pins for the third motor (back left)
    int motor3Pin1 = -1;
    int motor3Pin2 = -1;
    int motor3PinEn = -1;
    int motor3PWMChannel = 2;
    char motor3Side = 'l';

    // Creating pointer to new MotorSet
    MotorSet* leftMotorSet = new MotorSet;

    // Adding motors to left MotorSet
    leftMotorSet->addMotor(motor1Pin1, motor1Pin2, motor1PinEn, motor1PWMChannel, motor1Side);
    leftMotorSet->addMotor(motor2Pin1, motor2Pin2, motor2PinEn, motor2PWMChannel, motor2Side);
    leftMotorSet->addMotor(motor3Pin1, motor3Pin2, motor3PinEn, motor3PWMChannel, motor3Side);

    return leftMotorSet;
}


// This function adds motors to the right microcontroller
// Inputs: None
// Outputs: pointer to the right MotorSet
MotorSet* addPinsToRightMotorSet(){
    // Right microcontroller (motors 4 - 6)
    // Pins for the fourth motor (front right)
    int motor4Pin1 = -1;
    int motor4Pin2 = -1;
    int motor4PinEn = -1;
    int motor4PWMChannel = 0;
    char motor4Side = 'r';

    // Pins for the fifth motor (middle right)
    int motor5Pin1 = -1;
    int motor5Pin2 = -1;
    int motor5PinEn = -1;
    int motor5PWMChannel = 1;
    char motor5Side = 'r';

    // Pins for the sixth motor (back right)
    int motor6Pin1 = -1;
    int motor6Pin2 = -1;
    int motor6PinEn = -1;
    int motor6PWMChannel = 2;
    char motor6Side = 'r';

    // Creating pointer to new MotorSet
    MotorSet* rightMotorSet = new MotorSet;

    // Adding motors to right MotorSet
    rightMotorSet->addMotor(motor4Pin1, motor4Pin2, motor4PinEn, motor4PWMChannel, motor4Side);
    rightMotorSet->addMotor(motor5Pin1, motor5Pin2, motor5PinEn, motor5PWMChannel, motor5Side);
    rightMotorSet->addMotor(motor6Pin1, motor6Pin2, motor6PinEn, motor6PWMChannel, motor6Side);

    return rightMotorSet;
}


// This function sets a pin as a simple output pin
// Inputs: the pin number to set as an output
// Outputs: None
void setOutputPin(int pin){
    /*
    // Checking that the pin number is in between the max and min GPIO pin values
    if(pin < MIN_GPIO_PIN || pin > MAX_GPIO_PIN)
        return;
    
    // To set as simple output GPIO_FUNCx_OUT_SEL_CFG = 0x100
    //      First 8 bits are GPIO_FUNCx_OUT_SEL
    //volatile unsigned int pinFuncSelReg = GPIO_BASE_ADDRESS + GPIO_FUNCn_OUT_SEL_CFG_REG + 0x4*pin;
    //pinFuncSelReg &= 0xE00;
    // pinFuncSelReg |= 0x100;
    Serial.print(GPIO_FUNC27_OUT_SEL_CFG_REG);
    Serial.print(" ");
    GPIO_FUNC27_OUT_SEL_CFG_REG &= 0xE00;
    GPIO_FUNC27_OUT_SEL_CFG_REG |= 0x100;
    Serial.print(GPIO_FUNC27_OUT_SEL_CFG_REG);
    Serial.print(" ");
    // Set as always enable GPIO_FUNCx_OUT_SEL_CFG
    //      Set the GPIO_FUNCx_OEN_SEL bit 
    //pinFuncSelReg |= 0x400;
    GPIO_FUNC27_OUT_SEL_CFG_REG |= 0x400;
    Serial.print(GPIO_FUNC27_OUT_SEL_CFG_REG);
    // Set the bit the GPIO_ENABLE_DATAx in GPIO_ENABLE(1)_REG
    //volatile unsigned int enableDataReg;
    
    if(pin <= 31){
        //enableDataReg = GPIO_BASE_ADDRESS + GPIO_ENABLE_REG;
        //enableDataReg |= (unsigned int) power(2, pin);
        GPIO_ENABLE_REG |= (unsigned int) power(2,pin);
    } else {
        //enableDataReg = GPIO_BASE_ADDRESS + GPIO_ENABLE1_REG;
        //enableDataReg |= (unsigned int) power(2,pin-32);
    }
    */

   pinMode(pin, OUTPUT);
}


// This function sets a pin as a simple input pin
// Inputs: the pin number to set as an input
// Outputs: None
void setInputPin(int pin){
    pinMode(pin, INPUT);
}


// This function sets an output value for an initialized pin
// Inputs: the pin number, and the desired value
// Outputs: None
void digitalOutput(int pin, int value){
    /*
    // Checking that the pin number is in between the max and min GPIO pin values
    if(pin < MIN_GPIO_PIN || pin > MAX_GPIO_PIN)
        return;
    
    // Holds the output data register location
    //volatile unsigned int outputDataReg;
    
    // For the nth pin, set the nth bit in GPIO_OUT_DATA
    if(pin <= 31){
        //outputDataReg = GPIO_BASE_ADDRESS + GPIO_OUT_REG;
        if(value == 0)
            //outputDataReg &= (unsigned int) (0xFFFFFFFF - power(2,pin));
            GPIO_OUT_REG &= (unsigned int) (0xFFFFFFFF - power(2,pin));
        else
            //outputDataReg |= (unsigned int) power(2,pin);
            GPIO_OUT_REG |= (unsigned int) power(2,pin);
    } else {
        //outputDataReg = GPIO_BASE_ADDRESS + GPIO_OUT1_REG;
        
        
        //if(value == 0)
        //    outputDataReg &= (unsigned int) (0xFF - power(2,pin));
        //else{
        //    outputDataReg |= (unsigned int) power(2,pin-32);
        //}
        
    }
    */
   
    if(value == 0)
        digitalWrite(pin,LOW);
    else
        digitalWrite(pin,HIGH);


}


void setUpPWMChannel(int pin, int channel, int frequency, int resolution){
    // Setting up the pwm channel
    ledcSetup(channel, frequency, resolution);

    // Attaching pin to the pwm channel
    ledcAttachPin(pin, channel);
}


void writePWMChannel(int channel, int dutyCycle){
    ledcWrite(channel, dutyCycle);
}

int power(int base, int exp){
    // only positive exponents
    int value = 1;

    if(exp > 0)
        for(int i = 0; i < exp; i++)
            value *= base;
        
    return value;
}