/*
Title: CPPGPIO.cpp
Author: Christine Cabero, Ben Pauka, Matthew VonWahlde, Cameron Zheng
Date Created: 12/3/22
Date Modified: 12/3/22
Description: Function file for ESP32 GPIO in C++
*/

#include "CPPGPIO.h"


void setOutputPin(int pin, int direction){
    if(pin < MIN_GPIO_PIN || pin > MAX_GPIO_PIN)
        return;

    // To set as simple output GPIO_FUNCx_OUT_SEL_CFG = 0x100
    //      First 8 bits are GPIO_FUNCx_OUT_SEL
    volatile unsigned int* pinFuncSelReg = REGISTER_ADDRESS + 0x530 + (4*pin);
    *pinFuncSelReg |= 0x100;

    // Set as always enable GPIO_FUNCx_OUT_SEL_CFG
    //      Set the CPIO_FUNCx_OEN_SEL bit 
    *pinFuncSelReg |= 0x400;

    // Set the bit the GPIO_ENABLE_DATAx in GPIO_ENABLE(0 or 1)_REG
    volatile unsigned int* enableDataAddress;
    
    if(pin <= 31){
        enableDataAddress = REGISTER_ADDRESS + 0x20 + power(2,pin);
        *enableDataAddress |= 0x1;
    } else {
        enableDataAddress = REGISTER_ADDRESS + 0x2C + power(2,pin-32);
        *enableDataAddress |= 0x1;
    }
}


void digitalOutput(int pin, int value){
    // For the nth pin, set the nth bit in GPIO_OUT_DATA
    if(pin < MIN_GPIO_PIN || pin > MAX_GPIO_PIN)
        return;

    volatile unsigned int* outputDataAddress;
    
    if(pin <= 31){
        outputDataAddress = REGISTER_ADDRESS + 0x04;
        if(value == 0)
            *outputDataAddress &= (power(2,32) - 1) - power(2,pin);
        else{
            outputDataAddress += power(2,pin);
            *outputDataAddress |= 0x1;
        }
        
    } else {
        outputDataAddress = REGISTER_ADDRESS + 0x10;
        if(value == 0)
            *outputDataAddress &= (power(2,8) - 1) - power(2,pin-32);
        else{
            outputDataAddress += power(2,pin-32);
            *outputDataAddress |= 0x1;
        }
    }
}


void setUpPWMChannel(int channel, int frequency, int resolution){

}


void attachPWMChannel(int pin, int channel){

}


void writePWMChannel(int pin, int dutyCycle){

}

int power(int base, int exp){
    // only positive exponents
    int value = 1;

    if(exp > 0)
        for(int i = 0; i < exp; i++)
            value *= base;
        
    return value;
}