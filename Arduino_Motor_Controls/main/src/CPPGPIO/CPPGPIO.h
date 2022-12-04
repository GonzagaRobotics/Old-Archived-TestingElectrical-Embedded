/*
Title: CPPGPIO.h
Author: Christine Cabero, Ben Pauka, Matthew VonWahlde, Cameron Zheng
Date Created: 12/3/22
Date Modified: 12/3/22
Description: Header file for ESP32 GPIO in C++
*/

#ifndef CPPGPIO_H
#define CPPGPIO_H

#define somePointer (*((volatile uint8_t *) 0x00))


void setPinMode(int, int);
void setUpPWMChannel(int, int, int);
void attachPWMChannel(int, int);

void digitalOutput(int, int);
void writePWMChannel(int, int);

#endif