/*
Title: CPPGPIO.h
Author: Christine Cabero, Ben Pauka, Matthew VonWahlde, Cameron Zheng
Date Created: 12/3/22
Date Modified: 12/3/22
Description: Header file for ESP32 GPIO in C++
*/
#include <Arduino.h>

#ifndef CPPGPIO_H
#define CPPGPIO_H

// Min and max GPIO pins for checking valid pin number
#define MAX_GPIO_PIN 39
#define MIN_GPIO_PIN 0

// Base address for all GPIO registers
#define GPIO_BASE_ADDRESS (*((volatile unsigned int *)0x3FF44000))

#define GPIO_FUNC27_OUT_SEL_CFG_REG (*((volatile unsigned int *)0x3FF4459C))
#define GPIO_ENABLE_REG (*((volatile unsigned int *)0x3FF44020))
#define GPIO_OUT_REG (*((volatile unsigned int *)0x3FF44004))

// Relative addresses from GPIO_BASE_ADDRESS
#define GPIO_FUNCn_OUT_SEL_CFG_REG 0x530
//#define GPIO_ENABLE_REG 0x0020
#define GPIO_ENABLE1_REG 0x002C
//#define GPIO_OUT_REG 0x0004
#define GPIO_OUT1_REG 0x0010

void setOutputPin(int);
void setInputPin(int);
void setUpPWMChannel(int, int, int, int);

void digitalOutput(int, int);
void writePWMChannel(int, int);
int power(int, int);

#endif