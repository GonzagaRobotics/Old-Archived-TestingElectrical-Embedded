/*
Title: DataProcess.h
Author: Christine Cabero, Ben Pauka, Matthew VonWahlde, Cameron Zheng
Date Created: 2/2/23
Date Modified: 2/2/23
Description: Header file for DataProcess.cpp
*/

#include "../MotorSet/MotorSet.h"

const float TRIGGER_RESTING_THRESHOLD = 0.95;
const float TRIGGER_COMPRESSED_THRESHOLD = -0.95;
const float TRIGGER_CHANGE_THRESHOLD = 0.05;
const float SHOULDER_RESTING = 0;
const float SHOULDER_COMPRESSED = 1;
const float DPAD_RESTING = 0;
const float DPAD_LEFT = 1;
const float DPAD_RIGHT = -1;

const float BACKWARDS_SPEED = 0.5;
const float SPINNING_SPEED = 0.5;


void dataHandling(float[], MotorSet*, MotorSet*);

float setTriggerWheelSpeed(float);