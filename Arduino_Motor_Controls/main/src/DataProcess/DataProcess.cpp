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

    //Left and right speed buffer
    float leftSpeedCurrent;
    static float leftSpeedPrevious = 0;
    float rightSpeedCurrent;
    static float rightSpeedPrevious = 0;


    // Main Process
    // Priority: Shoulders, bumpers, then dpad
    
    // If the left trigger, left shoulder, dpad are not pressed
    leftSpeedCurrent = 0;
    rightSpeedCurrent = 0;

     // If only the dpad is pressed
    if(dpadPressed == true && lTriggerPressed == false && rTriggerPressed == false && lShoulderPressed == false && rShoulderPressed == false) {
        if(dpad == DPAD_LEFT){ // If left dpad is pressed
            // Spin left
            //leftSet->spinLeft(SPINNING_SPEED);
            //rightSet->spinLeft(SPINNING_SPEED);
            leftSpeedCurrent = -SPINNING_SPEED;
            rightSpeedCurrent = SPINNING_SPEED;

        } else if (dpad == DPAD_RIGHT){ // If right dpad is pressed
            // Spin right
            leftSpeedCurrent = SPINNING_SPEED;
            rightSpeedCurrent = -SPINNING_SPEED;
        }
    }

    // If left shoulder is pressed, and left trigger is not
    if(lShoulderPressed == true){
        // Set left wheels backwards
        //leftSet->driveBackwards(BACKWARDS_SPEED);
        leftSpeedCurrent = -BACKWARDS_SPEED;
    }

    // If right shoulder is pressed, and right trigger is not
    if(rShoulderPressed == true){ 
        // Set right wheels backwards
        //rightSet->driveBackwards(BACKWARDS_SPEED);
        rightSpeedCurrent = -BACKWARDS_SPEED;
    }

    // If left trigger is pressed
    if(lTriggerPressed == true){ 
        // Set left wheels forwards
        //leftSet->driveForwards(setTriggerWheelSpeed(leftTrigger));
        leftSpeedCurrent = setTriggerWheelSpeed(leftTrigger);
    }

    // If right trigger is pressed
    if(rTriggerPressed == true){ 
        // Set right wheels forward
        //rightSet->driveForwards(setTriggerWheelSpeed(rightTrigger));
        rightSpeedCurrent = setTriggerWheelSpeed(rightTrigger);
    }

    /* If leftSpeedCurrent is sufficiently different than leftSpeedPrevious,
    then execute the motor command, either stop if 0, drive forward if positive,
    or drive backwards if negative*/ 
    //If leftSpeedCurrent is different than leftSpeedPrevious, or leftSpeed is stopped and didnt already stop, then write to motor
    if (absValue(leftSpeedCurrent - leftSpeedPrevious) > CHANGE_THRESHOLD || (leftSpeedCurrent == 0 && leftSpeedPrevious != 0)) {
        if (leftSpeedCurrent == 0) { //If 0, then stop
            leftSet->stop();
        } else if (leftSpeedCurrent > 0) {
            leftSet->driveForwards(leftSpeedCurrent); //If positive, then go forward
        } else {
            leftSet->driveBackwards(-leftSpeedCurrent); //If negative, then go backwards
        }
        leftSpeedPrevious = leftSpeedCurrent; //Remember current speed for next loop
    }
    //If rightSpeedCurrent is different than rightSpeedPrevious, or rightSpeed is stopped and didnt already stop, then write to motor
    if (absValue(rightSpeedCurrent - rightSpeedPrevious) > CHANGE_THRESHOLD || (rightSpeedCurrent == 0 && rightSpeedPrevious != 0)) {
        if (rightSpeedCurrent == 0) { //If 0, then stop
            rightSet->stop();
        } else if (rightSpeedCurrent > 0) {
            rightSet->driveForwards(rightSpeedCurrent); //If positive, then go forward
        } else {
            rightSet->driveBackwards(-rightSpeedCurrent); //If negative, then go backwards
        }
        rightSpeedPrevious = rightSpeedCurrent; //Remember current speed for next loop
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
    return triggerVal * -0.5 + 0.5;
}

/*
Function: absValue
Input: float - value of the number
Output: float - the absolute value of the number
Description: Does the absolute value function on the number
*/
float absValue(float number) {
    return number >= 0 ? number : -number;
}