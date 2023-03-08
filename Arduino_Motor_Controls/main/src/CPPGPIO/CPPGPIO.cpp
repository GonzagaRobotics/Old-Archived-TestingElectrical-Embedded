/*
Title: CPPGPIO.cpp
Author: Christine Cabero, Ben Pauka, Matthew VonWahlde, Cameron Zheng
Date Created: 12/3/22
Date Modified: 2/2/23
Description: Function file for ESP32 GPIO in C++
*/

// Check ctre/Phoenix.h

#include "CPPGPIO.h"


// This function adds motors to the left microcontroller
// Inputs: None
// Outputs: pointer to the left MotorSet
MotorSet* addPinsToLeftMotorSet(){
    // All directions are from the perspective of the rover's POV
    // Left microcontroller (motors 1 - 3)
    // Pins for the first motor (front left)
    int motor1Pin1 = 1;
    int motor1PWMChannel1 = 1;
    char motor1Side = 'l';

    // Pins for the second motor (middle left)
    int motor2Pin1 = -1;
    int motor2PWMChannel1 = 2;
    char motor2Side = 'l';

    // Pins for the third motor (back left)
    int motor3Pin1 = -1;
    int motor3PWMChannel1 = 4;
    char motor3Side = 'l';

    // Creating pointer to new MotorSet
    MotorSet* leftMotorSet = new MotorSet;

    // Adding motors to left MotorSet
    leftMotorSet->addMotor(motor1Pin1, motor1PWMChannel1, motor1Side);
    //leftMotorSet->addMotor(motor2Pin1, motor2PWMChannel1, motor2Side);
    //leftMotorSet->addMotor(motor3Pin1, motor3PWMChannel1, motor3Side);

    return leftMotorSet;
}


// This function adds motors to the right microcontroller
// Inputs: None
// Outputs: pointer to the right MotorSet
MotorSet* addPinsToRightMotorSet(){
    // Right microcontroller (motors 4 - 6)
    // Pins for the fourth motor (front right)
    int motor4Pin1 = 0;
    int motor4PWMChannel1 = 0;
    char motor4Side = 'r';

    // Pins for the fifth motor (middle right)
    int motor5Pin1 = -1;
    int motor5PWMChannel1 = 2;
    char motor5Side = 'r';

    // Pins for the sixth motor (back right)
    int motor6Pin1 = -1;
    int motor6PWMChannel1 = 4;
    char motor6Side = 'r';

    // Creating pointer to new MotorSet
    MotorSet* rightMotorSet = new MotorSet;

    // Adding motors to right MotorSet
    rightMotorSet->addMotor(motor4Pin1, motor4PWMChannel1, motor4Side);
    //rightMotorSet->addMotor(motor5Pin1, motor5PWMChannel1, motor5Side);
    //rightMotorSet->addMotor(motor6Pin1, motor6PWMChannel1, motor6Side);

    return rightMotorSet;
}


// This function sets a pin as a simple output pin
// Inputs: the pin number to set as an output
// Outputs: None
void setOutputPin(int pin){
    /*
    Note: This function exists because originally we were going to alter register values
    to perform this function. However, it was found out by another group that Arduino commands
    could be used. We are keeping this here in case we need to go back to using registers.
    The original work in progress code is stored below in archived functions.
    */
    pinMode(pin, OUTPUT);
}


// This function sets up a PWM channel and attachs it to a pin
// Inputs: the pin number, PWM channel, PWM frequency, PWM resolution
// Outputs: None
void setUpPWMChannel(int pin, int channel, int frequency, int resolution){
    // Setting up the pwm channel
    ledcSetup(channel, frequency, resolution);

    // Attaching pin to the pwm channel
    ledcAttachPin(pin, channel);
}


// This function sets the desired duty cycle for the PWM channel
// Inputs: PWM channel, PWM duty cycle (0(0 duty cycle) to 255(1 duty cycle))
// Outputs: None
void writePWMChannel(int channel, int dutyCycle){
    ledcWrite(channel, dutyCycle);
}


///////////////////////////////////////////////////////////////////////////
// Archived Functions
///////////////////////////////////////////////////////////////////////////
// This function sets a pin as a simple output pin
// Inputs: the pin number to set as an output
// Outputs: None
/*
void setOutputPin(int pin){
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
}
*/

/*
int power(int base, int exp){
    // only positive exponents
    int value = 1;

    if(exp > 0)
        for(int i = 0; i < exp; i++)
            value *= base;
        
    return value;
}
*/
