/*
Title: DataProcess.cpp
Author: Christine Cabero, Ben Pauka, Matthew VonWahlde, Cameron Zheng
Date Created: 2/2/23
Date Modified: 2/2/23
Description: Function definitions for data handling
*/

#include "DataProcess.h"

/*
Function: dataHandling
Input: Array of 5 floats, pointers to left and right motor set
        Left trigger value, right trigger value, left shoulder value, right shoulder value, dpad
Output: None
Description: Processes the input array and calls necessary functions
*/
void dataHandling(float dataArr[], MotorSet* leftSet, MotorSet* rightSet){
    // Note to future self, make this so it remembers past values, and doesn't run through function
    // Ended up being a massive nest of conditionals that wouldn't have improved the speed by much
    // Worth considering for the triggers at least
    
    // Setting values to variables for easier use in functions (and reading clarity)
    float leftTrigger = dataArr[0];
    float rightTrigger = dataArr[1];
    float leftShoulder = dataArr[2];
    float rightShoulder = dataArr[3];
    float dpad = dataArr[4];

    // List of boolean values for whether something is pressed for ease of use and reading
    bool lTriggerPressed = (leftTrigger < TRIGGER_RESTING_THRESHOLD);
    bool rTriggerPressed = (rightTrigger < TRIGGER_RESTING_THRESHOLD);
    bool lShoulderPressed = (leftShoulder == SHOULDER_COMPRESSED);
    bool rShoulderPressed = (rightShoulder == SHOULDER_COMPRESSED);
    bool dpadPressed = (dpad != DPAD_RESTING);

    // Main Process
    // Priority: Shoulders, bumpers, then dpad

    // If nothing is pressed, stop motors and return
    if(lTriggerPressed == false && rTriggerPressed == false && lShoulderPressed == false && rShoulderPressed == false && dpadPressed == false){
        leftSet->stop();
        rightSet->stop();
        return;
    }

    if(lTriggerPressed == true){ // if left trigger is pressed
        // Set left wheels forwards
        leftSet->driveForwards(setTriggerWheelSpeed(leftTrigger));
    }

    if(rTriggerPressed == true){ // if right trigger is pressed
        // Set right wheels forward
        rightSet->driveForwards(setTriggerWheelSpeed(rightTrigger));
    }

    if(lShoulderPressed == true && lTriggerPressed == false){ // if left shoulder is pressed, and left trigger is not
        leftSet->driveBackwards(BACKWARDS_SPEED);
    }

    if(rShoulderPressed == true && rTriggerPressed == false){ // if right shoulder is pressed, and right trigger is not
        rightSet->driveBackwards(BACKWARDS_SPEED);
    }

    if(lTriggerPressed == false && rTriggerPressed == false && lShoulderPressed == false && rShoulderPressed == false && dpadPressed == true)
        if(dpad == DPAD_LEFT){
            leftSet->spinLeft(SPINNING_SPEED);
            rightSet->spinLeft(SPINNING_SPEED);
        } else if (dpad == DPAD_RIGHT){
            leftSet->spinRight(SPINNING_SPEED);
            rightSet->spinRight(SPINNING_SPEED);
        }
}


/*
Function: setTriggerWheelSpeed
Input: float - value of the trigger
Output: float - a value between 0 and 1
Description: Processes the input array and calls necessary functions
*/
float setTriggerWheelSpeed(float triggerVal){
    // if trigger is compressed fully (or meets threshold value), return full speed
    if(triggerVal < TRIGGER_COMPRESSED_THRESHOLD)
        return 1;

    // Return trigger value converted into a float between 0 (stopped) and 1 (full speed)
    return triggerVal * (-1/2) + 1/2;
}