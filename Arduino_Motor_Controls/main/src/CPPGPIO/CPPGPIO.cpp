/*
Title: CPPGPIO.cpp
Author: Christine Cabero, Ben Pauka, Matthew VonWahlde, Cameron Zheng
Date Created: 12/3/22
Date Modified: 12/3/22
Description: Function file for ESP32 GPIO in C++
*/

#include "CPPGPIO.h"

// This function sets a pin as a simple output pin
// Inputs: the pin number to set as an output
// Outputs: None
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


// This function sets an output value for an initialized pin
// Inputs: the pin number, and the desired value
// Outputs: None
void digitalOutput(int pin, int value){
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
        
        /*
        if(value == 0)
            outputDataReg &= (unsigned int) (0xFF - power(2,pin));
        else{
            outputDataReg |= (unsigned int) power(2,pin-32);
        }
        */
    }
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