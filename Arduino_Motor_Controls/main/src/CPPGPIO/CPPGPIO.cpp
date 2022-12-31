/*
Title: CPPGPIO.cpp
Author: Christine Cabero, Ben Pauka, Matthew VonWahlde, Cameron Zheng
Date Created: 12/3/22
Date Modified: 12/3/22
Description: Function file for ESP32 GPIO in C++
*/
// 12/30/2022 test
#include "CPPGPIO.h"


void setPinMode(int pin, int direction){
    // To set as simple output GPIO_FUNCx_OUT_SEL_CFG = 0x100
    //      First 8 bits are GPIO_FUNCx_OUT_SEL

    // Set as always enable GPIO_FUNCx_OUT_SEL_CFG
    //      Set the CPIO_FUNCx_OEN_SEL bit 
    
    // Set the GPIO_ENABLE_DATAx in GPIO_ENABLE(0 or 1)_REG
}


void setUpPWMChannel(int channel, int frequency, int resolution){

}


void attachPWMChannel(int pin, int channel){

}


void digitalOutput(int pin, int value){
    // For the nth pin, set the nth bit in GPIO_OUT_DATA
}


void writePWMChannel(int pin, int dutyCycle){

}