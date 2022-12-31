/*
Title: CPPGPIO.h
Author: Christine Cabero, Ben Pauka, Matthew VonWahlde, Cameron Zheng
Date Created: 12/3/22
Date Modified: 12/3/22
Description: Header file for ESP32 GPIO in C++
*/

#ifndef CPPGPIO_H
#define CPPGPIO_H

#define MAX_GPIO_PIN 39
#define MIN_GPIO_PIN 0

#define somePointer (*((volatile unsigned int *) 0x00))

#define REGISTER_ADDRESS ((volatile unsigned int *)0x3FF44000)

void setPinMode(int, int);
void setUpPWMChannel(int, int, int);
void attachPWMChannel(int, int);

void digitalOutput(int, int);
void writePWMChannel(int, int);
int power(int, int);

#endif